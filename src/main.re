let options = Args.parse Node_process.argv;

let stringified_options = options.standingDesk == true ? "standing-desk" : "";

let getSentence ticks =>
  switch ticks {
  | t when t mod 15 === 0 => Some {js|Drink some water 💧|js}
  | t when t mod 61 === 0 => Some {js|Go for a walk 🚶|js}
  | t when t mod 99 === 0 => options.standingDesk == true ? Some {js|Stand for a bit|js} : None
  | _ => None
  };

let counter = ref 0;

Js.Global.setInterval
  (
    fun () => {
      counter := !counter + 1;
      switch (getSentence !counter) {
      | Some message =>
        Js.log (string_of_int !counter ^ ": " ^ message);
        Notifier.notify {js|😎|js} message
      | None => ()
      }
    }
  )
  options.tickLength;

Js.log {js|Started your personal caretaker ✌️|js};

if (stringified_options !== "") {
  Js.log ("  with options: " ^ stringified_options)
};
