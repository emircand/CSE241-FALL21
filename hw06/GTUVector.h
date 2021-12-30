#ifndef GTUVECTOR_H
#define GTUVECTOR_H

#include "Iterable.h"

#include <memory>


namespace emircand
{
    template <typename T>
    class GTUVector : public Iterable<T> 
    {
        public:
        GTUVector();
        GTUVector(const GTUVector<T>& Copy);
        GTUVector(GTUVector<T>&& Move);
        GTUVector(std::initializer_list<T> myList); //initializer_list constructor
        ~GTUVector(){}
        
        bool empty() const; //Test whether container is empty
        int size() const; //Return container size
        void erase(GTUIterator<T>& object); //Erase element pointed by the given iterator
        void clear(); //Clear all content
        
        void add(const T& object); //add an element to the vector

        GTUIterator<T> begin(); //Return iterator to beginning
        GTUIterator<T> end(); //Return iterator to end
        GTUIteratorConst<T> cbegin() const; //Return a constant iterator to beginning
        GTUIteratorConst<T> cend() const; //Return a constant iterator to end

        //[] operator
        T& operator [](int index);       
    };
    
}


#endif //GTUVECTOR_H