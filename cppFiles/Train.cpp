// Train.cpp
#include "Train.h"

// basic getter functions
int Train::getTrainNo() {
    return trainNo;
}
string Train::getArriving(){
    return arriving;
}
string Train::getDeparting(){
    return departing;
}
int Train::getDepatureTime(){
    return departTime;
}
int Train::getArrivalTime(){
    return arrivalTime;
}

// basic setter functions
void Train::setTrainNo(int input) {
    trainNo = input;
}
void Train::setArriving(string input){
    arriving = input;
}
void Train::setDeparting(string input){
    departing = input;
}
void Train::setDepatureTime(int input){
    departTime = input;
}
void Train::setArrivalTime(int input){
    arrivalTime = input;
}
