#include <iostream>
#include <algorithm>
#include "GTUSet.h"

namespace emircand
{
    template<class T>
    GTUSet<T>::GTUSet()
    {
        //automatically set size as 0;
		this->Size = 0;
        this->MaxSize = 64;
        //create a memory in type of shared_ptr then assign it to ContainerPtr
		std::shared_ptr<T> temp(new T[this->MaxSize]);
		this->ContainerPtr = temp;
    }

    template<class T>
    GTUSet<T>::GTUSet(const GTUSet<T>& Copy)
    {
        this->ContainerPtr = Copy.ContainerPtr;
        this->Size = Copy.Size;
        this->MaxSize = Copy.MaxSize; 
    }

    template <class T>
    GTUSet<T>::GTUSet(GTUSet<T>&& Move)
    {
        this->Size = Move.Size;
        this->MaxSize = Move.Size;
        this->ContainerPtr = Move.ContainerPtr;
    }

    template<class T>
    GTUSet<T>::GTUSet(std::initializer_list<T> myList)
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
	bool GTUSet<T>::empty () const
    {
        bool flag = false;
        if(this->Size == 0)
            flag = true;
        
        return flag;
	}

    /*return container size*/
	template <class T>
	int GTUSet<T>::size () const
    {
		return this->Size;
	}

     /*add an element to GTUSet class*/
	template <class T>
	void GTUSet<T>::add (const T& element)
    {
        bool flag = true;
        for(auto iterative = this->cbegin(); iterative != this->cend(); ++iterative)
        {
			if(*(iterative) == element)
            {
				std::cerr << element << " couldn't add to GTUSet; " << element << " is already in GTUSet container..\n";
                flag = false;
			}
		}
        if(flag == true)
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
            mySort();
            std::cout << element << " added to GTUSet container\n"; 
        }
        
	}

    /*clear all content*/
    template <class T>
	void GTUSet<T>::clear ()
    {
        std::cout << "GTUSet deleted...\n";
        this->Size = 0;
		this->MaxSize = 64;
		std::shared_ptr<T> temp(new T[this->MaxSize]);
		this->ContainerPtr = temp;
	}

    /*erase the element pointed by the given iterator*/
	template <class T>
	void GTUSet<T>::erase (GTUIterator<T>& element) //this has to be changed with iterative type parameter
    {
        std::cout << "erase function called... the element " << *element << " will be deleted from GTUSet\n\n"; 
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
           std::cout << "the element " << *element << " couldn't find in GTUSet\n";
	}

    template <class T>
	GTUIterator<T> GTUSet<T>::begin ()
    {
		return (this->ContainerPtr).get(); //return address of container's first block
	}

	template <class T>
	GTUIterator<T> GTUSet<T>::end ()
    {
		GTUIterator<T> tempIterator = (this->ContainerPtr).get();
		for(auto i = 0 ; i < this->Size ; i++)
			tempIterator++;
		return tempIterator; //return address of next to the container's last block
	}

    template <class T>
	GTUIteratorConst<T> GTUSet<T>::cbegin () const
    {
		return (this->ContainerPtr).get(); //return address of container's first block
	}

	template <class T>
	GTUIteratorConst<T> GTUSet<T>::cend () const
    {
		GTUIteratorConst<T> tempIterator = (this->ContainerPtr).get();
		for(auto i = 0 ; i < this->Size ; i++)
			tempIterator++;
		return tempIterator; //return address of next to the container's last block
	}

    /*operator= overloading for move assignment*/
    template <class T>
    GTUSet<T>& GTUSet<T>::operator=(GTUSet<T>&& Move)
    {
        this->MaxSize = Move.MaxSize;
        this->Size = Move.Size;
        std::shared_ptr<T> temp(new T[this->MaxSize]);
		this->ContainerPtr = temp;
        this->ContainerPtr = Move.ContainerPtr;
        return *this;
    }

    /*operator^ overloading for union operation*/
    template <class T>
    GTUSet<T> operator+(const GTUSet<T>& obj1, const GTUSet<T>& obj2)
    {
        GTUSet<T> newObj;
        for (auto it = obj1.cbegin(); it != obj1.cend(); it++)
            newObj.add(*it);
        for (auto it = obj2.cbegin(); it != obj2.cend(); it++)
            newObj.add(*it);
        return newObj;
    }

    /*operator^ overloading for intersection operation*/
    template <class T>
    GTUSet<T> operator^(const GTUSet<T>& obj1, const GTUSet<T>& obj2)
    {
        GTUSet<T> newObj;
        for (auto it = obj1.cbegin(); it != obj1.cend(); it++)
            for (auto it_2 = obj2.cbegin(); it_2 != obj2.cend(); it_2++)
                if(*(it_2) == *it)
                    newObj.add(*it);
        return newObj;
    }

    /*sort set elements*/
    template<class T>
    void GTUSet<T>::mySort()
    {
        for (auto it_1 = this->begin(); it_1 != this->end(); it_1++)
        {
            for (auto it_2 = it_1; it_2 != this->end(); it_2++)
            {
                if(*(it_1) > *(it_2))
                {
                    auto temp = *(it_1);
                    *(it_1) = *(it_2);
                    *(it_2) = temp;
                }  
            }
        }  
    }

    /*search T object in set*/
    template<class T>
    void GTUSet<T>::search(T element)
    {
        for (auto it_1 = this->begin(); it_1 != this->end(); it_1++)
            if(*(it_1) == element)
                std::cout << element << " found in set\n";
    }

    /*search T object in set and delete it from set*/
    template<class T>
    void GTUSet<T>::myDelete(T element)
    {
        bool flag = true;
        for (auto it_1 = this->begin(); it_1 != this->end() && flag == true; it_1++)
        {
            if(*(it_1) == element)
            {
                this->erase(it_1);
                std::cout << element << " deleted from GTUSet\n";
            }
        }
    }
    template<class T>
    void GTUSet<T>::myIntersect(const GTUSet<T>& object1, const GTUSet<T>& object2)
    {
        *this = object1 ^ object2;

        std::cout << "intersection set: ";

        for(auto it : *this)
            std::cout << it << " ";

        std::cout << "\n";
    }

    template<class T>
    void GTUSet<T>::myUnion(const GTUSet<T>& object1, const GTUSet<T>& object2)
    {
        *this = object1 + object2;
        std::cout << "union set: ";
        for(auto it : *this)
            std::cout << "- "<< it << " ";

        std::cout << "\n";
    }
}