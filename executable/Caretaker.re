open Cmdliner;

let version = "1.0.0-rc.0";

let caretaker = (fast, standing_desk) => {
  let tick_length = fast ? 0.1 : 60. *. 60.;

  let get_sentence = ticks =>
    switch (ticks) {
    | t when t mod 15 === 0 => Some("Drink some water 💧")
    | t when t mod 61 === 0 => Some("Go for a walk 🚶")
    | t when t mod 99 === 0 =>
      standing_desk == true ? Some("Stand for a bit") : None
    | _ => None
    };

  let rec play = current_tick => {
    Unix.sleepf(tick_length);
    switch (get_sentence(current_tick)) {
    | Some(message) => Console.log(message)
    | None => ()
    };
    play(current_tick + 1);
  };
  play(1);
};

let _ =
  {
    let fast = Arg.(value & flag & info(["f", "fast"], ~doc=""));
    let standing_desk =
      Arg.(value & flag & info(["s", "standing-desk"], ~doc=""));

    Term.(
      const(caretaker) $ fast $ standing_desk,
      info("caretaker", ~version),
    );
  }
  |> (t => Term.eval_choice(t, []))
  |> Term.exit;
