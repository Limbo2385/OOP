#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
using namespace std;

class Train {
private:
    std::string destination; // пункт назначения
    int number; // номер
    int time; 
    int mainCount; // количество мест
    int kupeCount;
    int plackartCount;
public:
    void setTrain(std::string destination, int number, int time, int mainCount, int kupeCount, int plackartCount) {
         this->destination = destination;
         this->number = number;
         this->time = time;
         this->mainCount = mainCount;
         this->kupeCount = kupeCount;
         this->plackartCount = plackartCount;
    }

    void show() {
        std::cout << endl;
        std::cout << "Пункт назначения: " << destination << std::endl;
        std::cout << "Номер: " << number << std::endl;
        std::cout << "Время: " << time << std::endl;
        std::cout << "Общее количество мест: " << mainCount << std::endl;
        std::cout << "Мест в купе: " << kupeCount << std::endl;
        std::cout << "Мест в плацкарте: " << plackartCount << std::endl;

    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    std::string destination;
    int number;
    int time;
    int mainCount; 
    int kupeCount;
    int plackartCount;

    std::vector<Train> v1; // массив поездов

    cout << "Введите данные о поезде!\n";
    cout << "Пункт назначения: ";     cin >> destination;
    cout << "Номер: ";    cin >> number;
    cout << "Время: ";  cin >> time;
    cout << "Общее количество мест: ";    cin >> mainCount;
    cout << "Мест в купе: ";  cin >> kupeCount;
    cout << "Мест в плацкарте: ";  cin >> plackartCount;

    Train t1;
    t1.setTrain(destination, number, time, mainCount, kupeCount, plackartCount);
    t1.show();

    v1.push_back(t1);
    //getline(std::cin, name);
    //std::cout << name << std::endl;

}

