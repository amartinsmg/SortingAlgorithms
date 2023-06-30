# Makefile for building the "test" target and creating the "debug" directory.

#Targets
# `test`: compiles the main.cpp file in the src/test directory.
# `dir`: creates the "debug" directory if it doesn't already exist.

test: dir
	g++ -o debug/test -I src src/test/main.cpp

dir:
	[ -d debug ] || mkdir debug
