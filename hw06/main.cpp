#include <iostream>
#include <algorithm>
#include <initializer_list>

#include "Iterable.h"
#include "GTUVector.cpp"
#include "GTUVector.h"
#include "GTUSet.h"
#include "GTUSet.cpp"
#include "GTUArray.h"
#include "GTUArray.cpp"

using namespace emircand;
using std::cout;
using std::endl;


/*printer function for containers
this function also tests cbegin, cend and size functions*/
template <typename T>
void display(const Iterable<T> &container)
{
	cout << "#  ";
	for(auto iterator = container.cbegin(); iterator != container.cend(); ++iterator)
		cout << *(iterator) << "  #  " ;
	cout << "\ncontainer size: "<< container.size() << "\n\n";
}


int main()
{
	cout << "-----------------------------------------------GTUVector Test-----------------------------------------------\n";
	//create GTUVector container class object
	GTUVector<int> vector = {3, 5, 1};
	display(vector);
	vector.add(99);
	display(vector);
	vector.add(100);
	display(vector);

	cout << "**range based 'for loop' test for GTUVector class**\nprint with for loop: ";
	for(auto i : vector)
		cout << i << "  #  ";

	cout << "\n\n**for_each test for GTUVector class**\nprint with for_each loop: ";
	std::for_each(vector.begin(), vector.end(), [](int element) {cout << element << "  #  ";});

	cout << "\n\n**test erase function for GTUVector class**\n";
	for(auto iterator = vector.begin(); iterator != vector.end(); ++iterator)
		if(*(iterator) == 3)
			vector.erase(iterator);
	display(vector);
	cout << "**test clear&empty functions for GTUVector class**\n";
	vector.clear();
	if(vector.empty() == true)
		cout << "GTUVector is empty..\n\n";
	else
		cout << "GTUVector is not empty\n\n";
	
	
	cout << "-----------------------------------------------GTUSet Test-----------------------------------------------\n\n";
	GTUSet<int> set = {44, 53, 12, 14, 54};
	cout << "\n**test for_each loop for GTUSet class**\n";
	std::for_each(set.begin(), set.end(), [](int element) {cout << element << "  #  ";});
	cout << "\n\n";
	set.add(53);
	set.add(54);
	set.add(15);
	cout << "---set1---\n";
	display(set);
	
	cout << "---set1---\n";
	GTUSet<int> set1 = {44, 3, 5, 23};
	cout << "\nset1: \n";
	display(set1);
	cout << "**test union function for GTUSet class**\nset2 is union set of set1 and set\n---set2---\n";
	GTUSet<int> set2;
	set2.myUnion(set,set1);
	cout << "\nset2: \n";
	display(set2);
	cout << "**test intersect function for GTUSet class**\nset3 is intersection set of set1 and set\n---set3---\n";
	GTUSet<int> set3;
	set3.myIntersect(set,set1);
	display(set3);
	
	cout << "\n\n**test search function for GTUSet class**\n";
	set2.search(57);
	display(set1);
	cout << "\n\n**test myDelete and erase function for GTUSet class**\n";
	set1.myDelete(1);
	display(set1);
	cout << "\n\n**test clear function for GTUSet class**\n";
	set.clear();
	if(set.empty()) cout << "set is empty\n";
	
	
	
	cout << "\n-----------------------------------------------GTUArray Test-----------------------------------------------\n";
	GTUArray<int, 8> array;
	for (int i=0; i<8; i++)
		array[i] = i*4 + 1;
	cout << "\n**test for_each loop for GTUArray class**\n";
	std::for_each(array.begin(), array.end(), [](int element) {cout << element << "  #  ";});

	cout << "\n\n**test erase function for GTUArray class**\n";
	for(auto iterator = array.begin(); iterator != array.end(); ++iterator)
		if(*(iterator) == 5)
			array.erase(iterator);

	display(array);
	array.add(12);
	array.add(13);

	cout << "\n\n**test clear function for GTUArray class**\n";
	array.clear();

	GTUArray<int, 3> array_2 = {1,2,3};
	for (auto i: array_2)
		cout << i << "  #  ";
	cout << "\n";
	return 0;
}