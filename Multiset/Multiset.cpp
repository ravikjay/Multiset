//
//  Multiset.cpp
//  Multiset
//
//  Created by Ravi Jayanthi on 1/22/15.
//  Copyright (c) 2015 Ravi Jayanthi. All rights reserved.
//

#include "Multiset.h"

Multiset::Multiset()
{
    head = nullptr;
    nodeCount = 0;
}
// Create an empty multiset.

Multiset::~Multiset()
{
    Node *p;
    p = head;
    
    while (p != nullptr)
    {
        Node *n = p->next;
        delete p;
        p = n;
    }
    nodeCount = 0;
}
// Destructor. Free up memory

Multiset::Multiset(const Multiset& other)
{
    this->head = nullptr;
    
    nodeCount = other.nodeCount;
    Multiset* copyMulti = new Multiset;
    
    for (int i = 0; i < other.uniqueSize(); i++)
    {
        ItemType x;
        int n = other.get(i, x);
        
        for (int i = 0; i < n; i++)
        {
            copyMulti->insert(x);
        }
    }
    
    copyMulti->swap(*this);
    delete copyMulti;
}
// Copy constructor

Multiset& Multiset::operator=(const Multiset& src)
{
    if (this != &src){
        Multiset temp(src);
        swap(temp);
    }
    
    return (*this);
}
// Assignment operator

bool Multiset::empty() const
{
    if (head == nullptr){
        return true;
    }
    return false;
}
// Return true if the multiset is empty, otherwise false.

int Multiset::size() const
{
    Node *p;
    p = head;   // p points to the first node
    int counter = 0;    // Must be initialized to zero in case of an empty Multiset
    
    while (p != nullptr)
    {
        counter += p->itemCount;     // Tack on whatever the itemCount was for that Node object to the local variable counter
        p = p->next;
    }
    
    return counter;
}
// Return the number of items in the multiset.  For example, the size
// of a multiset containing "cumin", "cumin", "cumin", "turmeric" is 4.

int Multiset::uniqueSize() const
{
    Node *p;
    p = head;
    int counter = 0;        // Must be initialized for an empty Multiset
    
    while (p != nullptr)
    {
        if (p->itemCount > 0){
            counter++;       // For each valid Node object, increment the counter by only one
        }
        p = p->next;
    }
    return counter;
}
// Return the number of distinct items in the multiset.  For example,
// the uniqueSize of a multiset containing "cumin", "cumin", "cumin",
// "turmeric" is 2.

bool Multiset::insert(const ItemType& value)
{
    if (head == nullptr)
    {
        Node* hi = new Node;
        hi->item = value;
        hi->itemCount = 1;
        hi->next = nullptr;
        hi->previous = nullptr;
        head = hi;
        nodeCount++;
        return true;
    }
    
    Node *p;
    p = head;
    
    while (p != nullptr)
    {
        if (p->item == value){
            p->itemCount += 1;
            return true;
            // Only need to increment that Node's individual itemCount
        }
        p = p->next;
    }
    // This section is for traversing through the Multiset and adding a value if the value already exists

    p = new Node;
    nodeCount++;
    // Allocate a new Node and increment the member variable for total number of Nodes
    
    p->item = value;
    p->itemCount = 1;
    // Set the value and the Node's individual counter
    
    p->next = head;
    p->previous = nullptr;
    head->previous = p;
    // Set the two pointers for our newly allocated Node
    
    head = p;
    // Pointer housekeeping for the next Node
    
    return true;
}
// Insert value into the multiset. Return true always.

int Multiset::erase(const ItemType& value)
{
    if (head == nullptr){
        return 0;
    }
    // In case the Multiset is empty
    
    if (head->item == value && head->itemCount == 1){
        Node *killTarget = head;
        head = killTarget->next;
        delete killTarget;
        nodeCount--;
        return 1;
    }
    // If the head item is value and there is only one instance of it in the Node
    // Also in this case: nodeCount is decremented because the Node is deleted
    
    if (head->item == value && head->itemCount > 1){
        head->itemCount -= 1;
        return 1;
    }
    // If the head item is value and there are multiple instances of it in the Node
    
    Node* p;
    p = head;
    
    while (p != nullptr)
    {
        if (p->next != nullptr && p->next->item == value){
            //p = p->next;    // This is important so that p NOW points to the value we wish to manipulate
            break;
        }
        p = p->next;
    }
    // End the loop when the pointer is on the value you're looking for
    
    if (p != nullptr && p->next->itemCount == 1 && p->next != nullptr){
        Node *killTarget = p->next;
        p->next = killTarget->next;
        delete killTarget;
        nodeCount--;
        return 1;
    }
    // This scenario is if the target is NOT at the end of the Multiset
    
    if (p != nullptr && p->next->itemCount == 1){
        Node *killTarget = p->next;
        p->next = killTarget->next;
        killTarget->next->previous = p;
        delete killTarget;
        // The Node is actually deleted
        nodeCount--;
        return 1;
    }
    // If the target IS at the end of the Multiset
    
    if (p != nullptr && p->next->itemCount > 1){
        p = p->next;
        p->itemCount--;
        return 1;
    }
    // Here the Node has more than instance of item ocurring and thus the itemCount is decremented. The Node itself is NOT deleted
    
    return 0;
}
// Remove one instance of value from the multiset if present.
// Return the number of instances removed, which will be 1 or 0.

