#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
#include <vector>
#include <set>
using namespace std;

template <class T>
class Set {
private:
    set<T> mySet;
public:
    Set(set<T> mySet) {
        this->mySet = mySet;
    }

    Set& operator * ( Set& s) 
    {
        set<T> mySet3;
        
        for (T i : mySet) {
            for (T c : s.mySet) {
                if (i == c && mySet3.count(i) == 0) {
                    mySet3.insert(i);
                }
            }
        }
        mySet = mySet3;
        return *this;

    }

    Set& operator- (T s)
    {
        mySet.erase(s);
        return *this;
    }

    bool operator < (Set& s)
    {
        if (mySet.size() < s.mySet.size()) {
            return true;
        }
        return false;
    }

    void show() {
        for (T n : mySet)
        {
            cout << n << " ";
        }
        cout << endl;
    }
};

class PodobieSeta {

};

int main() {

    setlocale(LC_ALL, "rus");

    set<int> mySet1;
    set<int> mySet2;
    for (int i = 0; i < 5; i++) {
        mySet1.insert(i);
    };

    for (int i = 0; i < 5; i++) {
        mySet2.insert(i);
    }

    Set s(mySet1);
    Set s1(mySet2);
    Set s2(mySet1);
    s = s1 * s2;
    s = s - (4);
    s.show();

    if (s < s1) {
        cout << "текущее множество меньше";
    }
    else {
        cout << "текущее множество больше";
    }

    return 0;
};