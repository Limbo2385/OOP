#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

class Organization
{
private:
    string organization;
public:
    string getOrganization() { return organization; }

    void setOrganization(string organization) { this->organization = organization; }

    void showOrganization()
    {
        cout << "Организация: " << getOrganization() << endl;
    }
};

class InsuranceCompany : public Organization
{
private:
    string insuranceCompany;
public:
    string getInsuranceCompany() { return insuranceCompany; }

    void setInsuranceCompany(string insuranceCompany) { this->insuranceCompany = insuranceCompany; }

    void showInsuranceCompany()
    {
        cout << "Страховая компания: " << getInsuranceCompany() << endl;
    }
};

class Factory : public InsuranceCompany
{
private:
    string nameFactory;
    int performance;
public:
    Factory(string organization, string insuranceCompany, string nameFactory, int performance)
    {
        setOrganization(organization);
        setInsuranceCompany(insuranceCompany);
        this->nameFactory = nameFactory;
        this->performance = performance;
    }

    string getNameFactory() { return nameFactory; }
    int getPerformance() { return performance; }

    void setNameFactory(string nameFactory) { this->nameFactory = nameFactory; }
    void setPerformance(int performance) { this->performance = performance; }

    void show()
    {
        showOrganization();
        showInsuranceCompany();
        cout << "Завод: " << getNameFactory() << endl;
        cout << "Производительность завода: " << getPerformance() << endl << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    string organization;
    string insuranceCompany;
    string nameFactory;
    int performance;
    vector<Factory> v1;

    for (size_t i = 0; i < 2; i++)
    {
        cout << "Введите организацию: "; cin >> organization;
        cout << "Страховую компанию: ";    cin >> insuranceCompany;
        cout << "Название завода: ";    cin >> nameFactory;
        cout << "Производительность завода: ";    cin >> performance;
        cout << endl;

        Factory factory{ organization, insuranceCompany, nameFactory, performance };
        v1.push_back(factory);
    }

    for (size_t i = 0; i < v1.size(); i++)
    {
        v1[i].show();
    }
}