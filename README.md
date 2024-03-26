# CPM
Created by [Vicente Viera](https://github.com/VicenteVieraG)
## About the CPM
This is a package manager inspired by NPM. The goal of this project is to make working with C/C++ libraries as easy as it is with NPM.

The objective is to create an abstraction layer over CMake, so no previous knowledge about CMake is needed to build and run proffessional C/C++ projects. It should be as easy as to create a project in C/C++ with a command and get right into the code without the need of extra configuration. If any library is required, it should follow the same principle of simplicity and cero CMake previous knoledge.

This is a C/C++ Project for C/C++ community. The goal is to make the language easier and more accesible for begginers and to make the project managing easier for experts.

## Features

- To init and configure a project structure ready to work.
  - It should receive a flag --init or -i. The --init flag can take the following arguments:
    - Template
        - Creates a project with a C/C++ main file and all the configuration ready to start coding.
    - Empty
        - Creates only the folder structure with just the munimun CMake.