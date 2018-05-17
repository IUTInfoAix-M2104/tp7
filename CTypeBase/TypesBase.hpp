#ifndef TYPESBASE_HPP
#define TYPESBASE_HPP

namespace std{

    template <typename T>
    class TypeBase{
        T myVal;
    public:
        explicit TypeBase(const T & val) : myVal(val) {}
        operator T& (void) { return myVal; }

    };// TypeBase

    typedef TypeBase <short> Short;
    typedef TypeBase <int> Integer;
    typedef TypeBase <char> Character;
}

#endif // TYPESBASE_HPP
