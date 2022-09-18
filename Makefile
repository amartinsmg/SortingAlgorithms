test: dir
	g++ -o build/test src/test/main.cpp

dir:
	[ -d build ] || mkdir build