int Multiset::eraseAll(const ItemType& value)
{
    int counter = 0;
    if (head == nullptr){
        return 0;
    }
    // If the multiset is empty return out immediately
    
    if (head->item == value && head->itemCount >= 1){
        counter = head->itemCount;
        Node *killTarget = head;
        head = killTarget->next;
        delete killTarget;
        // Node is deleted
        head->previous = nullptr;
        nodeCount--;
        return counter;
    }
    // If the head pointer holds value
    
    Node* p;
    p = head;
    
    while (p != nullptr)
    {
        if (p->next != nullptr && p->next->item == value){
            break;
        }
        p = p->next;
    }
    // End the loop when the pointer is on the value you're looking for
    
    if (p != nullptr && p->next->itemCount >= 1){
        counter = p->next->itemCount;
        Node *killTarget = p->next;
        p->next = killTarget->next;
        p->previous = killTarget->previous;
        delete killTarget;
        // The Node is actually deleted
        nodeCount--;
        return counter;
    }
    // Use this section for deleting the actual Node the pointer is pointing to
    
    return 0;
}
// Remove all instances of value from the multiset if present.
// Return the number of instances removed.

bool Multiset::contains(const ItemType& value) const
{
    Node *p;
    p = head;
    
    while (p != nullptr)
    {
        if (p->item == value){
            return true;
        }
        p = p->next;
    }
    return false;
}
// Return true if the value is in the multiset, otherwise false.

int Multiset::count(const ItemType& value) const
{
    Node *p;
    p = head;
    int counter = 0;
    
    while (p != nullptr)
    {
        if (p->item == value){
            counter = p->itemCount;
        }
        p = p->next;
    }
    
    return counter;
}
// Return the number of instances of value in the multiset.

int Multiset::get(int i, ItemType& value) const
{
    Node *p;
    p = head;
    
    if (i >= 0 && i < uniqueSize())
    {
        for (int j = 0; j < i; j++){
            p = p->next;
        }
        
        value = p->item;
        return p->itemCount;
    }
    
    
    return 0;
}
// If 0 <= i < uniqueSize(), copy into value an item in the multiset
// and return the number of instances of that item in the multiset.
// Otherwise, leave value unchanged and return 0.

void Multiset::swap(Multiset& other)
{
    Node* p3;
    int temp;
    
    p3 = head;
    head = other.head;     // Dot operator because head is a (non-pointer) private member variable of Multiset, not the Node struct
    other.head = p3;
    
    temp = nodeCount;
    nodeCount = other.nodeCount;
    other.nodeCount = temp;
}
// Exchange the contents of this multiset with the other one.

void combine(const Multiset& ms1, const Multiset& ms2, Multiset& result)
{
    Multiset* combinedMulti = new Multiset;
    
    for (int i = 0; i < ms1.uniqueSize(); i++)
    {
        ItemType x;
        int n = ms1.get(i, x);
        
        for (int i = 0; i < n; i++)
        {
            combinedMulti->insert(x);
        }
    }
    // Loop traverses iterates through all values of ms1
    
    for (int i = 0; i < ms2.uniqueSize(); i++)
    {
        ItemType x;
        int n = ms2.get(i, x);
        
        for (int i = 0; i < n; i++)
        {
            combinedMulti->insert(x);
        }
    }
    // Loop traverses iterates through all values of ms2
    
    combinedMulti->swap(result);
    delete combinedMulti;

}

void subtract(const Multiset& ms1, const Multiset& ms2, Multiset& result)
{
    
    Multiset* combinedMulti = new Multiset;
    
    for (int i = 0; i < ms1.uniqueSize(); i++)
    {
        ItemType x;
        int n = ms1.get(i, x);
        
        for (int i = 0; i < n; i++)
        {
            combinedMulti->insert(x);
        }
    }
    // Loop traverses iterates through all values of ms1
    
    for (int i = 0; i < ms2.uniqueSize(); i++)
    {
        ItemType x;
        int n = ms2.get(i, x);
        
        for (int i = 0; i < n; i++)
        {
            combinedMulti->erase(x);
        }
    }
    // Loop traverses iterates through all values of ms2
    
    combinedMulti->swap(result);
    delete combinedMulti;

    
//    Multiset* combinedMulti = new Multiset;
//    ItemType x;
//    ItemType y;
//    
//    for (int i = 0; i < ms1.uniqueSize(); i++){
//        for (int j = 0; j < ms2.uniqueSize(); j++)
//        {
//            int n = ms1.get(i, x);
//            int m = ms2.get(j, y);
//            // Loop through both ms1 and ms2
//            
//            if (x == y){
//                if (n > m){
//                    int q = n- m;
//                    
//                    for (int w = 0; w < q; w++){
//                        combinedMulti->insert(x);
//                        // Doing this only ever inserts the values desired and only at the number of values its necessary for
//                    }
//                }
//            }
//            else{
//                combinedMulti->insert(x);
//            }
//            // If there are values in ms1 but not in ms2
//        }
//    }
//    
//    combinedMulti->swap(result);
//    delete combinedMulti;
    // This implementation works in theory, but I'm not sure about how to check for aliasing this way
    
}


