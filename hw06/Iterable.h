#ifndef ITERABLE_H
#define ITERABLE_H

#include <iostream>
#include <memory>
#include <initializer_list>

#include "GTUIterator.h"
#include "GTUIteratorConst.h"

#include "GTUIterator.cpp"
#include "GTUIteratorConst.cpp"


namespace emircand
{
    template <class T>
    class Iterable
    {
        public:

        virtual bool empty() const = 0; //Test whether container is empty
        virtual int size() const = 0; //Return container size
        virtual void erase(GTUIterator<T>& object) = 0; //Erase element pointed by the given iterator
        virtual void clear() = 0; //Clear all content

        virtual GTUIterator<T> begin() = 0; //Return iterator to the beginning of container
        virtual GTUIterator<T> end() = 0; //Return iterator to the ending of container
        virtual GTUIteratorConst<T> cbegin() const = 0; //Return const_iterator to the beginning of container
        virtual GTUIteratorConst<T> cend() const = 0; //Return const_iterator to the ending of container

        protected:
        std::shared_ptr<T> ContainerPtr;
        size_t Size;
        size_t MaxSize;

    };
    
}


#endif //ITERABLE_H