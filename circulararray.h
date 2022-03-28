#include <iostream>
using namespace std;

template <class T>
class CircularArray
{
private:
    T *array;
    int capacity;
    int back, front;
    
public:
    CircularArray();
    CircularArray(int _capacity);
    virtual ~CircularArray();
    void push_front(T data);
    void push_back(T data);
    void insert(T data, int pos);
    T pop_front();
    T pop_back();
    bool is_full();
    bool is_empty();
    int size();
    void clear();
    T &operator[](int);
    void sort();
    bool is_sorted();
    void reverse();
    string to_string(string sep=" ");

private:
    int next(int);
    int prev(int);
};

template <class T>
CircularArray<T>::CircularArray()
{
    CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}

template <class T>
CircularArray<T>::~CircularArray()
{
    delete[] array;
}

template <class T>
int CircularArray<T>::prev(int index)
{
    return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index)
{
    return (index + 1) % capacity;
}
template <class T>
void CircularArray<T>::push_front(T data)
{ 

   if (is_empty()){     
     if(front==0){       
           array[capacity-1]= data;
           front=capacity-1; 
        }
       else{
          array[front -1]= data;
          front--;
        }  
   }   
}

template <class T>
void CircularArray<T>::push_back(T data)
{
   if (is_empty()){
        if(back==capacity-1 ){       
          array[0]= data;
          back=0; 
        }
        else{
          array[back +1]= data;
          back++;
        }
   }
}

template <class T>
bool CircularArray<T>::is_full()
{
    if (size()== capacity){

        return true;
    }
}

template <class T>
bool CircularArray<T>::is_empty()
{

     
    if (size() < capacity ){

        return true;
    }
}

template <class T>
int CircularArray<T>::size()
{

    int size;
    if (back < front ){
    

     if (back +1 == front){
       size = capacity;
       cout<< size << endl;
       }
     else {
          size = capacity - (front - back - 1); 
           cout<< size << endl;
        }
    }

    else if(back == front){
    size = 1;
    cout<< size << endl;
    }
    
    else{
     size = back - front +1;
       cout<< size << endl;
    }

    return size;
}

template <class T>
string CircularArray<T>::to_string(string sep)
{
    string result = ""; 
    for (int i = 0; i < size(); i++)
        result += std::to_string((*this)[i]) + sep;
    return result;    
}
