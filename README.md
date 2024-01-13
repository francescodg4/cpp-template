# Template for Cpp Projects

```bash
cmake -B /tmp/cpp-template.build -DCMAKE_BUILD_TYPE=Release
cmake --build /tmp/cpp-template.build/ -j
```

--parallel [<jobs>], -j [<jobs>]

If <jobs> is omitted the native build tool's default number is used (CMAKE_BUILD_PARALLEL_LEVEL).
