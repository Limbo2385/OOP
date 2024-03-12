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

    MySet(T* p)
    {
        Arr = p; 
    }



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

    bool count(T item) {
        for (int i = 0; i < size; i++) {
            if (Arr[i] == item) {
                return true;
            }
        }
        return false;
    }

    MySet& operator * (MySet& s)
    {
        int *p = NULL;
        MySet<T> Arr3{ p };
        //MySet<T> mySet3;

        for (int i = 0; i < size; i++) {
            for (int c = 0; c < s.getSize(); c++) {
                if (i == c && Arr3.count(i) == false) {
                    Arr3.insert(i);
                }
            }
        }
        Arr = Arr3;
        return *this;

    }

    MySet& operator- (T s)
    {
        erase(s);
        return *this;
    }

    bool operator < (MySet& s)
    {
        if (Arr.getSize() < s.Arr.getSize()) {
            return true;
        }
        return false;
    }

    void show() {
        for (int i=0; i<size; i++ )
        {
            cout << Arr[i] << " ";
        }
        cout << endl;
    };
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
    MySet<int> arr{p};

    int* p1 = {0};
    int* p2 = {0};
    int* p3 = {0};

    MySet<int> arr1{ p1 };
    MySet<int> arr2{ p2 };
    MySet<int> arr3{ p3 };

    for (int i = 0; i < 5; i++) {
        arr1.insert(i);
    };

    for (int i = 0; i < 5; i++) {
        arr2.insert(i);
    }

    for (int i = 0; i < 5; i++) {
        arr3.insert(i);
    }

    arr1 = arr1 - (4);
    arr1 = arr2 * arr3;
    arr1.show();
}