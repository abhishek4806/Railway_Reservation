// Name : Abhishek Kumar
// Roll No. : 19ME31035

#include<iostream>
#include "Station.h"
#include "Railways.h"
#include "Exception.h"

using namespace std;

Station::Station(string name) : name_(name) {}
Station::~Station() {}

string Station::GetName() const {
    return this->name_;              
}

Station::Station(const Station& other) {
    name_ = other.name_;
}

Station& Station::operator=(const Station& other) {
    name_ = other.name_;
    return *this;
}

bool Station::operator==(const Station &other) {
    return this->name_ == other.name_;
}

int Station::GetDistance(const Station& other) {
    int distance = Railways::IndianRailways().GetDistance(*this , other);
    return distance;
}

ostream& operator<<(ostream& os , const Station& other) {
    os << "Station : " << other.name_ << "\n";
    return os;
}

Station Station::Construct(string name){
    int flag = 0;
    if(name == "")
        flag = 1;

    try{
        if(flag){
            BadStation ex;
            throw ex;
        }
        else{
            Station s(name);
            return s;
        }
    }
    catch(BadStation &ex){
        throw;
    }
}

void Station::UnitTestStation() {
    try{
        Station s1 = Station :: Construct("Mumbai");
        Station s2 = Station :: Construct("Delhi");
        Station s3 = Station :: Construct("Mumbai");
        if(s1.name_ != "Mumbai" || s2.name_ != "Delhi") {
            cout << "STATION CONSTRUCTION : FAILED" << "\n";      
        }
        else{
            cout << "STATION CONSTRUCTION : PASSED" << "\n";
        }
        if(s1 == s3) {
            cout << "OPERATOR OVERLOADING ( == ) : PASSED" << "\n";   
        }
        else{
            cout << "OPERATOR OVERLOADING ( == ) : FAILED" << "\n";    
        }
        
        if(s1.GetName() != "Mumbai") {
            cout << "STATION GETNAME FUNCTION : FAILED" << "\n";
        }
        else{
            cout<<"STATION GETNAME FUNCTION : PASSED"<<"\n";
        }
        if(s1.GetDistance(s2) == 1447) {
            cout << "STATION GETDISTANCE FUNCTION : PASSED" << "\n";
        }
        else{
            cout << "STATION GETDISTANCE FUNCTION : FAILED" << "\n";
        }
    }
    catch(BadStation &ex){
        cout<<"STATION CONSTRUCTION FAILED"<<"\n";
    }

    try{
        Station s1 = Station :: Construct("");
        cout<<"INCORRECT STATION CONSTRUCTION (NEGATIVE TEST) : PASSED"<<"\n";
    }
    catch(BadStation &ex){
        cout<<"INCORRECT STATION CONSTRUCTION (NEGATIVE TEST) : FAILED"<<"\n";
    }
}