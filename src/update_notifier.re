let check: unit => unit = [%bs.raw
  {|
  function check() {
    const updateNotifier = require('update-notifier');
    const pkg = require('../package.json');

    const notifier = updateNotifier({
      pkg,
	    updateCheckInterval: 1000 * 60 * 60 * 12
    });
    notifier.notify()

    if (notifier.update) {
	    console.log(`Updated version available: ${notifier.update.latest}`);
    }
  }
|}
];
