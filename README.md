# SmartWebAsm

A simple web app featuring a C++ application embedded and running with WebAssembly.

This application needs /emscripten/ to compile C++ into WebAssembly.

- WebAssembly -- [https://webassembly.org/](https://webassembly.org/)
- Emscripten -- [https://emscripten.org/](https://emscripten.org/)

### Compile C++ to WASM

Open terminal and run:

    em++ -o hello.html src/cpp/main.cpp -O3 -s WASM=1 --shell-file html_template/shell_minimal.html

### Run application

Install this folder in any HTTP Server (example: [Web Server for Chrome](https://chrome.google.com/webstore/detail/web-server-for-chrome))
and navigate to hello.html








