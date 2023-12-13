
# Password-gen

## About the tool

A CLI daily-usable password generator, implemented in **C++**. It generates random passwords based on user configurations, such as length, character sets, and inclusion of uppercase or symbols.

## Features

- Extracts random seeds from [/dev/urandom,](https://en.wikipedia.org/wiki//dev/random) ensuring truly random data.
- Calculates an estimated time for password cracking using Brute Force/Dictionary attack methods.

## Installing Build Dependencies

This program uses cmake for building. CMake can be installed via package managers like apt or dnf:

- For Ubuntu/Debian
  ```bash
  sudo apt-get install cmake
-   For Fedora/CentOS
    
    bashCopy code
    
    ```bash
    sudo dnf install cmake 
To learn more about cmake, refer to [CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html).

## Build instructions

This requires a C++14 compatible compiler.

-   Instruction :
    
    ```bash
    git clone https://github.com/Cerealmaster0621/Password_generator` 
    cd Password_generator
    cmake -B build/
    cd build
    make
    ```
## Run Using Chmod

-   Make the script executable:  
    ```bash
    chmod +x run.sh
    ```
    
-   Run the program:
    ```bash
    ./run.sh
    ``` 
   
The script will compile the program if it's not already compiled and run it.

## Usage

This supports various flags for customizing the generated password:

-   `--h` or `--help`: Display help information.
-   `--l` or `--length <length>`: Specify password length, default is 8.
-   `--u` or `--uppercase`: Include at least one uppercase letter, default is false.
-   `--s` or `--symbol`: Include at least one symbol, default is false.
-   `--i` or `--include <string>`: Include the specified string in the password.

Example usage:
``` bash
./run.sh --l 12 --u --s --i aaa
```
# License 
MIT License Copyright (c) 2023 YoungJune Kang