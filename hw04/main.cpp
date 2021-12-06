#include <iostream>
#include <vector>
#include <string>
#include "Functions.h"
#include "Functions.cpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace emircand;

void fillVectors(vector<DayofYearSet::DayofYear> &Days);

int main(){
    srand(time(NULL));
    /*declare and fill vectors and objects*/
    vector<DayofYearSet::DayofYear> Days1, Days2, Days3, Days4, Days5;
    fillVectors(Days1);
    fillVectors(Days2);
    fillVectors(Days3);
    fillVectors(Days4);
    fillVectors(Days5);

    DayofYearSet obj1(Days1), obj2(Days2), obj3(Days3), obj4(Days4), obj5(Days5), obj6(Days1);

    /*overloaded stream insertion operator operator<< will print DayofYearSet details*/
    cout << "------------------" << endl  
    << "test operator<<" << endl
    << "------------------" << endl
    << "set 1-\n" << obj1 
    << "\nset 2-\n" << obj2 
    << "\nset 3-\n" << obj3 
    << "\nset 4-\n" << obj4 
    << "\nset 5-\n" << obj5 
    << "\nset 6-\n" << obj6 << endl;

    /*Overloaded operator== and operator!= operators for comparing DayofYearSet objects.*/
    cout << "------------------" << endl   
    << "test operator== and operator!=" << endl
    << "------------------" << endl;

    if(obj1 == obj6)
        cout << "set1 and set6 are equal sets" << endl;
    
    if(obj3 != obj5)
        cout << "set3 and set5 are discrete sets" << endl;

    /*Overloaded binary operator+ returns the union set.*/
    cout << "------------------" << endl  
    << "test operator+" << endl
    << "------------------" << endl;
    DayofYearSet obj7 = obj2 + obj4;
    DayofYearSet obj10 = obj1 + obj3;
    cout << "union set of set2 and set4\n" << obj7 << endl;
    cout << "union set of set1 and set3\n" << obj10 << endl;

    /*Overloaded binary operator+ returns the union set.*/
    cout << "------------------" << endl  
    << "test operator-" << endl
    << "------------------" << endl;
    DayofYearSet diff1 = obj2 - obj4;
    DayofYearSet diff2 = obj1 + obj3;
    cout << "difference of set2 to set4\n" << obj7 << endl;
    cout << "difference set of set1 to set3\n" << obj10 << endl;

    /*Overloaded binary operator^ returns the intersection set.*/
    cout << "------------------" << endl  
    << "test operator^" << endl
    << "------------------" << endl;
    DayofYearSet obj8 = obj3 ^ obj5;
    DayofYearSet obj9 = obj1 ^ obj6;
    cout << "intersection set of set3 and set5\n" << obj8 << endl
    <<"intersection set of set1 and set6\n" << obj9 << endl;

    /*Overloaded unary operator! returns the complement set. 
    Note that there are only 365 days in a year.*/
    cout << "------------------" << endl  
    << "test operator!" << endl
    << "------------------" << endl;
    DayofYearSet obj11 = obj1 + obj2 + obj3 + obj4 + obj5;
    cout << "complement set of set1 + set2 + set3 + set4 + set5\n" << !obj11 << endl;

    /*Test the De Morgan rule for sets with at least 5 different set pairs. 
    Note that for sets s1 and s2, De Morgan says that !(s1 + s2) == !s1 ^ !s2*/
    cout << "------------------" << endl  
    << "test De Morgan" << endl
    << "------------------" << endl;
    DayofYearSet obj12 = obj1 + obj2, obj13 = !obj1 ^ !obj2;
    if(!(obj12) == obj13)
        cout << "de morgan proof is correct: !(obj1 + obj2) == !obj1 ^ !obj2 work " << endl;
    DayofYearSet obj14 = obj2 + obj3, obj15 = !obj2 ^ !obj3;
    if(!(obj14) == obj15)
        cout << "de morgan proof is correct: !(obj2 + obj3) == !obj2 ^ !obj3 work " << endl;
    DayofYearSet obj16 = obj3 + obj4, obj17 = !obj3 ^ !obj4;
    if(!(obj16) == obj17)
        cout << "de morgan proof is correct: !(obj3 + obj4) == !obj3 ^ !obj4 work " << endl;
    DayofYearSet obj18 = obj4 + obj5, obj19 = !obj4 ^ !obj5;
    if(!(obj18) == obj19)
        cout << "de morgan proof is correct: !(obj4 + obj5) == !obj4 ^ !obj5 work " << endl;
    DayofYearSet obj20 = obj5 + obj6, obj21 = !obj5 ^ !obj6;
    if(!(obj20) == obj21)
        cout << "de morgan proof is correct: !(obj5 + obj6) == !obj5 ^ !obj6 work " << endl;
    
    cout << "------------------" << endl  
    << "test add function" << endl
    << "------------------" << endl;

    cout << "before addition to set 1: \n" << obj1 << endl;
    obj1.add(8,6);
    cout << "after addition to set 1:  \n" << obj1 << endl;

    cout << "before addition to set 2: \n" << obj2 << endl;
    obj2.add(8,6);
    cout << "after addition to set 2:  \n" << obj2 << endl;
    

    cout << "------------------" << endl  
    << "test size function" << endl
    << "------------------" << endl;
    cout << "size of set1 " << obj1.size() << endl
    << "size of union set of set2 and set4 " << obj7.size() << endl;

    cout << obj1[0].getNumber() << " is number of the total DayofYear objects" << endl;


    return 0;
}

void fillVectors(vector<DayofYearSet::DayofYear> &Days)
{
    for(int i = 0; i < 3; i++)
    {
        int rDay = rand() % 28 + 1;
        int rMonth = rand() % 12 + 1;
        DayofYearSet::DayofYear newObj(rDay, rMonth);   
        Days.push_back(newObj);
    }
}