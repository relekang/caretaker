Update_notifier.check ();

let options = Args.parse Node_process.argv;

let stringified_options = options.standingDesk == true ? "standing-desk" : "";

if (options.help == true) {
  Js.log {|Your personal caretaker.

  --standing-desk  Will add the message stand for a bit every once in a while.
  --fast           Runs with 100ms instead of minutes, help for debugging.
  --help           Show this.
  |};
  Node_process.exit 0
};

let getSentence ticks =>
  switch ticks {
  | t when t mod 15 === 0 => Some {js|Drink some water 💧|js}
  | t when t mod 61 === 0 => Some {js|Go for a walk 🚶|js}
  | t when t mod 99 === 0 => options.standingDesk == true ? Some {js|Stand for a bit|js} : None
  | _ => None
  };

let counter = ref 0;

let notify sentence =>
  switch sentence {
  | Some message =>
    Js.log (string_of_int !counter ^ ": " ^ message);
    Notifier.notify {"title": {js|😎|js}, "message": message, "timeout": 20};
    ()
  | None => ()
  };

Js.Global.setInterval
  (
    fun () => {
      counter := !counter + 1;
      notify (getSentence !counter)
    }
  )
  options.tickLength;

Js.log {js|Started your personal caretaker ✌️|js};

if (stringified_options !== "") {
  Js.log ("  with options: " ^ stringified_options)
};
