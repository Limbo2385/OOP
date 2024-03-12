#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

template <class T = int>
class MySet
{
private:
    int size = 0;
    T* Arr = NULL;
public:
    MySet() {}

    MySet(T* p)
    {
        Arr = p; 
    }

    void setArr(T* p) { Arr = p; }

    void insert(T item)
    {
        if (size == 0)
        {
            size = 1;
            Arr = new T[size];
            Arr[0] = item;
        }
        else
        {
            size++;
            T* Arrey = new T[size];

            for (size_t i = 0; i < size - 1; i++)
            {
                Arrey[i] = Arr[i];
            }

            delete[] Arr;
            Arr = Arrey;
        }
    }

    void erase(T item)
    {
        size--;
        T* Arrey = new T[size];

        for (size_t i = 0; i < size; i++)
        {
            if (Arr[i] == item)
                Arrey[i] = Arr[i + 1];
            else
                Arrey[i] = Arr[i];
        }

        delete[] Arr;
        Arr = Arrey;
    }

    int getSize() { return size; }

};

//class MySet
//{
//private:
//    int size = 0;
//    int* Arr;
//public:
//    MySet() {}
//
//    MySet(int* p)
//    {
//        Arr = p;
//    }
//
//    void insert(int item)
//    {
//        if (size == 0)
//        {
//            size = 1;
//            Arr = new int[size];
//            Arr[0] = item;
//        }
//        else
//        {
//            size++;
//            int* Arrey = new int[size];
//
//            for (size_t i = 0; i < size - 1; i++)
//            {
//                Arrey[i] = Arr[i];
//            }
//
//            delete[] Arr;
//            Arr = Arrey;
//        }
//    }
//
//    void erase(int item)
//    {
//        size--;
//        int* Arrey = new int[size];
//
//        for (size_t i = 0; i < size; i++)
//        {
//            if (Arr[i] == item)
//                Arrey[i] = Arr[i + 1];
//            else
//                Arrey[i] = Arr[i];
//        }
//
//        delete[] Arr;
//        Arr = Arrey;
//    }
//
//    int getSize() { return size; }
//
//};

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int* p = NULL;
    MySet arr{p};
}