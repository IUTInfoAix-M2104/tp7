/**
 *
 * @file     TestTypesBase.cpp
 *
 * @authors  M. Laporte
 *
 * @date     07/05/2018
 *
 * @version  V2.0
 *
 **/
#include <iostream>
#include <cassert>

#include "TypesBase.hpp"        // Character

using namespace std;
#define classdef typedef

namespace
{
    void testTypesBase (void)
    {
        cout << "TestTypesBase : ";

        // Verification de l'arithmetique des entiers avec la classe
        //   Short

        Short s1 (12), s2 (34);
        assert (s1 == 12);
        assert (s2 == 34);
        assert ((s1 + s2) == 46);
        assert (s1++ == 12);
        assert (++s1 == 14);

        cout << "OK\n";

        // Verification du fonctionnement de l'injecteur

        cout << "Saisir un Short : ";
        cin >> s1;

        cout << "s1 = " << s1 << endl;

    }// testTypesBase ()

} // namespace

int main ()
{
    testTypesBase();    // Attention : exception bad_alloc possible ...

    return 0;

} // main()
