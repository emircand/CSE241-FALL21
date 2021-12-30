#include "GTUIterator.h"

namespace emircand
{
    template <class T>
    GTUIterator<T>::GTUIterator(T* object)
    {
        _pointer = object;
    }

    template <class T>
    GTUIterator<T>::GTUIterator()
    {
        _pointer = NULL;
    }

    template <class T>
    GTUIterator<T>::GTUIterator(const GTUIterator<T>& other)
    {
        this->_pointer = other._pointer;
    }

    template <class T>
    GTUIterator<T>::GTUIterator(GTUIterator<T>&& other)
    {
        this->_pointer = other._pointer;
        delete [] other._pointer;
    }

    template<class T>
	GTUIterator<T>& GTUIterator<T>::operator=(const GTUIterator<T>& element){
		_pointer = element._pointer;
		return *this;
	}

    //pre-increment address of shared_ptr and move on the container
    template <class T>
    GTUIterator<T>& GTUIterator<T>::operator++()
    {
        ++_pointer;
        return *this;
    }

    //post-increment address of shared_ptr and move on the container
    template <class T>
    GTUIterator<T> GTUIterator<T>::operator++(int x)
    {
        GTUIterator tempObject = *this; //change rhs
        _pointer++;
        return tempObject;
    }

    //pre-decrement address of shared_ptr and move on the container
    template <class T>
    GTUIterator<T>& GTUIterator<T>::operator--()
    {
        --_pointer;
        return *this;
    }

    //post-decrement address of shared_ptr and move on the container
    template <class T>
    GTUIterator<T> GTUIterator<T>::operator--(int x)
    {
        GTUIterator tempObject = *this;
        _pointer--;
        return tempObject;
    }

    template<class T>
	T& GTUIterator<T>::operator*(){
		return *_pointer;
	}

	template<class T>
	T* GTUIterator<T>::operator->(){
		return _pointer;
	}

    /*boolean operator overloadings of GTUIterator class*/
    template<class T>
	bool GTUIterator<T>::operator==(const GTUIterator<T>& element) const
    {
		return (this->_pointer == element._pointer);
	}

	template<class T>
	bool GTUIterator<T>::operator!=(const GTUIterator<T>& element) const
    {
		return (this->_pointer != element._pointer);
	}

    
    template<class T>
	GTUIterator<T> operator-(const GTUIterator<T>& obj1, const GTUIterator<T>& obj2)
    {
        GTUIterator<T> newObj(obj1._pointer - obj2._pointer);
		return newObj;
	}
}