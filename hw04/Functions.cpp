#include "Functions.h"
#include <iostream>

namespace emircand
{

int DayofYearSet::DayofYear::getNumber()
{
    return numberDayofYear;
}

/*save object to file*/
void SaveToText(DayofYearSet obj)
{
    std::ofstream fout;
    vector <DayofYearSet::DayofYear> SaveVector = obj.getVector();

    /*open file -which is string variable fileName- in write mode*/    
    fout.open("save.txt", std::ios::out);

    if (fout.is_open())
    {
        for (int i = 0; i < obj.size(); i++)
        {
            fout << SaveVector[i].getDay() << " / " << SaveVector[i].getMonth() << endl;
        }
        fout.close();
        cout << "set succesfully saved to save.txt" << endl;
    }
    else cout << "set couldn't saved to save.txt" << endl;

}
    
/*send vector parameter to constructor, then copy all elements to DayOfYear pointer*/
DayofYearSet::DayofYearSet(vector<DayofYear> objVector)
    :ObjVector(objVector)
{
   CopyVectortoPtr();
}

/*default constructor*/
DayofYearSet::DayofYearSet()
{
}

/*destructor*/
DayofYearSet::~DayofYearSet()
{
    delete [] ObjArr;
}

/*default constructor*/
DayofYearSet::DayofYear::DayofYear()
                        :Day(1), Month(1)   
{
    testDate();
    numberDayofYear++;
}

/**/
DayofYearSet::DayofYear::DayofYear(int day, int month)
                        :Day(day), Month(month)
{
    testDate();
    numberDayofYear++;
}

DayofYearSet::DayofYear::~DayofYear()
{
}

void DayofYearSet::DayofYear::setDay(int day){
    if(day >= 1 && day <= 31){
        Day = day;
    }
    else cerr << "!!!!invalid day value" << endl;
}
void DayofYearSet::DayofYear::setMonth(int month){
    if(month >= 1 && month <= 12){
        Month = month;
    }
    else cerr << "!!!!invalid month value" << endl;
}


int DayofYearSet::DayofYear::getDay() const{
    return Day;
}

int DayofYearSet::DayofYear::getMonth() const{
    return Month;
}

/*test the validity of the dates*/
void DayofYearSet::DayofYear::testDate(){
    if(getMonth() == 2)
    {
        if(getDay() < 1 && getDay() > 28)
        {
            cerr << "!!!!invalid day value" << endl;
            exit(1);
        }
    }
    else if(getMonth() == 1 || getMonth() == 3 || getMonth() == 5 || getMonth() == 7 || getMonth() == 8 || getMonth() == 10)
    {
        if(getDay() < 1 && getDay() > 31)
        {
            cerr << "!!!!invalid day value" << endl;
            exit(1);
        }
    }
    else if(getMonth() == 4 || getMonth() == 6 || getMonth() == 9 || getMonth() == 11)
    {
        if(getDay() < 1 && getDay() > 30)
        {
            cerr << "!!!!invalid day value" << endl;
            exit(1);
        }
    }
    else if(getMonth() < 1 && getMonth() > 12)
    {
        cerr << "!!!invalid month value" << endl;
        exit(1);
    }
}

/*
operator overloading for cout << obj
print day value and month name in every element of pointer
*/
ostream& operator <<(ostream& outputStream, const DayofYearSet& obj){
    /*increase index value, after every print of dayofyear variables..*/
    
    for(int i = 0; i < obj.size(); i++){
        /*switch case month value to month name*/
        string monthStr = MonthName(obj[i].getMonth());
        /*nested usage of operator overloadings
        [] operator returns the element of pointer in given position*/
        outputStream << obj[i].getDay() << " " << monthStr << endl;
    }
	return outputStream;
}

const DayofYearSet DayofYearSet::operator! ()
{
    std::vector <DayofYearSet::DayofYear> tempVector = this->getVector();
    int dayValue = 1, monthValue = 1;
    std::vector <DayofYearSet::DayofYear> inverseSet;
    for (int i = 0; i < 365; i++)
    {
        bool flag = true;
        
        
        for (int j = 0; j < this->size() && flag; j++)
        {
            if(tempVector[j].getDay() == dayValue && tempVector[j].getMonth() == monthValue)
                flag = false;
        }

        if(flag)
        {   
            DayofYearSet::DayofYear newObj(dayValue, monthValue);
            inverseSet.push_back(newObj);
        }

        if(dayValue >= 28)
        {
            if(dayValue == 28)
            {
                if(monthValue == 2)
                {
                    monthValue++;
                    dayValue = 1;
                }
                else dayValue++;
            }
            else if(dayValue == 31)
            {
                if(monthValue == 1 || monthValue == 3 || monthValue == 5 || monthValue == 7 || monthValue == 8 || monthValue == 10)
                {
                    dayValue = 1;
                    monthValue++;
                }
                else dayValue++;
            }
            else if(dayValue == 30)
            {
                if(monthValue == 4 || monthValue == 6 || monthValue == 9 || monthValue == 11)
                {  
                    dayValue = 1;
                    monthValue++;
                }
                else dayValue++;
            }
            else dayValue++;
        }
        else dayValue++;
    }
    /*
    send vector to constructor;
    constructor function which passes vector parameter, will delete duplicate objects 
    */
    return DayofYearSet(inverseSet);
}


const DayofYearSet operator +(const DayofYearSet& obj1, const DayofYearSet& obj2)
{
    vector <DayofYearSet::DayofYear> newObj;
    for (int i = 0; i < obj1.size() || i < obj2.size(); i++)
    {
        if(i < obj1.size())
            newObj.push_back(obj1[i]);
        if(i < obj2.size())
            newObj.push_back(obj2[i]);
    }
    /*
    send vector to constructor;
    constructor function which passes vector parameter, will delete duplicate objects 
    */
    return DayofYearSet(newObj);
}

const DayofYearSet operator ^(const DayofYearSet& obj1, const DayofYearSet& obj2)
{
    vector <DayofYearSet::DayofYear> intersection;
    bool flag = true;
    for (int i = 0; i < obj1.size(); i++)
    {
        flag = true;
        /*if an object exists in each of two sets, add it to the intersection vector*/
        for (int j = 0; j < obj2.size() && flag; j++)
        {
            if(obj1[i] == obj2[j])
            {
                intersection.push_back(obj1[i]);
                flag = false;
            }
        }    
        
    }
    /*
    send vector to constructor;
    constructor function which passes vector parameter, will delete duplicate objects 
    */
    return DayofYearSet(intersection);
}

const DayofYearSet operator -(const DayofYearSet& obj1, const DayofYearSet& obj2)
{
    vector <DayofYearSet::DayofYear> differenceSet;
    for (int i = 0; i < obj1.size(); i++)
    {
        bool flag = true;
        /*if an object exists in each of two sets, add it to the intersecition vector*/
        for (int j = 0; j < obj2.size() && flag; j++)
            if(obj1[i] == obj2[j])
                flag = false;

        if(flag) 
            differenceSet.push_back(obj1[i]);
    }
    /*
    send vector to constructor;
    constructor function which passes vector parameter, will delete duplicate objects 
    */
    return DayofYearSet(differenceSet);
}

//Overloaded binary operator[] returns the element at given position. 
DayofYearSet::DayofYear& DayofYearSet::operator[](int index) const
{
    if(index >= this->size())
    {
        std::cerr << "pointer index out of bounds, exiting" << endl;
        exit(1);
    }
    return ObjArr[index];
}

//operator!= for comparing DayofYearSet objects.
bool operator !=(const DayofYearSet& obj1, const DayofYearSet& obj2)
{
    bool flag = true;
    
    if(obj1.size() == obj2.size())
    {
        for (int i = 0; i < obj1.size() && flag; i++)
        {
            /*nested usage of overloading functions*/
            for (int j = 0; j < obj2.size(); j++)
                if(obj1[i] == obj2[j])
                    flag = false;
        }
    }
    return flag;
}

//operator== for comparing DayofYearSet objects.
bool operator ==(const DayofYearSet& obj1, const DayofYearSet& obj2)
{
    bool flag = false;
    if(obj1.size() == obj2.size())
    {
        for (int i = 0; i < obj1.size(); i++)
        {
            for (int j = 0; j < obj2.size(); j++)
                if(obj1[i] == obj2[j])
                    flag = true;

            if(flag == false) break;
        }
    }
    return flag;
}

//operator!= operators for comparing DayofYear objects.
bool operator ==(const DayofYearSet::DayofYear& obj1, const DayofYearSet::DayofYear& obj2)
{
    return (obj1.getDay() == obj2.getDay() && obj1.getMonth() == obj2.getMonth());
}

void DayofYearSet::add(int dayValue, int monthValue)
{
    DayofYearSet::DayofYear newObj(dayValue, monthValue);

    /*add new element to vector*/
    vector <DayofYearSet::DayofYear> temp = this->getVector();
    temp.push_back(newObj);
    this->setVector(temp);
    /*delete the duplicate and send to pointer*/
    CopyVectortoPtr();

}

void DayofYearSet::remove(int index)
{
    vector <DayofYearSet::DayofYear> tempVector = this->getVector();
    tempVector.erase(tempVector.begin() + index);
    this->setVector(tempVector);
}

/*Member function size returns the number of elements from vector*/
int DayofYearSet::size() const
{
    auto SizeofVector = getVector().size();
    return SizeofVector;
}

/*convert monthNumber to MonthName, print to the console in string type*/
string MonthName(int monthValue)
{
    string monthStr;
    switch (monthValue)
    {
        case 1:
            monthStr = "January";
            break;
        case 2:
            monthStr = "February";
            break;
        case 3:
            monthStr = "March";
            break;
        case 4:
            monthStr = "April";
            break;
        case 5:
            monthStr = "May";
            break;
        case 6:
            monthStr = "June";
            break;
        case 7:
            monthStr = "July";
            break;
        case 8:
            monthStr = "August";
            break;
        case 9:
            monthStr = "September";
            break;
        case 10:
            monthStr = "October";
            break;
        case 11:
            monthStr = "November";
            break;
        case 12:
            monthStr = "December";
            break;
    }
    return monthStr;
}

/*call getVector then copy elements from vector to dynamic array*/
void DayofYearSet::CopyVectortoPtr()
{
    vector <DayofYear> tempVector = this->getVector(); //get vector
    DayofYear *tempPtr = new DayofYear[this->size()]; //create dynamic DayofYear array
    /*traverse in vector and copy elements to pointer; delete duplicates*/
    for (int i = 0; i < tempVector.size(); i++)
    {
        for (int j = i; j < tempVector.size(); j++)
        {
            /*if two or more elements are same, delete all duplicates except one*/
            if( (tempVector[i] == tempVector[j]) && (j != i) )
            {
                this->remove(j-1);
                tempVector = this->getVector();
            }      
        }
    }
    
    for (int i = 0; i < tempVector.size(); i++)
    {
        /*assign vector element to pointer*/
        tempPtr[i] = tempVector[i];
    }

    this->setVector(tempVector); //initialize vector to DayofYearSet class
    this->setPtr(tempPtr); //initalize pointer to DayofYearSet class
}

}