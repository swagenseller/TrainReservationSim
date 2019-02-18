CXX = g++
CXXFLAGS = -Wall -g

dbHelper.o: dbHelper.cpp
	$(CXX) $(CXXFLAGS) -c dbHelper.h dbHelper.cpp

main: main.o
	$(CXX) $(CXXFLAGS) -o main main.cpp

cd_line.o: cd_line.cpp
	$(CXX) $(CXXFLAGS) -c cd_line.cpp
