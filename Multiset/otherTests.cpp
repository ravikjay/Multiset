//
//  otherTests.cpp
//  Multiset
//
//  Created by Ravi Jayanthi on 1/24/15.
//  Copyright (c) 2015 Ravi Jayanthi. All rights reserved.
//

#include "Multiset.h"
#include <iostream>
#include <cassert>

using namespace std;


//for (int i = 0; i < spade.uniqueSize(); i++)
//{
//    ItemType x;
//    int n = spade.get(i, x);
//    for (int j = 0; j < n; j++)
//    {
//        cout << x << endl;
//        }
//        
//        }
//        
//        cout << "---" << endl;
// Use this loop to print out the Multiset when debugging
// Conveniently, this also tests the get method & and the uniqueSize

void basicMemberFunctionTest ()
{
    Multiset spade;
    assert(spade.empty());
    assert(spade.size() == 0);
    
    spade.insert("red");
    spade.insert("blue");
    spade.insert("green");
    spade.insert("red");
    spade.insert("yellow");
    spade.insert("blue");
    spade.insert("red");
    spade.insert("green");
    spade.insert("");
    
    assert(spade.contains("red"));
    assert(!spade.contains("purple"));
    assert(spade.size() == 9);
    assert(spade.uniqueSize() == 5);
    assert(spade.count("red") == 3);
    assert(spade.count("yellow") == 1);
    assert(spade.erase("") == 1);
    assert(spade.erase("green") == 1);
    assert(spade.erase("purple") == 0);
    assert(spade.size() == 7);
    assert(spade.uniqueSize() == 4);
    assert(spade.count("green") == 1);
    assert(spade.eraseAll("blue") == 2);
    assert(spade.erase("red") == 1);
    assert(spade.size() == 4);
    assert(spade.uniqueSize() == 3);
    assert(spade.count("blue") == 0);

    spade.insert("black");
    
    assert(spade.contains("black"));
    assert(spade.size() == 5);
    assert(spade.uniqueSize() == 4);
    assert(spade.eraseAll("red") == 2);
    assert(spade.eraseAll("green") == 1);
    assert(spade.size() == 2);
    assert(spade.uniqueSize() == 2);
}

void swapTest ()
{
    Multiset spade;
    spade.insert("red");
    spade.insert("red");
    spade.insert("blue");
    spade.insert("green");
    spade.insert("blue");
    spade.insert("");
    
    Multiset club;
    club.insert("pizza");
    club.insert("taco");
    club.insert("sushi");
    club.insert("pizza");
    
    spade.swap(club);
    
    assert(club.count("red") == 2);
    assert(club.count("blue") == 2);
    assert(club.count("green") == 1);
    assert(club.count("") == 1);
    assert(club.size() == 6);
    assert(club.uniqueSize() == 4);
    
    assert(spade.count("pizza") == 2);
    assert(spade.count("taco") == 1);
    assert(spade.count("sushi") == 1);
    assert(spade.size() == 4);
    assert(spade.uniqueSize() == 3); 
}


void copyConstructorTest ()
{
    Multiset spade;
    spade.insert("red");
    spade.insert("red");
    spade.insert("blue");
    spade.insert("green");
    spade.insert("blue");
    spade.insert("");
    
    Multiset club = spade;
    
    assert(club.count("red") == 2);
    assert(club.count("blue") == 2);
    assert(club.count("green") == 1);
    assert(club.count("") == 1);
    assert(club.size() == 6);
    assert(club.uniqueSize() == 4);
}

void assignmentOperatorTest ()
{
    Multiset spade;
    spade.insert("red");
    spade.insert("red");
    spade.insert("blue");
    spade.insert("green");
    spade.insert("blue");
    spade.insert("");
    
    Multiset club;
    club.insert("pizza");
    club.insert("taco");
    club.insert("sushi");
    club.insert("pizza");
    
    club = spade;
    
    assert(club.count("red") == 2);
    assert(club.count("blue") == 2);
    assert(club.count("green") == 1);
    assert(club.count("") == 1);
    assert(club.size() == 6);
    assert(club.uniqueSize() == 4);
}

void combineTest ()
{
    Multiset spade;
    spade.insert("red");
    spade.insert("red");
    spade.insert("blue");
    spade.insert("green");
    spade.insert("blue");
    spade.insert("");
    
    Multiset clover;
    clover.insert("red");
    clover.insert("blue");
    clover.insert("black");
    clover.insert("purple");
    clover.insert("purple");
    
    Multiset heart;
    combine(spade, clover, heart);
    
    assert(heart.count("red") == 3);
    assert(heart.count("blue") == 3);
    assert(heart.count("green") == 1);
    assert(heart.count("") == 1);
    assert(heart.count("black") == 1);
    assert(heart.count("purple") == 2);
    
    
    combine(spade, clover, spade);
    // Test for aliasing
    
    assert(spade.count("red") == 3);
    assert(spade.count("blue") == 3);
    assert(spade.count("green") == 1);
    assert(spade.count("") == 1);
    assert(spade.count("black") == 1);
    assert(spade.count("purple") == 2);
}

