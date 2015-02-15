//
//  Multiset.h
//  Multiset
//
//  Created by Ravi Jayanthi on 1/22/15.
//  Copyright (c) 2015 Ravi Jayanthi. All rights reserved.
//

#ifndef __Multiset__Multiset__
#define __Multiset__Multiset__

#include <stdio.h>
#include <string>

using namespace std;

typedef string ItemType;

class Multiset
{
public:
    Multiset();
    // Constructor. Create an empty multiset.
    
    ~Multiset();
    // Destructor. Clear up memory.
    
    Multiset(const Multiset& other);
    // Copy constructor
    
    Multiset& operator=(const Multiset& src);
    // Assignment operator
    
    bool empty() const;
    // Return true if the multiset is empty, otherwise false.
    
    int size() const;
    // Return the number of items in the multiset.  For example, the size
    // of a multiset containing "cumin", "cumin", "cumin", "turmeric" is 4.
    
    int uniqueSize() const;
    // Return the number of distinct items in the multiset.  For example,
    // the uniqueSize of a multiset containing "cumin", "cumin", "cumin",
    // "turmeric" is 2.
    
    bool insert(const ItemType& value);
    // Insert value into the multiset.  Return true if the value was
    // actually inserted.  Return false if the value was not inserted
    // (perhaps because the multiset has a fixed capacity and is full).
    
    int erase(const ItemType& value);
    // Remove one instance of value from the multiset if present.
    // Return the number of instances removed, which will be 1 or 0.
    
    int eraseAll(const ItemType& value);
    // Remove all instances of value from the multiset if present.
    // Return the number of instances removed.
    
    bool contains(const ItemType& value) const;
    // Return true if the value is in the multiset, otherwise false.
    
    int count(const ItemType& value) const;
    // Return the number of instances of value in the multiset.
    
    int get(int i, ItemType& value) const;;
    // If 0 <= i < uniqueSize(), copy into value an item in the multiset
    // and return the number of instances of that item in the multiset.
    // Otherwise, leave value unchanged and return 0.
    
    void swap(Multiset& other);
    // Exchange the contents of this multiset with the other one.
    
private:
    
    // Since this structure is used only by the implementation of the
    // Multiset class, we'll make it private to Multiset.
    struct Node
    {
        ItemType item;
        int      itemCount;
        Node* next;
        Node* previous;
    };
    
    int nodeCount;
    Node* head;
};


void combine(const Multiset& ms1, const Multiset& ms2, Multiset& result);

void subtract(const Multiset& ms1, const Multiset& ms2, Multiset& result);
// These are both non-member functions that can manipulate Multisets


#endif /* defined(__Multiset__Multiset__) */
