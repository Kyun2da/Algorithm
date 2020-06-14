module.exports = {
  env: {
    browser: true,
    es2020: true,
  },
  plugins: ["prettier"],
  extends: ["airbnb", "prettier"],
  parserOptions: {
    ecmaVersion: 11,
    sourceType: "module",
  },
  rules: {
    "prettier/prettier": "error",
    "no-console": 0,
  },
};
