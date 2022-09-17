default: test
clean:
	rm -f w10
build: clean
	g++ -std=c++11 -o w10 w10.cpp SecureData.cpp
test: build
	./w10 w10_text.dat encoded.dat %