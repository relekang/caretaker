type args = {
  standingDesk: bool,
  help: bool
};

let defaults = {standingDesk: false, help: false};

let folder lastValue argument =>
  switch argument {
  | "--standing-desk" => {...lastValue, standingDesk: true}
  | "--help" => {...lastValue, help: true}
  | _ => lastValue
  };

let parse = Array.fold_left folder defaults;
