#include "circulararray.h"

template <typename T>
class QueueArray : public CircularArray<T> { 

                   public:
                   QueueArray(int _capacity);    
                   virtual ~QueueArray();     
                   void display(); 
                   void push(T data);
                   T pop();

    
};

template <typename T>
QueueArray<T>::QueueArray(int _capacity):CircularArray<T>(_capacity){}
template <typename T>
QueueArray<T>::~QueueArray(){
CircularArray<T>::clear();
}

template <typename T>
void QueueArray<T>::display()
{
    
    CircularArray<T>::to_string();
}
template <typename T>
void QueueArray<T>::push(T data)
{
    
    CircularArray<T>::push_back(data);
}
template <typename T>
T QueueArray<T>::pop()
{
    
    return CircularArray<T>::pop_front();
}