void subtractTest ()
{
    Multiset spade;
    spade.insert("red");
    spade.insert("red");
    spade.insert("blue");
    spade.insert("green");
    spade.insert("blue");
    spade.insert("red");
    
    Multiset clover;
    clover.insert("red");
    clover.insert("blue");
    clover.insert("blue");
    clover.insert("black");
    clover.insert("purple");
    clover.insert("purple");
    
    Multiset heart;
    subtract(spade, clover, heart);
    
    assert(heart.count("red") == 2);
    assert(heart.count("blue") == 0);       // All counts of blue should be gone
    //assert(heart.count("green") == 0);      // Green wasn't in both so it shouldn't be in the new Multiset either
    
    subtract(spade, clover, spade);
    
    assert(spade.count("red") == 2);
    assert(spade.count("blue") == 0);       // All counts of blue should be gone
    //assert(spade.count("green") == 0);      // Green wasn't in both so it shouldn't be in the new Multiset either
}

void bigTest ()
{
    basicMemberFunctionTest();
    swapTest();
    copyConstructorTest();
    assignmentOperatorTest();
    combineTest();
    subtractTest();
}
 //One large function that contains all void tester functions. Doing this keeps the main routuine clutter free

int main ()
{
    bigTest();
    cout << "All multiset tests passed!" << endl;
}

//int main ()
//{
//    Multiset s;
//    Multiset a;
//    
//    assert(s.empty()); // check to see if s set is empty
//    assert(a.empty()); // check to see if a set is empty
//    
//    unsigned long x = 9876543;
//    assert( !s.get(42,x)  &&  x == 9876543); // x unchanged by get failure
//    s.insert(123456789);
//    assert(s.size() == 1);
//    assert(s.get(0,x));
//    assert(x == 123456789);
//    s.erase(123456789); // erase 123456789
//    assert(!s.contains(123456789)); // check if it doesn't contain 123456789
//    assert(s.empty()); // check to see if the set is empty
//    s.insert(123);
//    assert(s.size() == 1); // check size = 1
//    s.insert(321);
//    assert(s.size() == 2); // check size = 2
//    s.insert(222);
//    assert(s.size() == 3); // check size = 3
//    assert(s.contains(123) && s.contains(222) && s.contains(321));
//    // check to see if all numbers are in the set
//    
//    a.insert(987); // add 987
//    a.insert(789); // add 789
//    
//    //check swap function
//    s.swap(a);
//    
//    unsigned long temp = 0;
//    a.get(2, temp);
//    assert(temp == 123); //check to see if temp was correctly changed
//    
//    assert(!a.get(50,temp)); // get failure
//    
//    assert(a.contains(123) && a.contains(222) && a.contains(321));
//    //check for correct swap
//    
//    assert(s.contains(789) && s.contains(987));//check for correct swap
//    
//    a.erase(321);
//    assert(a.contains(123)); // check to see if the set still contains 123
//    assert(!a.contains(321)); // check to see if the set doesn't contain 321
//    assert(a.contains(222)); // check to see if the set still contains 222
//    assert(a.size() == 2); // check the size = 2
//    
//    //copy constructor
//    Multiset b(a);
//    assert(a.contains(123)); // check to see if the set contains 123
//    assert(!a.contains(321)); // check to see if the set doesn't contain 321
//    assert(a.contains(222)); // check to see if the set contains 222
//    assert(a.size() == 2); // check the size = 2
//    
//    //test equal operator
//    b = s;
//    assert(b.contains(789) && b.contains(987));//check for correct operator
//    
//    //test out unite function
//    combine(s,a,b);
//    assert(s.contains(789) && s.contains(987));//check for correct unite
//    assert(a.contains(123)); // check to see if the set contains 123
//    assert(!a.contains(321)); // check to see if the set doesn't contain 321
//    assert(a.contains(222)); // check to see if the set contains 222
//    
//    Multiset c,d,e;
//    //add 1,2,3,4
//    c.insert(1);
//    c.insert(2);
//    c.insert(3);
//    c.insert(4);
//    
//    //add 3,4,5,6
//    d.insert(3);
//    d.insert(4);
//    d.insert(5);
//    d.insert(6);
//    
//    //subtract the two and make sure 3,4 are gone
//    subtract(c,d,e);
//    assert(e.contains(1) && e.contains(2));
//    
//    
//    //unite c and d and make sure it's only 1,2,5,6
//    combine(c,d,e);
//    assert(e.contains(1) && e.contains(2) && e.contains(5) && e.contains(6));
//    
//    //test out aliasing and make sure it's the same
//    combine(e,d,e);
//    assert(e.contains(1) && e.contains(2) && e.contains(5) && e.contains(6));
//    subtract(e,e,e);
//    assert(e.empty());
//    
//    cout << "Passed all tests" << endl;
//}
//// Tests found online to more thoroughly check my code for correctness




