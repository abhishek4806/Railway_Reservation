// Name : Abhishek Kumar
// Roll No. : 19ME31035

#include<iostream>
#include "Date.h"
#include "Station.h"
#include "Passenger.h"
#include "Booking.h"
#include "Railways.h"
#include "BookingClasses.h"
#include "SecondSitting.h"
#include "FirstClass.h"
#include "ACChairCar.h"
#include "FirstClass.h"
#include "Sleeper.h"
#include "AC3Tier.h"
#include "AC2Tier.h"
#include "ACFirstClass.h"
#include "Gender.h"
#include "BookingCategory.h"
#include "Tatkal.h"
#include "PremiumTatkal.h"
#include "General.h"
#include "SeniorCitizen.h"
#include "Ladies.h"
#include "Blind.h"
#include "TB.h"
#include "Cancer.h"
#include "Handicapped.h"
#include "Exception.h"
#include "ExecutiveChairCar.h"
using namespace std;

// Test application for booking
void BookingApplication() {
    try{
        Booking *b1 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(17 , 3 , 2021) , Date::Construct(12,2,2021) , AC3Tier::Type() , General::Type() , Passenger::Construct("Abhishek" , Male::Type() , "123456789111" , Date::Construct(17,12,2001)));
        Booking *b2 = Booking::ReserveBooking(Station::Construct("Mumbai") , Station::Construct("Delhi")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , AC3Tier::Type() , General::Type() , Passenger::Construct("Abhishek" , Male::Type() , "123456789111" , Date::Construct(17,12,2001)));
        // multiple booking -> same passenger
        cout<<"MUTIPLE BOOKING SAME PASSENGER : PASSED"<<"\n";
    }
    catch(...){
        cout<<"MUTIPLE BOOKING SAME PASSENGER : FAILED"<<"\n";
    }
    
    try{
        Booking *b3 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(17 , 3 , 2021) , Date::Construct(12,2,2021) , AC3Tier::Type() , SeniorCitizen::Type() , Passenger::Construct("Abhishek" , Male::Type() , "123456789111" , Date::Construct(17,12,1901)));
        Booking *b4 = Booking::ReserveBooking(Station::Construct("Kolkata") , Station::Construct("Mumbai")  , Date::Construct(17 , 3 , 2021) , Date::Construct(12,2,2021) , ACFirstClass::Type() , SeniorCitizen::Type() , Passenger::Construct("Abhishek" , Male::Type() , "123456789111" , Date::Construct(17,12,1901)));
        // multiple booking -> same date of booking -> different passenger
        cout<<"MULTIPLE BOOKING SAME DOB(BOOKING) DIFFERENT PASSENGER : PASSED"<<"\n"; 
    }
    catch(...){
        cout<<"MULTIPLE BOOKING SAME DOB(BOOKING) DIFFERENT PASSENGER : FAILED"<<"\n";  
    }
    
    try{
        Booking *b5 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(17 , 3 , 2021) , Date::Construct(12,2,2021) , AC3Tier::Type() , Blind::Type() , Passenger::Construct("Abhishek" , Male::Type() , "123456789111" , Date::Construct(17,12,1901)));
        Booking *b6 = Booking::ReserveBooking(Station::Construct("Chennai") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(12,2,2021) , ACFirstClass::Type() , Cancer::Type() , Passenger::Construct("Abhishek" , Female::Type() , "123456789111" , Date::Construct(17,12,1901), "" , "Singh" , "7867658902" ,"Cancer"));
        // // multiple bookings -> same date of reservation -> same passenger
        cout<<"MULTIPLE BOOKING SAME DOR(RESERVATION) SAME PASSENGER : PASSED"<<"\n";
    }
    catch(...){
        cout<<"MULTIPLE BOOKING SAME DOR(RESERVATION) SAME PASSENGER : FAILED"<<"\n";
    }

    try{
        Booking *b7 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(12,2,2021) , AC3Tier::Type() , Tatkal::Type() , Passenger::Construct("Abhishek" , Male::Type() , "123456789111" , Date::Construct(17,12,1901)));
        Booking *b8 = Booking::ReserveBooking(Station::Construct("Chennai") , Station::Construct("Bangalore")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , ACFirstClass::Type() , Tatkal::Type() , Passenger::Construct("Abhishek" , Male::Type() , "123456789111" , Date::Construct(17,12,1901)));
        // multiple bookings -> same date of reservation -> different passenger
        cout<<"MULTIPLE BOOKING SAME DOR(RESERVATION) DIFFERENT PASSENGER : PASSED"<<"\n";
    }
    catch(...){
        cout<<"MULTIPLE BOOKING SAME DOR(RESERVATION) DIFFERENT PASSENGER : FAILED"<<"\n";
    }
    
    try{
        Booking *b9 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(12,2,2021) , AC3Tier::Type() , General::Type() , Passenger::Construct("Abhishek" , Male::Type() , "123456789111" , Date::Construct(17,12,2001)));
        Booking *b10 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , ACFirstClass::Type() , General::Type() , Passenger::Construct("Abhishek" , Female::Type() , "123456789111" , Date::Construct(17,12,1901), "" , "Singh" , "7867658902" ,"Cancer"));
        // multiple bookings from the same departure station
        cout<<"MULTIPLE BOOKING FROM SAME DEPARTURE STATION : PASSED"<<"\n";
    }
    catch(...){
        cout<<"MULTIPLE BOOKING FROM SAME DEPARTURE STATION : FAILED"<<"\n";
    }
    
    try{
        Booking *b11 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(17 , 3 , 2021) , Date::Construct(12,2,2021) , AC3Tier::Type() , SeniorCitizen::Type() , Passenger::Construct("Abhishek" , Male::Type() , "123456789111" , Date::Construct(17,12,1901)));
        Booking *b12 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Kolkata")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , ACFirstClass::Type() , SeniorCitizen::Type() , Passenger::Construct("Abhishek" , Female::Type() , "123456789111" , Date::Construct(17,12,1901)));
        // multiple bookings to the same arrival station
        cout<<"MULTIPLE BOOKING TO SAME ARRIVAL STATION : PASSED" <<"\n";
    }
    catch(...){
        cout<<"MULTIPLE BOOKING TO SAME ARRIVAL STATION : FAILED" <<"\n";
    }

    try{
        Booking *b13 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(17 , 3 , 2021) , Date::Construct(12,2,2021) , AC3Tier::Type() , Blind::Type() , Passenger::Construct("Abhishek" , Male::Type() , "123456789111" , Date::Construct(17,12,1901) , "" , "Singh" , "7867658902" ,"Blind"));
        Booking *b14 = Booking::ReserveBooking(Station::Construct("Bangalore") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , ACFirstClass::Type() , Cancer::Type() , Passenger::Construct("Abhishek" , Female::Type() , "123456789111" , Date::Construct(17,12,1901), "" , "Singh" , "7867658902" ,"Cancer"));
        // multiple bookings for the same booking class
        cout<<"MULTIPLE BOOKING FOR SAME BOOKING CLASS : PASSED"<<"\n";
    }
    catch(...){
        cout<<"MULTIPLE BOOKING FOR SAME BOOKING CLASS : FAILED"<<"\n";
    }
    
    try
    {
        Booking *b15 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(17 , 3 , 2021) , Date::Construct(12,2,2021) , ACFirstClass::Type() , Tatkal::Type() , Passenger::Construct("Abhishek" , Male::Type() , "123456789111" , Date::Construct(17,12,1901)));
        Booking *b16 = Booking::ReserveBooking(Station::Construct("Chennai") , Station::Construct("Bangalore")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , ACFirstClass::Type() , Tatkal::Type() , Passenger::Construct("Abhishek" , Female::Type() , "123456789111" , Date::Construct(17,12,1901)));
        // multiple booking for same booking category
        cout<<"MULTIPLE BOOKING FOR SAME BOOKING CATEGORY : PASSED"<<"\n";
    }
    catch(...)
    {
        cout<<"MULTIPLE BOOKING FOR SAME BOOKING CATEGORY : FAILED"<<"\n";
    }
    
    try{
        Booking *b17 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(17 , 3 , 2021) , Date::Construct(12,2,2021) , AC3Tier::Type() , General::Type() , Passenger::Construct("Abhishek" , Male::Type() , "123456781119" , Date::Construct(17,12,1901)));
        Booking *b18 = Booking::ReserveBooking(Station::Construct("Chennai") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(12,2,2021) , ACFirstClass::Type() , General::Type() , Passenger::Construct("Abhishek" , Female::Type() , "123456781119" , Date::Construct(17,12,1901), "" , "Singh" , "7867658902" ,"Cancer"));
        // different booking class for same set of stations
        cout<<"DIFFERENT BOOKING FOR SAME SET OF STATION : PASSED"<<"\n";
    }
    catch(...){
        cout<<"DIFFERENT BOOKING FOR SAME SET OF STATION : FAILED"<<"\n";
    }
    
    try{
        Booking *b19 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(12,2,2021) , AC3Tier::Type() , Tatkal::Type() , Passenger::Construct("Abhishek" , Male::Type() , "123456789111" , Date::Construct(17,12,1901)));
        Booking *b20 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , ACFirstClass::Type() , Tatkal::Type() , Passenger::Construct("Abhishek" , Male::Type() , "123456789111" , Date::Construct(17,12,1901)));
        // different booking category for same set of stations
        cout<<"DIFFERENT BOOKING CATEGORY FOR SAME SET OF STATION : PASSED"<<"\n";
    }
    catch(...){
        cout<<"DIFFERENT BOOKING CATEGORY FOR SAME SET OF STATION : FAILED"<<"\n";
    }
    
    try{
        Booking *b21 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(21 , 3 , 2021) , Date::Construct(13,2,2021) , AC3Tier::Type() , General::Type() , Passenger::Construct("Abhishek" , Male::Type() , "123451116789" , Date::Construct(17,12,2001)));
        Booking *b22 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , AC3Tier::Type() , General::Type() , Passenger::Construct("Abhishek" , Male::Type() , "123451116789" , Date::Construct(17,12,2001)));
        // fare independent of date
        if(b21->ComputeFare() != b22->ComputeFare())
            throw 1;
        cout<<"FARE SHOULD BE INDEPENDENT OF DATE : PASSED"<<"\n";
    }
    catch(int){
        cout<<"FARE SHOULD BE INDEPENDENT OF DATE : FAILED"<<"\n";
    }
    
    try{
        Booking *b23 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(17 , 3 , 2021) , Date::Construct(12,2,2021) , AC3Tier::Type() , SeniorCitizen::Type() , Passenger::Construct("Abhishek" , Male::Type() , "121113456789" , Date::Construct(17,12,1901)));
        Booking *b24 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(17 , 3 , 2021) , Date::Construct(12,2,2021) , AC2Tier::Type() , SeniorCitizen::Type() , Passenger::Construct("Abhishek" , Male::Type() , "121113456789" , Date::Construct(17,12,1901)));
        if(b23->ComputeFare() == b24->ComputeFare())
            throw 1;
        cout<<"FARE SHOULD BE DEPENDENT ON BOOKING CLASS : PASSED"<<"\n";
    }
    catch(...){
        cout<<"FARE SHOULD BE DEPENDENT ON BOOKING CLASS : FAILED"<<"\n";
    }

    try{
        Booking *b25 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(17 , 3 , 2021) , Date::Construct(12,2,2021) , AC3Tier::Type() , Blind::Type() , Passenger::Construct("Abhishek" , Male::Type() , "123456711189" , Date::Construct(17,12,1901) , "" , "Singh" , "7867658902" ,"Blind"));
        Booking *b26 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(17 , 3 , 2021) , Date::Construct(12,2,2021) , AC3Tier::Type() , Cancer::Type() , Passenger::Construct("Abhishek" , Male::Type() , "123456711189" , Date::Construct(17,12,1901) , "" , "Singh" , "7867658902" ,"Blind"));
        if(b25->ComputeFare() == b26->ComputeFare())
            throw 1;
        cout<<"FARE SHOULD BE DEPENDENT ON BOOKING CATEGORY : PASSED"<<"\n";
    }
    catch(...){
        cout<<"FARE SHOULD BE DEPENDENT ON BOOKING CATEGORY : FAILED"<<"\n";
    }

    try{
        Booking *b27 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , AC3Tier::Type() , SeniorCitizen::Type() , Passenger::Construct("Abhishek" , Male::Type() , "123456111789" , Date::Construct(17,12,1901)));
        Booking *b28 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , AC3Tier::Type() , SeniorCitizen::Type() , Passenger::Construct("Abhishek" , Female::Type() , "123456111789" , Date::Construct(17,12,1901)));
        
        if(b27->ComputeFare() == b28->ComputeFare())
            throw 1;

        cout<<"FARE SHOULD BE DEPENDENT ON PASSENGER GENDER : PASSED"<<"\n";
    }
    catch(...){
        cout<<"FARE SHOULD BE DEPENDENT ON PASSENGER GENDER : FAILED"<<"\n";
    }
    
    try{
        Booking *b29 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , AC3Tier::Type() , SeniorCitizen::Type() , Passenger::Construct("Abhishek" , Male::Type() , "123411156789" , Date::Construct(17,12,1951)));
        Booking *b30 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , AC3Tier::Type() , SeniorCitizen::Type() , Passenger::Construct("Abhishek" , Male::Type() , "123411156789" , Date::Construct(17,12,2002)));
    
        if(b29->ComputeFare() == b30->ComputeFare())
            throw 1;
        cout<<"FARE SHOULD BE DEPENDENT ON PASSENGER AGE : PASSED"<<"\n";
    }
    catch(...){
        cout<<"FARE SHOULD BE DEPENDENT ON PASSENGER AGE : FAILED"<<"\n";
    }

    try{
        Passenger p1 = Passenger::Construct("Abhishek" , Male::Type() , "111123456789" , Date::Construct(17,12,2001), "Arpit", "Singh", "7877474747","Cancer");
        Passenger p2 = Passenger::Construct("Abhishek" , Male::Type() , "111123456789" , Date::Construct(17,12,2001), "Arpit", "Singh", "7877474747","Blind");
        Booking *b31 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , AC3Tier::Type() , Cancer::Type() , p1);
        Booking *b32 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , AC3Tier::Type() , Blind::Type() , p2);
        if(b31->ComputeFare() == b32->ComputeFare())
            throw 1;
        cout<<"FARE SHOULD BE DEPENDENT ON PASSENGER DISABILITY : PASSED"<<"\n";
    }
    catch(...){
        cout<<"FARE SHOULD BE DEPENDENT ON PASSENGER DISABILITY : FAILED"<<"\n";
    }

    try{
        Booking *b31 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , AC3Tier::Type() , Handicapped::Type() , Passenger::Construct("Abhishek" , Male::Type() , "111123456789" , Date::Construct(17,12,3000)));
        
        cout<<"INVALID BOOKING DUE TO PASSENGER DOB(BIRTH) (NEGATIVE TEST) : PASSED"<<"\n";
    }
    catch(BadDate &ex){
        cout<<"INVALID BOOKING DUE TO PASSENGER DOB(BIRTH) (NEGATIVE TEST) : FAILED"<<"\n";
    }

    try{
        Booking *b31 = Booking::ReserveBooking(Station::Construct("") , Station::Construct("Mumbai")  , Date::Construct(20 , 3 , 2021) , Date::Construct(19,2,2021) , AC3Tier::Type() , Handicapped::Type() , Passenger::Construct("Abhishek" , Male::Type() , "111123456789" , Date::Construct(17,12,2002)));
        
        cout<<"INVALID BOOKING DUE TO INVALID STATION (NEGATIVE TEST) : PASSED"<<"\n";
    }
    catch(BadStation &ex){
        cout<<"INVALID BOOKING DUE TO INVALID STATION (NEGATIVE TEST) : FAILED"<<"\n";
    }
    
    // Output the bookings done where sBookings is the collection of bookings done
    vector<Booking*>::iterator it;
    for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it) {
        cout << *(*it);
    }
    return;
}

