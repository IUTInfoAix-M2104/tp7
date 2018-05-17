#include <iostream>

using namespace std;

namespace {
    class ILessThanGen{
    public:
        virtual bool operator() (const& m1, const & m2) const = 0;
        virtual ~ILessThanGen(void) {}
    }; //ILessThanGen

    template <typename Iter_t, typename T>
    void selectSort (Iter_t deb, Iter_t fin,
                     const ILessThanGen <T> & isInf)
    {
        if (fin <= deb) return;

        for ( ; deb < fin - 1; ++deb)
        {
            Iter_t rgMin = deb;
            for (Iter_t j (deb + 1); j < fin; ++j)
                if (isInf (*j, *rgMin)) rgMin = j;
            swap (*deb, *rgMin);
        }

    } // selectSort()

    class Pers /* : public IEditable */{
        string   myNom;
        unsigned myAge;

      public :
        Pers (const string & nom, unsigned age)
              : myNom (nom), myAge (age) {}

        const string & getNom (void) const noexcept { return myNom; }
        unsigned       getAge (void) const noexcept { return myAge; }

      private :
        ostream & display (ostream & os)  const{
            return os << getAge () << " - " << getNom ();

        } // display()

      public :    // ajouté pour faciliter les essais

        friend ostream & operator << (ostream & os, const Pers & p){
            return p.display (os);
        }
    }   ; // Pers

    class TriParAgeAsc : public ILessThanGen{
    public:
        virtual bool operator () (const Pers & p1, Pers & p2) {return p1.getAge() < p2.getAge();}

    }; //TriParAgeAsc

    class TriParNomDesc : public ILessThanGen{
        bool operator () (const Pers & p1, Pers & p2) {return p1.getNom() > p2.getNom();}
    }; //TriParNomDesc


}
