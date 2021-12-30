#include <iostream>
#include "GTUVector.h"

namespace emircand{

	template <class T>
	GTUVector<T>::GTUVector ()
    {
        //automatically set size as 0;
		this->Size = 0;
		this->MaxSize = 64;
        //container will return nullptr at first
		std::shared_ptr<T> temp(new T[this->MaxSize]);
		this->ContainerPtr = temp;
	}

	template <class T>
	GTUVector<T>::GTUVector(const GTUVector<T>& Copy)
	{
		this->Size = Copy.Size;
		this->MaxSize = Copy.MaxSize;
		this->ContainerPtr = Copy.ContainerPtr;
	}

	template <class T>
	GTUVector<T>::GTUVector(GTUVector<T>&& Move)
	{
		this->Size = Move.Size;
		this->MaxSize = Move.MaxSize;
		this->ContainerPtr = Move.ContainerPtr;
	}

	template<class T>
    GTUVector<T>::GTUVector(std::initializer_list<T> myList)
    {
        //automatically set size as 0;
		this->Size = 0;
        this->MaxSize = 64;
        //container will return nullptr at first
		std::shared_ptr<T> temp(new T[this->MaxSize]);
		this->ContainerPtr = temp;
        for(auto i: myList)
            add(i);
    }


    /*
    test whether container is empty;
    if size equal to zero return true, else return false
    */
	template <class T >
	bool GTUVector<T>::empty () const
    {
        bool flag = false;
        if(this->Size == 0)
            flag = true;
        
        return flag;
	}

    /*
    return container size
    */
	template <class T>
	int GTUVector<T>::size () const
    {
		return this->Size;
	}

    /*
    add an element to GTUVector class
    */
	template <class T>
	void GTUVector<T>::add (const T& element)
    {
		*(this->end()) = element;
        this->Size++;
		if(this->Size >= this->MaxSize)
		{	
			this->MaxSize = this->MaxSize + 64;
			std::shared_ptr<T> temp(new T[this->MaxSize]);
			int index = 0;
			for(auto it = this->begin() ; it != this->end();++it){
				temp.get()[index] = *(it);
				index++;
			}
			this->ContainerPtr = nullptr;
			this->ContainerPtr = temp;
		}
        std::cout << element << " added to GTUVector\n";
	}

	template <class T>
	void GTUVector<T>::clear ()
    {
        std::cout << "GTUVector deleted...\n";
        this->Size = 0;
		this->MaxSize = 64;
		std::shared_ptr<T> temp(new T[this->MaxSize]);
		this->ContainerPtr = temp;
	}

	template <class T>
	void GTUVector<T>::erase (GTUIterator<T>& element) //this has to be changed with iterative type parameter
    {
        std::cout << "erase function called... the element " << *element << " will be deleted from GTUVector\n\n"; 
        bool flag = true;
		for(auto tempIterator = this->begin(); tempIterator != this->end() && flag == true; tempIterator++)
        {
			if((tempIterator) == element)
            {
				for(decltype(tempIterator) tempIterator_2 = tempIterator; tempIterator_2 != this->end();++tempIterator_2)
                    *(tempIterator_2) = *(tempIterator_2.getPtr()+1);
				this->Size--;
                flag = false;
			}
		}
        if(flag == true) 
           std::cout << "the element " << *element << " couldn't find in GTUVector\n";
	}

	template <class T>
	GTUIterator<T> GTUVector<T>::begin ()
    {
		return (this->ContainerPtr).get();
	}

	template <class T>
	GTUIterator<T> GTUVector<T>::end ()
    {
		GTUIterator<T> tempIterator = (this->ContainerPtr).get();

		for(auto i = 0 ; i < this->Size ; i++)
			tempIterator++;

		return tempIterator;
	}

    template <class T>
	GTUIteratorConst<T> GTUVector<T>::cbegin () const
    {
		return (this->ContainerPtr).get();
	}

	template <class T>
	GTUIteratorConst<T> GTUVector<T>::cend () const
    {
		GTUIteratorConst<T> tempIterator = (this->ContainerPtr).get();

		for(auto i = 0 ; i < this->Size ; i++)
			tempIterator++;

		return tempIterator;
	}


	template <class T>
	T& GTUVector<T>::operator[](int index){
        GTUIteratorConst<T> tempIterator = this->cbegin();
        if(index > this->size())
        {
            std::cerr << "index value is out of bounds\nexiting..\n";
            exit(1);
        }
        int i = 0;
        while (i < index)
        {
            tempIterator++;
            i++;
        }
		return *tempIterator;
	}
}
