let notify: string => string => unit = [%bs.raw
  {|
  function notify(title, message) {
    const notifier = require('node-notifier');
    notifier.notify({ title, message });
  }
|}
];
