//
//  main.cpp
//  Multiset
//
//  Created by Ravi Jayanthi on 1/22/15.
//  Copyright (c) 2015 Ravi Jayanthi. All rights reserved.
//

#include "Multiset.h"
#include <iostream>
#include <cassert>
using namespace std;


//// Test cases for unsigned longs
//int main ()
//{
//     //Tests I wrote for all member functions of Multiset
//    Multiset spade;
//    assert(spade.empty());
//    assert(spade.size() == 0);
//    spade.insert(999);
//    spade.insert(999);
//    spade.insert(34);
//    spade.insert(50);
//    spade.insert(4);
//    spade.insert(24);
//    spade.insert(0);
//    spade.insert(50);
//    spade.insert(34);
//    assert(spade.contains(0));
//    assert(spade.contains(4));
//    assert(spade.size() == 9);
//    assert(spade.uniqueSize() == 6);
//    assert(spade.erase(34) == 1);
//    assert(spade.erase(57) == 0);
//    assert(spade.eraseAll(999) == 2);
//    assert(spade.count(999) == 0);
//    assert(spade.size() == 6);
//    assert(spade.uniqueSize() == 5);
//    assert(spade.count(50) == 2);
//    assert(spade.count(24) == 1);
//    
//    // Provided code tests if swap functions correctly
//    Multiset ms1;
//    ms1.insert(240);
//    ms1.insert(240);
//    ms1.insert(240);
//    ms1.insert(490);
//    Multiset ms2;
//    ms2.insert(510);
//    ms2.insert(240);
//    ms2.insert(890);
//    ms1.swap(ms2);  // exchange contents of ms1 and ms2
//    assert(ms1.size() == 3  &&  ms1.count(510) == 1  &&
//           ms1.count(240) == 1  &&  ms1.count(890) == 1);
//    assert(ms2.size() == 4  &&  ms2.count(240) == 3  &&
//           ms2.count(490) == 1);
//    
//    // Provided code tests if get functions correctly
//    Multiset ms;
//    assert(ms.empty());
//    unsigned long x = 999;
//    assert(ms.get(0, x) == 0  &&  x == 999);  // x unchanged by get failure
//    assert( ! ms.contains(42));
//    ms.insert(42);
//    ms.insert(42);
//    assert(ms.size() == 2  &&  ms.uniqueSize() == 1);
//    assert(ms.get(1, x) == 0  &&  x == 999);  // x unchanged by get failure
//    assert(ms.get(0, x) == 2  &&  x == 42);
//    
//    // Tests I wrote to test the copy constructor and assignment operator
//    //Multiset clover(spade);
//    //clover = ms;
//    
//    // Smallberg tests for #5
//    Multiset a;   // a can hold at most 1000 distinct items
//    Multiset b;      // b can hold at most 5 distinct items
//    Multiset c;         // c can hold at most DEFAULT_MAX_ITEMS distinct items
//    ItemType v[6] = { 1, 2, 3, 4, 5 };
//    // No failures inserting 5 distinct items twice each into b
//    for (int k = 0; k < 5; k++)
//    {
//        assert(b.insert(v[k]));
//        assert(b.insert(v[k]));
//    }
//    assert(b.size() == 10  &&  b.uniqueSize() == 5  &&  b.count(v[0]) == 2);
//    
//    // When two Multisets' contents are swapped, their capacities are swapped
//    // as well:
//    a.swap(b);
//    assert(a.size() == 10  &&  a.uniqueSize() == 5  &&  a.count(v[0]) == 2);
//    
//    
//    for (int i = 0; i < b.uniqueSize(); i++)
//    {
//        ItemType x;
//        int n = b.get(i, x);
//        for (int j = 0; j < n; j++)
//        {
//            cout << x << endl;
//        }
//        
//    }
//    // Code to use to check if your own code is printing properly
//    
//    cout << "Multiset tests passed!" << endl;
//}



//int main ()
//{
////    Multiset ms1;
////    assert(ms1.insert(2));
////    assert(ms1.insert(2));
////    assert(ms1.insert(2));
////    assert(ms1.insert(8));
////    assert(ms1.insert(3));
////    assert(ms1.insert(3));
////    assert(ms1.insert(9));
////    assert(ms1.insert(5));
////    Multiset ms2;
////    assert(ms2.insert(6));
////    assert(ms2.insert(3));
////    assert(ms2.insert(8));
////    assert(ms2.insert(8));
////    assert(ms2.insert(5));
////    assert(ms2.insert(10));
////    assert(ms2.erase(6));
////    Multiset ms3;
////    subtract(ms1, ms2, ms3);
////    assert(ms3.count(3) == 1);
////    
////    cout << "All tests passed" << endl;
//    // Test for assignment operator by switching ms3 with ms1 in the above lines
//    
////    Multiset ms1;
////    assert(ms1.insert(2));
////    assert(ms1.insert(2));
////    assert(ms1.insert(2));
////    assert(ms1.insert(8));
////    assert(ms1.insert(3));
////    assert(ms1.insert(3));
////    assert(ms1.insert(9));
////    assert(ms1.insert(5));
////    Multiset ms2;
////    assert(ms2.insert(6));
////    assert(ms2.insert(3));
////    assert(ms2.insert(8));
////    assert(ms2.insert(8));
////    assert(ms2.insert(5));
////    assert(ms2.insert(10));
////    Multiset ms3;
////    subtract(ms1, ms2, ms3);
////    assert(ms3.count(3) == 1);
////    
////    Multiset* swag = new Multiset(ms1);
////    delete swag;
////    if(true)
////    {
////        Multiset swag = ms1;
////    }
////    assert (ms1.count(2) == 3);
////    
////    cout << "All tests passed" << endl;
//    // Random test for copy constructor - mark
//    
////    Multiset kobe;
////    assert(kobe.insert(1));
////    assert(kobe.insert(1));
////    assert(kobe.insert(2));
////    assert(kobe.insert(3));
////    assert(kobe.insert(4));
////    assert(kobe.insert(4));
////    assert(kobe.insert(4));
////    
////    Multiset* swaggy = new Multiset(kobe);
////    delete swaggy;
////    if(true)
////    {
////        Multiset swaggy = kobe;
////    }
////    assert(swaggy->count(1)==2);
////    assert(swaggy->count(2)==1);
////    assert(swaggy->count(3)==1);
////    assert(swaggy->count(4)==3);
////    
////    cout << "PASS COPY CONSTRUCTOR" << endl;
//    // Test for copy constructor 
//}






