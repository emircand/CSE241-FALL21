#ifndef GTUITERATORCONST_H
#define GTUITERATORCONST_H

#include <memory>


namespace emircand
{
    template <class T>
    class GTUIteratorConst
    {
        /*operators * -> ++ -- = ==*/
        public:
        GTUIteratorConst(T* object);
        ~GTUIteratorConst(){}

        GTUIteratorConst& operator ++();
        GTUIteratorConst operator ++(int);

        GTUIteratorConst& operator --();
        GTUIteratorConst operator --(int);

        GTUIteratorConst& operator=(const GTUIteratorConst& element);
        bool operator==(const GTUIteratorConst& element)const;
		bool operator!=(const GTUIteratorConst& element)const;


        T& operator*();
		T* operator->();

        private:
        T* _pointer;
    };
}

#endif