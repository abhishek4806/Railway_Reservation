// Name : Abhishek Kumar
// Roll No. : 19ME31035

#ifndef BOOKINGCLASSES_H
#define BOOKINGCLASSES_H
#include <iostream>
using namespace std;

// Parent class for the booking classes
class BookingClasses {
protected:
    float loadFactor_;
    string name_;
public:
    virtual float GetLoadFactor() const = 0;
    virtual string GetName() const = 0;
    virtual bool IsAC() const = 0;       
    virtual bool IsLuxury() const = 0;
    virtual bool IsSitting() const = 0;
    virtual int GetNumberOfTiers() const = 0;
    virtual int GetReservationCharge() const = 0;
    virtual int GetMinimumTatkalCharge() const = 0;
    virtual int GetMaximumTatkalCharge() const = 0;
    virtual int GetMinimumTatkalDistance() const = 0;
    virtual void ChangeLoadFactor() const {return;}    
};

#endif // BOOKINGCLASSES_H
