#ifndef TRAIN
#define TRAIN
#include <iostream>
using namespace std;

class Train {
private:
    char firstClassSeats[20];
    char secondClassSeats[80];
    int trainNo;
    string departing;
    string arriving;
    int departTime;
    int arrivalTime;

public:
    Train() {
        firstClassSeats[20];
        secondClassSeats[80];
        trainNo = 0;
        departing = "";
        arriving = "";
        departTime = 0;
        arrivalTime = 0;        
    };
    int getTrainNo();
    string getDeparting();
    string getArriving();
    int getDepatureTime();
    int getArrivalTime();

};
#endif
