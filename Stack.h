#pragma once

template <class T>
class Stack
{
private:
    int maxSize;
    T** stackData;
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
    top = -1;
}
template <class T>
int Stack<T>::count()
{
    return top + 1;
}
template <class T>
void Stack<T>::push(T* value)
{
    stackData[++top] = value;
}
template <class T>
T* Stack<T>::pop()
{
    return stackData[top--];
}
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