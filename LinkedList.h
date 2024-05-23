#pragma once
#include "iostream"

using namespace std;

template <class T>
class LinkedList
{
public:
    // Pointer to the first element of the linked list
    T* first;
    LinkedList();
    bool isEmpty();
    void insert(T* data);
    T* find(T* search);
    T* remove(T* search);
    T* pop();
};

template <class T>
LinkedList<T>::LinkedList()
{
    // initialise first element to zero
    first = 0;
}

template <class T>
bool LinkedList<T>::isEmpty()
{
    return (first == 0);
}

// Insert the item in the linked list and assign it the first position of the linked list
// This data structure operates in a LIFO order
template <class T>
void LinkedList<T>::insert(T* item)
{
    // the inserted item points to the curent first element
    item->next = first;
    // the inserted item is assigned the first position in the data structure
    first = item;
}

/*
* Find if a an item is present in the list
* Time complexity is O(n) as it is required to check every record of the list in the worst case
*/
template <class T>
T* LinkedList<T>::find(T* search)
{
    T* current = first;
    while (current != 0)
    {
        if (*search == *current)
            return current;
        // move to the next element of the list if current element is not equal to the search
        else
            current = current->next;
    }

    // if element is not found return zero
    return 0;
}

template <class T>
T* LinkedList<T>::remove(T* search)
{
    T* current = first;
    T* previous = first;

    // search element to remove
    while (*current != *search)
    {
        if (current->next == 0)
            return 0;
        else
        {
            previous = current;
            current = current->next;
        }
    }

    // When element is found, remove it by setting the 
    // next value of the previous to the next element of the removed element, 
    // and then return removed element
    if (current == first)
        // element to remove is the first of the list
        // so there's no need to set th eprevious element as this does not exist
        first = first->next;
    else
        previous->next = current->next;

    return current;
}

template <class T>
T* LinkedList<T>::pop()
{
    if (isEmpty())
        return 0;
    T* temp = first;
    first = first->next;
    return temp;
}