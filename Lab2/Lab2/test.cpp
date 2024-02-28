#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
using namespace std;

class Train;

class Observer {
private:
    string destination;
    int number;
    int time;
    int mainCount;
    int kupeCount;
    int plackartCount;
public:
    Observer(string destination, int number, int time, int mainCount, int kupeCount, int plackartCount)
    {
        this->destination = destination;
        this->number = number;
        this->time = time;
        this->mainCount = mainCount;
        this->kupeCount = kupeCount;
        this->plackartCount = plackartCount;
    }
    Observer(const Observer& t)
    {
        this->destination = t.destination;
        this->number = t.number;
        this->time = t.time;
        this->mainCount = t.mainCount;
        this->kupeCount = t.kupeCount;
        this->plackartCount = t.plackartCount;
    }

    ~Observer()
    {

    }


    void GetInfo(const Train&);
};

class Train {
    friend void Observer::GetInfo(const Train&);
private:
    string destination;
    int number;
    int time;
    int mainCount;
    int kupeCount;
    int plackartCount;
public:
    Train(string destination, int number, int time, int mainCount, int kupeCount, int plackartCount)
    {
        this->destination = destination;
        this->number = number;
        this->time = time;
        this->mainCount = mainCount;
        this->kupeCount = kupeCount;
        this->plackartCount = plackartCount;
    }

    Train(const Train& t)
    {
        this->destination = t.destination;
        this->number = t.number;
        this->time = t.time;
        this->mainCount = t.mainCount;
        this->kupeCount = t.kupeCount;
        this->plackartCount = t.plackartCount;
    }

    ~Train()
    {

    }


    bool operator == (const Train& train) const {
        return mainCount == train.mainCount;
    }

    bool operator != (const Train& train) const {
        return mainCount != train.mainCount;
    }

    Train& operator++ () {
        number += 1;
        return *this;
    }

    Train operator++ (int) {
        Train copy{ *this };
        ++(*this);
        return copy;
    }

    Train& operator-- () {
        number -= 1;
        return *this;
    }

    Train operator-- (int) {
        Train copy{ *this };
        --(*this);
        return copy;
    }

    Train& operator = (const Train& train) {
        destination = train.destination;
        number = train.number;
        time = train.time;
        mainCount = train.mainCount;
        kupeCount = train.kupeCount;
        plackartCount = train.plackartCount;
        return *this;
    }

    void show() {
        cout << endl;
        cout << "�����: " << number << endl;
        cout << "����� ���������� ����: " << mainCount << endl;
    }

    string getDestination() { return destination; }
    int getTime() { return time; }
    int getMainCount() { return mainCount; }
    int getNumber() { return number; }
    int getKupeCount() { return kupeCount; }
    int getPupeCount() { return plackartCount; }


    string setDestination(string destination) {
        this->destination = destination;
    }
    int setTime(int time) {
        this->time = time;
    }
    int setMainCount(int mainCount) {
        this->mainCount = mainCount;
    }
    int setNumber(int number) {
        this->number = number;
    }
    int setKupeCount(int kupeCount) {
        this->kupeCount = kupeCount;
    }
    int setPupeCount(int plackartCount) {
        this->plackartCount = plackartCount;
    }
};


void Observer::GetInfo(const Train& trainer) {
    cout << "�����: " << trainer.number << " ���������� ����: " << trainer.mainCount << endl;
}


int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    string destination = "1";
    int number = 1;
    int time = 1;
    int mainCount = 1;
    int kupeCount = 1;
    int plackartCount = 1;

    vector<Train> v1; // ������ �������

    for (size_t i = 0; i < 2; i++)
    {
        cout << "������� ������ � ������ " << i + 1 << endl;
        cout << "�����: ";    cin >> number;
        cout << "����� ���������� ����: ";    cin >> mainCount;
        cout << endl;

        Train t{ destination, number, time, mainCount, kupeCount, plackartCount };
        v1.push_back(t);
    }

    for (size_t i = 0; i < v1.size() - 1; i++)
    {
        if (v1[i] == v1[i + 1])
        {
            cout << "���������� ���� � ������� ���������" << endl;
        }
        if (v1[i] != v1[i + 1])
        {
            cout << "���������� ���� � ������� ������" << endl;
        }
    }


    v1[0].show();
    v1[1].show();

    cout << "������������ ���������� ���� 2 ������ 1" << endl;
    v1[0] = v1[1];

    v1[0].show();
    v1[1].show();

    v1[0]++;
    v1[0]--;
    ++v1[0];
    --v1[0];


    cout << "������� ������ � ������ " << endl;
    cout << "�����: ";    cin >> number;
    cout << "����� ���������� ����: ";    cin >> mainCount;
    cout << endl;

    Observer t{ destination, number, time, mainCount, kupeCount, plackartCount };

    t.GetInfo(v1[0]);
}