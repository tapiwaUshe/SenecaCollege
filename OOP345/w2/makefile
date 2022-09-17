default: compile
compile:
	g++ -o bin/w2 src/w2.cpp src/Station.cpp src/Stations.cpp
test: clean compile
	cp db/Stations.dat.dist db/Stations.dat
	bin/w2 db/Stations.dat
	cat db/Stations.dat
clean:
	rm -f bin/w2
