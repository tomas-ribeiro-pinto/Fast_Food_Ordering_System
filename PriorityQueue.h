#pragma once
template <class T>
class PriorityQueue
{
    // size of queue
    int size;
    // current size of queue
    int currentSize;
    // dynamic array of pointers to 
    // Template objects that stores the queue data
    T** data;
    int count;

public:
    PriorityQueue() {};
    PriorityQueue(int size);
    ~PriorityQueue();
    void insert(T* item);
    T* remove();
    T* peakMin();
    bool isEmpty();
    bool isFull();
    int getSize();
    int getCurrentSize();
};

template <class T>
PriorityQueue<T>::PriorityQueue(int size) : size(size)
{
    // initialise dynamic array and other variables
    data = new T * [size];
    count = 0;
    currentSize = 0;
}
template <class T>
PriorityQueue<T>::~PriorityQueue()
{
}

/*
* Insert an element at correct position acording to priority Template object data
*/
template <class T>
void PriorityQueue<T>::insert(T* item)
{
    // if queue is empty, add item to first position
    if (count == 0)
    {
        currentSize++;
        data[count++] = item;
    }
    // else, find and shift items to correct position in queue using a modified bubble sorting algorithm
    else
    {
        int j;
        for (j = (count - 1); j >= 0; j--)
        {
            // compare values of items, if priority value of the inserted item is greater 
            // than the current position (value of local variable j) shift items until the whole queue
            // is correctly ordered in a crescent order according to priority value compared thorugh an operator overload
            if (*item > *data[j])
            {
                data[j + 1] = data[j];
            }
            // if inserted element priority value is not greater than the element at current position, break from the loop 
            else
            {
                break;
            }
        }

        // Insert item at the previous value of j where loop was broken and increase size of queue
        data[j + 1] = item;
        count++;
        currentSize++;
    }
}
template <class T>
T* PriorityQueue<T>::remove()
{
    // decrease currentSize
    currentSize--;
    return data[--count];
}

/*
* Return the first element of the queue
*/
template <class T>
T* PriorityQueue<T>::peakMin()
{
    return data[count - 1];
}
template <class T>
bool PriorityQueue<T>::isEmpty()
{
    return count == 0;
}
template <class T>
bool PriorityQueue<T>::isFull()
{
    return count == size;
}
template <class T>
int PriorityQueue<T>::getSize()
{
    return size;
}

template <class T>
int PriorityQueue<T>::getCurrentSize()
{
    return currentSize;
}