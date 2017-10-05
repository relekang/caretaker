import resolve from "rollup-plugin-node-resolve";
import commonjs from "rollup-plugin-commonjs";
import path from "path";

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
  ],
  external: [
    "mri",
    "node-notifier",

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
