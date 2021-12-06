#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>

using std::string;
using std::vector;
using std::ostream;
using std::cerr;
using std::endl;
using std::cout;
using std::ios;
using std::cin;

namespace emircand
{
    /*class to represent a set of DayofYear Objects*/
class DayofYearSet{
public:
    /*DayofYear is an inner class with all its public and private members*/
    class DayofYear{
        public:
            /*getters and setters for DayofYear class*/
            void setDay(int day);
            void setMonth(int month);

            int getDay() const;
            int getMonth() const;

            /*DayofYear constructor functions*/
            DayofYear();
            DayofYear(int day, int month);
            ~DayofYear();
            static int getNumber(); 
            friend bool operator ==(const DayofYearSet::DayofYear& obj1, const DayofYearSet::DayofYear& obj2);
        private:
            static int numberDayofYear;
            int Day;
            decltype(Day) Month;
            
            void testDate();
    };
    /*constructors of DayofYearSet*/
    DayofYearSet();
    explicit DayofYearSet(vector <DayofYear> obj);
    ~DayofYearSet();


    friend ostream& operator <<(ostream& outputStream, const DayofYearSet& obj);
    friend const DayofYearSet operator +(const DayofYearSet& obj1, const DayofYearSet& obj2);
    friend const DayofYearSet operator -(const DayofYearSet& obj1, const DayofYearSet& obj2);
    friend const DayofYearSet operator ^(const DayofYearSet& obj1, const DayofYearSet& obj2);
    friend bool operator !=(const DayofYearSet& obj1, const DayofYearSet& obj2);
    friend bool operator ==(const DayofYearSet& obj1, const DayofYearSet& obj2);
    DayofYear& operator [](int index) const;
    const DayofYearSet operator !();
    
    void setPtr(DayofYear *ObjPtr){ ObjArr = ObjPtr;}
    void setVector(vector <DayofYear> objVector) {ObjVector = objVector;}
    
    DayofYear *getPtr() const {return ObjArr;}
    vector <DayofYear> getVector() const {return ObjVector;}

    void CopyVectortoPtr();
    int size() const;
    void remove(int index);
    void add(int dayValue, int yearValue);

private:
    DayofYear *ObjArr;
    vector<DayofYear> ObjVector;
};

int DayofYearSet::DayofYear::numberDayofYear = 0;

string MonthName(int monthValue);
void SaveToText(DayofYearSet obj);

const DayofYearSet operator +(const DayofYearSet& obj1, const DayofYearSet& obj2);
const DayofYearSet operator -(const DayofYearSet& obj1, const DayofYearSet& obj2);
const DayofYearSet operator ^(const DayofYearSet& obj1, const DayofYearSet& obj2);
bool operator !=(const DayofYearSet& obj1, const DayofYearSet& obj2);
bool operator ==(const DayofYearSet& obj1, const DayofYearSet& obj2);
bool operator ==(const DayofYearSet::DayofYear& obj1, const DayofYearSet::DayofYear& obj2);
}

#endif