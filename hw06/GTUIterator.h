#ifndef GTUITERATOR_H
#define GTUITERATOR_H

#include <memory>

namespace emircand
{
    template <class T>
    class GTUIterator
    {
        /*operators * -> ++ -- = ==*/
        public:
        GTUIterator();
        GTUIterator(const GTUIterator<T>& object);
        GTUIterator(T* object);
        GTUIterator(GTUIterator<T>&& object);
        ~GTUIterator(){}

        GTUIterator& operator ++();
        GTUIterator operator ++(int);

        GTUIterator& operator --();
        GTUIterator operator --(int);

        GTUIterator& operator=(const GTUIterator& element);
        bool operator==(const GTUIterator& element)const;
		bool operator!=(const GTUIterator& element)const;


        T& operator*();
		T* operator->();

        T* getPtr() const {return _pointer;}

        T* _pointer;
    };

}
#endif //GTUITERATOR_H