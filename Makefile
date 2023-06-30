# Makefile for building the "test" target and creating the "build" directory.

#Targets
# `test`: compiles the main.cpp file in the src/test directory.
# `dir`: creates the "build" directory if it doesn't already exist.

test: dir
	g++ -o build/test -I src src/test/main.cpp

dir:
	[ -d build ] || mkdir build
