import resolve from "rollup-plugin-node-resolve";
import commonjs from "rollup-plugin-commonjs";
import json from 'rollup-plugin-json';

export default {
  input: "src/main.js",
  output: {
    file :"bundle.js",
    format: "cjs",
  },
  plugins: [
    commonjs(),
    resolve({
      modules: true,
      preferBuiltins: false,
    }),
    json()
  ],
  external: [
    "mri",
    "node-notifier",
    "update-notifier",

    "child_process",
    "crypto",
    "events",
    "fs",
    "net",
    "os",
    "path",
    "url",
    "util",
  ]
};
