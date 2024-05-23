#pragma once

template <class T>
class Stack
{
private:
    // Maximum size of the Stack object
    int maxSize;
    // dynamic array of pointers to 
    // Template objects that stores the stack data
    T** stackData;
    // Top index that refers to the top element of the stack
    int top;

public:
    Stack(int maxSize);
    void push(T* value);
    int count();
    T* pop();
    T* peek();
    bool isEmpty();
    bool isFull();
};
template <class T>
Stack<T>::Stack(int maxSize)
{
    this->maxSize = maxSize;
    stackData = new T * [maxSize];
    // initialise top element to out of boundary
    top = -1;
}
template <class T>
int Stack<T>::count()
{
    // returns count of elements in stack
    return top + 1;
}
template <class T>
void Stack<T>::push(T* value)
{
    // increase top and add element at position
    stackData[++top] = value;
}
template <class T>
T* Stack<T>::pop()
{
    // return top element and decrease top variable
    return stackData[top--];
}

/*
* Return top element without popping it
*/
template <class T>
T* Stack<T>::peek()
{
    return stackData[top];
}
template <class T>
bool Stack<T>::isEmpty()
{
    return (top == -1);
}
template <class T>
bool Stack<T>::isFull()
{
    return (top == maxSize - 1);
}