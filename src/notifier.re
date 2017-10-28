type options = {. "title": string, "message": string, "timeout": int};

[@bs.module "node-notifier"] external notify : options => unit = "notify";
