# GDNATIVE CLASS FACTORY

This repository contains the code of a class factory for gdnative.

Explained briefly, this is a powerful design pattern that allows classes to self-register themselves in a more modular manner and to make them auto-generate gdns files to make the workflow of nativescript way more convenient to make full games in C++ way faster.

## Instructions

- Clone the repository by using :

`git clone --recursive https://github.com/SeleDreams/gdnative_class_factory.git`

- Create an api.json in the main directory by starting godot with these arguments : 

`godot --gdnative-generate-json-api api.json`

- Create a build directory and cd to it.

- Use cmake by specifying the install directory to the godot project.

` cmake -DCMAKE_INSTALL_PREFIX="../gdnative_class_factory/bin" ..`

- Build the generated makefile or project file to end up with a shared library (MAKE SURE TO INSTALL IF USING MAKE AND IF USING SOMETHING ELSE, ADD THE SHARED LIBRARY TO THE PROJECT).

- Add the shared library to the gdnative_class_factory/bin/gdnative_class_factory.gdnlib under the correct platform and architecture.

If you correctly followed these instructions, types should normally correctly register themselves and create gdns files.

when it comes to self register a class all you have to do is to make it inherit from ClassFactory and to call REGISTER_CLASS in the cpp file.