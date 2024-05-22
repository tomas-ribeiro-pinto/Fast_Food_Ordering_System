#pragma once
#include "iostream"

using namespace std;

template <class T>
class LinkedList
{
public:
    T* first;
    LinkedList();
    bool isEmpty();
    void insert(T* data);
    void display();
    T* find(T* search);
    T* remove(T* search);
    T* pop();
};

template <class T>
LinkedList<T>::LinkedList()
{
    first = 0;
}

template <class T>
bool LinkedList<T>::isEmpty()
{
    return (first == 0);
}

// Insert as copy
template <class T>
void LinkedList<T>::insert(T* item)
{
    item->next = first;
    first = item;
}

template <class T>
T* LinkedList<T>::find(T* search)
{
    T* current = first;
    while (current != 0)
    {
        if (*search == *current)
            return current;
        else
            current = current->next;
    }
    return 0;
}

template <class T>
T* LinkedList<T>::remove(T* search)
{
    T* current = first;
    T* previous = first;
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
    if (current == first)
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