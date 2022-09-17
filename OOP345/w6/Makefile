default: test
clean:
	rm -f w6
build: clean
	# g++ -std=c++11 -o w6 w6.cpp
	g++ -std=c++11 -o w6 w6.cpp Grades.cpp
test: build
	./w6 w6.dat