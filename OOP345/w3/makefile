default: test
clean:
	rm -f w3
build: clean
	g++ -o w3 -std=c++0x w3.cpp Text.cpp
test: build
	./w3 gutenberg_shakespeare
