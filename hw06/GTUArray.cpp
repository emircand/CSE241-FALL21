#include <iostream>
#include "GTUArray.h"

namespace emircand{

	template <class T, int N>
	GTUArray<T, N>::GTUArray ()
    {
        //automatically set size as N;
		this->Size = N;
		this->MaxSize = N;
        //create a memory in type of shared_ptr then assign it to ContainerPtr
		std::shared_ptr<T> temp(new T[this->MaxSize]);
		this->ContainerPtr = nullptr;
		this->ContainerPtr = temp;
	}

	template <class T, int N>
	GTUArray<T, N>::GTUArray(const GTUArray<T, N>& Copy)
	{
		this->Size = Copy.Size;
		this->MaxSize = Copy.MaxSize;
		this->ContainerPtr = Copy.ContainerPtr;
	}

	template <class T, int N>
	GTUArray<T, N>::GTUArray(GTUArray<T, N>&& Move)
	{
		this->Size = Move.Size;
		this->MaxSize = Move.MaxSize;
		this->ContainerPtr = Move.ContainerPtr;
	}

	template<class T, int N>
    GTUArray<T, N>::GTUArray(std::initializer_list<T> myList)
    {
        //automatically set size as 0;
		this->Size = 0;
        this->MaxSize = N;
        //container will return nullptr at first
		std::shared_ptr<T> temp(new T[this->MaxSize]);
		this->ContainerPtr = temp;
		//add all list to GTUArray
        for(auto i: myList)
            add(i);
    }


    /*
    test whether container is empty;
    if size equal to zero return true, else return false
    */
	template <class T, int N>
	bool GTUArray<T, N>::empty () const
    {
        bool flag = false;
        if(this->Size == 0)
            flag = true;
        
        return flag;
	}

    /*
    return container size
    */
	template <class T, int N>
	int GTUArray<T, N>::size () const
    {
		int result = 0;
		for (auto it = this->cbegin(); it != this->cend(); it++)
			if(it != nullptr)
				result++;
		return result;
	}

    /*
    add an element to GTUArray class
    */
	template <class T, int N>
	void GTUArray<T, N>::add (const T& element)
    {
		if(this->Size < this->MaxSize)
		{	
			*(this->end()) = element; //add element to the end of the container
            this->Size++; //increase size
			std::cout << element << " added to GTUArray\n";
		}
        else std::cout << "GTUArray is full; " << element << " couldn't added to GTUArray\n";
	}

	template <class T, int N>
	void GTUArray<T, N>::clear ()
    {
        std::cout << "GTUArray deleted...\n";
        this->Size = 0;
		this->MaxSize = N;
		std::shared_ptr<T> temp(new T[this->MaxSize]);
		this->ContainerPtr = temp;
	}

	template <class T, int N>
	void GTUArray<T, N>::erase (GTUIterator<T>& element) //this has to be changed with iterative type parameter
    {
        std::cout << "erase function called... the element " << *element << " will be deleted from GTUArray\n\n"; 
        bool flag = true;
		for(auto it = this->begin(); it != this->end() && flag == true; it++)
        {
			if((it) == element)
            {
				for(decltype(it) it_2 = it; it_2 != this->end();++it_2)
                    *(it_2) = *(it_2.getPtr()+1);
				this->Size--;
                flag = false;
			}
		}
        if(flag == true) 
           std::cout << "the element " << *element << " couldn't find in GTUArray\n";
	}

	template <class T, int N>
	GTUIterator<T> GTUArray<T, N>::begin ()
    {
		return (this->ContainerPtr).get(); //return address of container's first block
	}

	template <class T, int N>
	GTUIterator<T> GTUArray<T, N>::end ()
    {
		GTUIterator<T> it = (this->ContainerPtr).get();
		for(auto i = 0 ; i < this->Size ; i++)
			it++;
		return it; //return address of next to the container's last block
	}

    template <class T, int N>
	GTUIteratorConst<T> GTUArray<T, N>::cbegin () const
    {
		return (this->ContainerPtr).get(); //return address of container's first block
	}

	template <class T, int N>
	GTUIteratorConst<T> GTUArray<T, N>::cend () const
    {
		GTUIteratorConst<T> it = (this->ContainerPtr).get();
		for(auto i = 0 ; i < this->Size ; i++)
			it++;
		return it; //return address of next to the container's last block
	}


	template <class T, int N>
	T& GTUArray<T, N>::operator[](int index){
        GTUIteratorConst<T> it = this->cbegin();
        if(index > this->MaxSize)
        {
            std::cerr << "index value is out of bounds\nexiting..\n";
            exit(1);
        }
        int i = 0;
        while (i < index)
        {
            it++;
            i++;
        }
		return *it;
	}
}