// This is the function for Unit Testing, This will call the respective function in each class, and print the result
void UnitTesting() {
    Date::UnitTestDate();
    Station::UnitTestStation();
    Passenger::UnitTestPassenger();
    Railways::UnitTestRailways();
    Booking::UnitTestBooking();


    AC2Tier::UnitTestAC2Tier();
    AC3Tier::UnitTestAC3Tier();
    ACChairCar::UnitTestACChairCar();
    ACFirstClass::UnitTestACFirstClass();
    FirstClass::UnitTestFirstClass();
    SecondSitting::UnitTestSecondSitting();
    Sleeper::UnitTestSleeper();
    ExecutiveChairCar::UnitTestExecutiveChairCar();
}

// This are the booking that were given in the problem statement
void GivenBookingApplication(){
    try{
        Booking *b1 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai") , Date::Construct(12,5,2021) , Date::Construct(17 , 3 , 2020) , AC3Tier::Type() , General::Type() , Passenger::Construct("Shreyansh" , Male::Type() , "123456789111" , Date::Construct(17,12,2001)));
    }
    catch(BadDate &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadPassenger &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadStation &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadBooking &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadRailways &ex){
        cout<<ex.what()<<endl;
    }
    catch(...){
        cout<<"Unexpected Error in Booking b1";
    }

    try{
        Booking *b2 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai") , Date::Construct(19,2,2021) , Date::Construct(20 , 1 , 2020) , ACFirstClass::Type() , General::Type() , Passenger::Construct("Shreyansh" , Male::Type() , "123456789111" , Date::Construct(17,12,2001)));
    }
    catch(BadDate &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadPassenger &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadStation &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadBooking &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadRailways &ex){
        cout<<ex.what()<<endl;
    }
    catch(...){
        cout<<"Unexpected Error in Booking b2";
    }

    try{
        Booking *b3 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai") , Date::Construct(12,2,2021) , Date::Construct(17 , 3 , 2020) , AC3Tier::Type() , SeniorCitizen::Type() , Passenger::Construct("Shreyansh" , Male::Type() , "123456789111" , Date::Construct(17,12,1901)));
    }
    catch(BadDate &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadPassenger &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadStation &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadBooking &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadRailways &ex){
        cout<<ex.what()<<endl;
    }
    catch(...){
        cout<<"Unexpected Error in Booking b3";
    }

    try{
        Booking *b4 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai") , Date::Construct(19,2,2021) , Date::Construct(20 , 1 , 2020) , ACFirstClass::Type() , SeniorCitizen::Type() , Passenger::Construct("Kunal" , Female::Type() , "123456789111" , Date::Construct(17,12,1901)));
    }
    catch(BadDate &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadPassenger &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadStation &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadBooking &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadRailways &ex){
        cout<<ex.what()<<endl;
    }
    catch(...){
        cout<<"Unexpected Error in Booking b4";
    }

    try{
        Booking *b5 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai") , Date::Construct(12,2,2021) , Date::Construct(17 , 3 , 2020) , AC3Tier::Type() , Blind::Type() , Passenger::Construct("Kunal" , Male::Type() , "123456789111" , Date::Construct(17,12,1901) , "" , "Singh" , "7867658902" ,"Blind"));
    }
    catch(BadDate &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadPassenger &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadStation &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadBooking &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadRailways &ex){
        cout<<ex.what()<<endl;
    }
    catch(...){
        cout<<"Unexpected Error in Booking b5";
    }

    try{
        Booking *b6 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai") , Date::Construct(19,2,2021) , Date::Construct(20 , 1 , 2020) , ACFirstClass::Type() , Cancer::Type() , Passenger::Construct("Kunal" , Female::Type() , "123456789111" , Date::Construct(17,12,1901), "" , "Singh" , "7867658902" ,"Cancer"));
    }
    catch(BadDate &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadPassenger &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadStation &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadBooking &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadRailways &ex){
        cout<<ex.what()<<endl;
    }
    catch(...){
        cout<<"Unexpected Error in Booking b6";
    }

    try{
        Booking *b7 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai") , Date::Construct(12,2,2021) , Date::Construct(17 , 3 , 2020) , AC3Tier::Type() , Tatkal::Type() , Passenger::Construct("Shreyansh" , Male::Type() , "123456789111" , Date::Construct(17,12,1901)));
    }
    catch(BadDate &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadPassenger &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadStation &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadBooking &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadRailways &ex){
        cout<<ex.what()<<endl;
    }
    catch(...){
        cout<<"Unexpected Error in Booking b7";
    }

    try{
        Booking *b8 = Booking::ReserveBooking(Station::Construct("Chennai") , Station::Construct("Bangalore") , Date::Construct(19,2,2021) , Date::Construct(20 , 1 , 2020) , ACFirstClass::Type() , Tatkal::Type() , Passenger::Construct("Kunal" , Female::Type() , "123456789111" , Date::Construct(17,12,1901)));
    }
    catch(BadDate &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadPassenger &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadStation &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadBooking &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadRailways &ex){
        cout<<ex.what()<<endl;
    }
    catch(...){
        cout<<"Unexpected Error in Booking b8";
    }

    try{
        Booking *b9 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai") , Date::Construct(12,5,2021) , Date::Construct(17 , 3 , 2020) , AC3Tier::Type() , General::Type() , Passenger::Construct("Shreyansh" , Male::Type() , "123456789111" , Date::Construct(17,12,2001)));
    }
    catch(BadDate &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadPassenger &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadStation &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadBooking &ex){
        cout<<ex.what()<<endl;
    }
    catch(BadRailways &ex){
        cout<<ex.what()<<endl;
    }
    catch(...){
        cout<<"Unexpected Error in Booking b9";
    }

    vector<Booking*>::iterator it;
    for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it) {
        cout << *(*it);
    }
    return;
}

// There are function call for Booking Application, Unit Testing and the Given Tests, You can comment/un-comment based on the uses, and the expected output
int main() {
    // BookingApplication();
    // UnitTesting();
    GivenBookingApplication();
    
    // Deleting the classes, once the functions are done
    delete &ACFirstClass::Type();
    delete &AC2Tier::Type();
    delete &AC3Tier::Type();
    delete &ACChairCar::Type();
    delete &FirstClass::Type();
    delete &Sleeper::Type();
    delete &SecondSitting::Type();
    delete &Railways::IndianRailways();
    return 0;
}
