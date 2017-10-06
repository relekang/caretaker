type options = Js.t {. title : string, message : string, timeout : int};

external notify : options => unit = "notify" [@@bs.module "node-notifier"];
