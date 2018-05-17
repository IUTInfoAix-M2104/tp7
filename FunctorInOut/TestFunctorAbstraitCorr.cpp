/**
 *
 * @file    TestFunctorAbstraitCorr.cpp
 *
 * @authors M. Laporte
 *
 * @date    07/05/2018
 *
 * @version V1.0
 *
 * @brief   functor abstrait
 *
 **/
#include <iostream>
#include <string>
#include <cctype>               // ispunct(), islower(), isalpha()
                                // tolower(), toupper()
#include <cassert>

using namespace std;

namespace
{
    class ITraitCar
    {
        mutable unsigned myCpt;
      public :
        ITraitCar (void) : myCpt(0) {} //la valeur par default est automatique gérée par le compilateur
        virtual ~ITraitCar (void) {}
        virtual int operator () (int caract) = 0;
        unsigned getCpt(void) const {return myCpt;}
        void setCpt(unsigned cpt){myCpt = cpt;}

    }; // ITraitCar

    class ToLower  : public ITraitCar
    {
      public :
        virtual ~ToLower (void) {}
        virtual int operator () (int caract)  noexcept
        {
            if(isalpha(caract)) setCpt(getCpt()+1);

            return tolower (caract);

        } // operateur()

    }; // ToLower

    class ToUpper : public ITraitCar
    {
      public :
        virtual ~ToUpper (void) {}
        virtual int operator () (int caract)  noexcept
        {
            setCpt(getCpt()+1);
            if (islower(caract)) return toupper(caract);
            return toupper (caract);

        } // operateur()

    }; // ToUpper

    class IgnPunct : public ITraitCar
    {
      public :
        virtual ~IgnPunct (void) {}
        virtual int operator () (int caract)  noexcept
        {
            if (ispunct(caract)) setCpt(getCpt()+1);
            return ispunct (caract) ? ' ' : caract;

        } // operateur()

    }; // IgnPunct

    string & moulinette (string & str, ITraitCar & transf)
    {
        for (string::size_type i (str.size()); i--; )
            str [i] = transf (str [i]);

        return str;

    } // moulinette()

    void testFunctor (void)
    {
        cout << "Functor abstrait : ";

        string ligne     ("azert:;,.?GFDSQ");
        string minusc    ("azert:;,.?gfdsq");
        string majusc    ("AZERT:;,.?GFDSQ");
        string sansPunct ("AZERT     GFDSQ");

        ToLower myLower;
        ToUpper myUpper;
        IgnPunct myPunct;

        assert (minusc    == moulinette (ligne, myLower));
        assert (10 == myLower.getCpt());
        assert (majusc    == moulinette (ligne, myUpper));
        assert (10 == myUpper.getCpt());
        assert (sansPunct == moulinette (ligne, myPunct));
        assert (10 == myPunct.getCpt());



        cout << "OK\n";

    } // testFunctor()

} // namespace

int main (void)
{
    /*      */    testFunctor ();     /*           */

    return 0;

} // main()
