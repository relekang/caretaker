let tickLength = 1000;

let options = Args.parse ();

let getSentence ticks =>
  switch ticks {
  | t when t mod 15 === 0 => Some {js|Drink some water 💧|js}
  | t when t mod 60 === 0 => Some {js|Go for a walk 🚶|js}
  | t when t mod 100 === 0 => options.standingDesk ? Some {js|Stand for a bit|js} : None
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
  tickLength;
