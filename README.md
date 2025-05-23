# Cap table contract

An attempt to fix [812](https://github.com/hypha-dao/hypha-web/issues/812)
issue from Hypha-web.

To completely solve the issue, it would be nice to get more discreet
explanation of the task. For example, issues for Ethereum smart-contracts (e.g.
issues [743](https://github.com/hypha-dao/hypha-web/issues/743) or
[742](https://github.com/hypha-dao/hypha-web/issues/742)) have great
description, so it will be nice to add similar explanation for this issue.

## Build

Generate build system:

```sh
cmake . -B ./build
```

Compile the contract:

```sh
cmake --build ./build
```

Built project (wasm and abi files) will be held in `./build/cap_table`.

## Contribution

Additions to CMake should be done to the CMakeLists.txt in the `./src`
directory and **not in the top level CMakeLists.txt**.
