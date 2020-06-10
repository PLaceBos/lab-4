#ifndef FULL_H_INCLUDED
#define FULL_H_INCLUDED

#include <iostream>

using namespace std;

template<typename T>
class Full
{
private:
    size_t size;
    size_t count;
    T * data;
public:
   Full();
    Full(size_t size);
    Full(const Full &f);
    ~Full();

   Full<T> & operator=(const Full<T> &f);

    bool pushBack(T value);
    bool pushFront(T value);
    void popBack(T value);
    void popFront(T value);
    void topBack(T &value) const;
    void topFront(T &value) const;
    void clear();
    bool isEmpty()const;
    size_t Size()const;
    void print() const;
};

template<typename T>
Full<T>::Full()
{
    size = 1;
    count = 0;
    data = new T[size];
}

template<typename T>
Full<T>::Full(size_t size)
{
    if(size < 1)
    {
        size = 1;
    }

    this->size = size;
    this->count = 0;
    this->data = new T[size];
}

template<typename T>
Full<T>::Full(const Full &f)
{
    this->size = f.size;
    this->count = f.count;
    this->data = new T[f.size];

    for(size_t i=0;i<f.count;i++)
    {
        this->data[i]=f.data[i];
    }
}

template<typename T>
Full<T>::~Full()
{
    if(data) delete [] data;
}

template<typename T>
Full<T> & Full<T>::operator=(const Full<T> &f)
{
    if(data) delete [] data;

    this->size = f.size;
    this->count = f.count;
    this->data = new T[f.size];

    for(size_t i=0;i<f.count;i++)
    {
        this->data[i]=f.data[i];
    }
}

template<typename T>
bool Full<T>::pushBack(T value)
{
    if(count < size)
    {
        data[count] = value;
        ++count;
        return true;
    }
    return false;

}


template<typename T>
bool Full<T>::pushFront(T value)
{
    int i;
    for (i=count;i>0; i--)
    {
      data[i]=data[i-1];
    }
    if(count < size)
    {

        data[0] = value;
        ++count;
        return true;
    }
    return false;

}



template<typename T>
void Full<T>::popFront(T value)
{

        data[0] = value;

}

template<typename T>
void Full<T>::popBack( T value)
{


        data[count-1] = value;

}

template<typename T>
void Full<T>::topFront(T &value) const
{

        value = data[0];

}

template<typename T>
void Full<T>::topBack(T &value) const
{

        value = data[count-1];

}


template<typename T>
void Full<T>::clear()
{
    count = 0;
}

template<typename T>
size_t Full<T>::Size()const
{
    return size;
}

template<typename T>
bool Full<T>::isEmpty()const
{
    return count == 0;
}

template<typename T>
void Full<T>::print() const
{
    cout << "Full size: " << size << ", count: " << count << endl;
    for(size_t i=0;i<count;i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}


#endif // FULL_H_INCLUDED
