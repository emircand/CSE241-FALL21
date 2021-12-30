#ifndef GTUSET_H
#define GTUSET_H

#include "Iterable.h"

namespace emircand
{
    template<class T>
    class GTUSet : public Iterable<T>
    {
        public:
        GTUSet();
        GTUSet(const GTUSet<T>& Copy);
        GTUSet(GTUSet<T>&& Move);
        GTUSet(std::initializer_list<T> myList); //initializer_list constructor
        ~GTUSet(){}

        bool empty() const; //Test whether container is empty
        int size() const; //Return container size
        void erase(GTUIterator<T>& object); //Erase element pointed by the given iterator
        void clear(); //Clear all content

        void add(const T& object); //add a new element to container
        void mySort(); //sort container
        void search(T object); //search T object in set
        void myDelete(T object); //find T object in set; call erase function
        void myIntersect(const GTUSet<T>& object1, const GTUSet<T>& object2);
        void myUnion(const GTUSet<T>& object1, const GTUSet<T>& object2);

        //move assignment operator
        GTUSet<T>& operator=(GTUSet<T>&& other);
        
        GTUIterator<T> begin(); //Return iterator to beginning
        GTUIterator<T> end(); //Return iterator to end
        GTUIteratorConst<T> cbegin() const; //Return a constant iterator to beginning
        GTUIteratorConst<T> cend() const; //Return a constant iterator to end

    };
    /*operator overloadings for intersection and union operations*/
    template <class T>
    GTUSet<T> operator+(const GTUSet<T>& obj1, const GTUSet<T>& obj2);
    template <class T>
    GTUSet<T> operator^(const GTUSet<T>& obj1, const GTUSet<T>& obj2);
    
}

#endif