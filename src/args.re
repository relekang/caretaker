type args = {
  standingDesk: bool,
  tickLength: int,
  help: bool
};

let defaults = {standingDesk: false, tickLength: 1000 * 60, help: false};

let folder lastValue argument =>
  switch argument {
  | "--standing-desk" => {...lastValue, standingDesk: true}
  | "--fast" => {...lastValue, tickLength: 100}
  | "--help" => {...lastValue, help: true}
  | _ => lastValue
  };

let parse = Array.fold_left folder defaults;
