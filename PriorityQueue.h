#pragma once
template <class T>
class PriorityQueue
{
    int size;
    int currentSize;
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
    data = new T * [size];
    count = 0;
    currentSize = 0;
}
template <class T>
PriorityQueue<T>::~PriorityQueue()
{
}
template <class T>
void PriorityQueue<T>::insert(T* item)
{
    if (count == 0)
    {
        currentSize++;
        data[count++] = item;
    }
    else
    {
        int j;
        for (j = (count - 1); j >= 0; j--)
        {
            if (*item > *data[j])
            {
                data[j + 1] = data[j];
            }
            else
            {
                break;
            }
        }
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