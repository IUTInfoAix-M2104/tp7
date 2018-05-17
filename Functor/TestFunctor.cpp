/**
 *
 * @file   TestFunctor.cpp
 *
 * @authors M. Laporte, D. Mathieu
 *
 * @date    27/04/2010
 *
 * @version V1.0
 *
 * @brief   Premier functor
 *
 **/
#include <iostream>
#include <string>
#include <cctype>               // tolower(), toupper()
#include <cassert>

using namespace std;

namespace
{
    class ToLower
    {
    public :
        virtual ~ToLower (void) {}
        virtual int operator () (int val) const { return tolower(val); }

    }; // ToLower

    typedef int (* fctInt2Int_t) (int);
    string & moulinette (string & str, const ToLower & transf)
    {
        for (string::size_type i (str.size ()); i--; )
            str [i] = transf (str [i]);

        return str;

    } // moulinette()

    void testFunctor (void)
    {
        cout << "Functor : ";

        string ligne  ("AZECv qrgWSg wrV  wfdgWFDHG  wdfGWXCV");
        string minusc ("azecv qrgwsg wrv  wfdgwfdhg  wdfgwxcv");

        ToLower myLower;
        assert (minusc == moulinette (ligne, myLower));

        cout << "OK\n";

    } // testFunctor()

} // namespace anonyme

int main (void)
{
    /*      */    testFunctor ();     /*           */

    return 0;

} // main()
