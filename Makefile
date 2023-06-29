test: dir
	g++ -o build/test -I src src/test/main.cpp

dir:
	[ -d build ] || mkdir build
