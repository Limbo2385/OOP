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

    std::string getDestination() {
        return this->destination;
    }
};

void inputDataTrain(std::string destination, int number, int time, int mainCount, int kupeCount, int plackartCount) { // хотел сделать функцию для записи данных под новый объект класса
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

    std::string destination;
    int number;
    int time;
    int mainCount; 
    int kupeCount;
    int plackartCount;
    std::string name;
    
    vector<Train> v1; // массив поездов

    cout << "Введите данные о поезде!\n";
    cout << "Пункт назначения: ";     cin >> destination;
    cout << "Номер: ";    cin >> number;
    cout << "Время: ";  cin >> time;
    cout << "Общее количество мест: ";    cin >> mainCount;
    cout << "Мест в купе: ";  cin >> kupeCount;
    cout << "Мест в плацкарте: ";  cin >> plackartCount;

    std::cout << endl;

    cout << "Введите искомый пункт значения: "; cin >> name;

    Train t1;
    t1.setTrain(destination, number, time, mainCount, kupeCount, plackartCount);
    Train t2;
    t2.setTrain(destination, number, time, mainCount, kupeCount, plackartCount);
    Train t3;
    t3.setTrain(destination, number, time, mainCount, kupeCount, plackartCount);

    v1.push_back(t1);
    v1.push_back(t2);
    v1.push_back(t3);

    std::cout << endl;
    std::cout << "Походящие поезда: ";
    std::cout << v1.size() << endl;
    std::cout << endl;

    for (int i = 0; i < v1.size(); i++) {
        std::cout << i+1 << " поезд";
        if (v1[i].getDestination() == name) {
            v1[i].show();
            std::cout << endl;

        }
    }



    std::cout << "Размер массива: " << v1.size();
    

}

