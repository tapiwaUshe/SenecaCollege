default: test
clean:
	rm -f w5
build: clean
	g++ -o w5 -std=c++0x w5.cpp Notifications.cpp Message.cpp
test: build
	./w5 w5_test.dat
