type args = {standingDesk: bool};

let parse: unit => args = [%bs.raw
  {|
  function parse() {
    const args = require('mri')(process.argv)
    return {
      standingDesk: !!args['standing-desk']
    }
  }
|}
];
