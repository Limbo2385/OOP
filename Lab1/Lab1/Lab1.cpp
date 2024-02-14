#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
using namespace std;

class Train {
private:
    string destination; // пункт назначения
    int number; // номер
    int time;
    int mainCount; // количество мест
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

    Train()
    {

    }

    ~Train()
    {
        
    }

    void setTrain(string destination, int number, int time, int mainCount, int kupeCount, int plackartCount) {
        this->destination = destination;
        this->number = number;
        this->time = time;
        this->mainCount = mainCount;
        this->kupeCount = kupeCount;
        this->plackartCount = plackartCount;
    }

    void show() {
        cout << endl;
        cout << "Пункт назначения: " << destination << endl;
        cout << "Номер: " << number << endl;
        cout << "Время: " << time << endl;
        cout << "Общее количество мест: " << mainCount << endl;
        cout << "Мест в купе: " << kupeCount << endl;
        cout << "Мест в плацкарте: " << plackartCount << endl;

    }

    string getDestination() { return destination; }
    int getTime() { return time; }
    int getMainCount() { return mainCount; }
    int getNumber() { return number; }
};

void inputDataTrain(string destination, int number, int time, int mainCount, int kupeCount, int plackartCount) { // хотел сделать функцию для записи данных под новый объект класса
    cout << "Введите данные о поезде!\n";
    cout << "Пункт назначения: ";     cin >> destination;
    cout << "Номер: ";    cin >> number;
    cout << "Время: ";  cin >> time;
    cout << "Общее количество мест: ";    cin >> mainCount;
    cout << "Мест в купе: ";  cin >> kupeCount;
    cout << "Мест в плацкарте: ";  cin >> plackartCount;
}


int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    string destination;
    int number;
    int time;
    int mainCount;
    int kupeCount;
    int plackartCount;

    vector<Train> v1; // массив поездов

    for (size_t i = 0; i < 5; i++)
    {
        cout << "Введите данные о поезде " << i + 1<< endl;
        cout << "Пункт назначения: ";     cin >> destination;
        cout << "Номер: ";    cin >> number;
        cout << "Время: ";  cin >> time;
        cout << "Общее количество мест: ";    cin >> mainCount;
        cout << "Мест в купе: ";  cin >> kupeCount;
        cout << "Мест в плацкарте: ";  cin >> plackartCount;

        cout << endl;

        Train t{ destination, number, time, mainCount, kupeCount, plackartCount };
        /*Train t;
        t.setTrain(destination, number, time, mainCount, kupeCount, plackartCount);*/
        /*if (i > 1)
        {
            Train train{ t };
            v1.push_back(train);
            continue;
        }*/
        v1.push_back(t);
    }


     cout << "Введите искомый пункт назначения: "; cin >> destination;
     cout << "Введите время: "; cin >> time;
     cout << "Введите количество мест: "; cin >> mainCount;
     
     cout << "Поезда, следующие до заданного пункта назначения:" << endl;

     for (size_t i = 0; i < v1.size(); i++)
     {
         if (v1[i].getDestination() == destination)
         {
             cout << v1[i].getNumber() << endl;
         }
     }

     cout << endl;
     cout << "Поезда, следующие до заданного пункта назначения с учетом времени:" << endl;

     for (size_t i = 0; i < v1.size(); i++)
     {
         if (v1[i].getDestination() == destination && v1[i].getTime() > time)
         {
             cout << v1[i].getNumber() << endl;
         }
     }

     cout << endl;
     cout << "Поезда, следующие до заданного пункта назначения с учетом мест:" << endl;

     for (size_t i = 0; i < v1.size(); i++)
     {
         if (v1[i].getDestination() == destination && v1[i].getMainCount() == mainCount)
         {
             cout << v1[i].getNumber() << endl;
         }
     }
     
     cout << "Размер массива: " << v1.size();
}