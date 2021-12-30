#include "GTUIteratorConst.h"

namespace emircand
{
    template <class T>
    GTUIteratorConst<T>::GTUIteratorConst(T* object)
    {
        _pointer = object;
    }

    template<class T>
	GTUIteratorConst<T>& GTUIteratorConst<T>::operator=(const GTUIteratorConst<T>& element)
    {
		_pointer = element._pointer;
		return *this;
	}

    //pre-increment address of shared_ptr and move on the container
    template <class T>
    GTUIteratorConst<T>& GTUIteratorConst<T>::operator++()
    {
        ++_pointer;
        return *this;
    }

    //post-increment address of shared_ptr and move on the container
    template <class T>
    GTUIteratorConst<T> GTUIteratorConst<T>::operator++(int x)
    {
        GTUIteratorConst tempObject = *this; //change rhs
        _pointer++;
        return tempObject;
    }

    //pre-decrement address of shared_ptr and move on the container
    template <class T>
    GTUIteratorConst<T>& GTUIteratorConst<T>::operator--()
    {
        --_pointer;
        return *this;
    }

    //post-decrement address of shared_ptr and move on the container
    template <class T>
    GTUIteratorConst<T> GTUIteratorConst<T>::operator--(int x)
    {
        GTUIteratorConst tempObject = *this;
        _pointer--;
        return tempObject;
    }

    template<class T>
	T& GTUIteratorConst<T>::operator*()
    {
		return *_pointer;
	}

	template<class T>
	T* GTUIteratorConst<T>::operator->()
    {
		return _pointer;
	}

    /*boolean operator overloadings of GTUIteratorConst class*/
    template<class T>
	bool GTUIteratorConst<T>::operator==(const GTUIteratorConst<T>& element) const
    {
		return (this->_pointer == element._pointer);
	}

	template<class T>
	bool GTUIteratorConst<T>::operator!=(const GTUIteratorConst<T>& element) const
    {
		return (this->_pointer != element._pointer);
	}
}