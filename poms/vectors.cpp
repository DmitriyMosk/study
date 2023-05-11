#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>

using namespace std;

class ManufacturingCompany
{
public:
    string Country;
    string TypeOfEquipment;

    void OutPut()
    {
        cout << "Company from " << Country << ", using this type of equipment: " << TypeOfEquipment << endl
             << endl;
    };

    ManufacturingCompany()
    {
        TypeOfEquipment = Country = "-";
    }

    ManufacturingCompany(string p_Country, string p_TypeOfEquipment)
    {
        Country = p_Country;
        TypeOfEquipment = p_TypeOfEquipment;
    }
};

bool compare(ManufacturingCompany a, ManufacturingCompany b){
    return (a.TypeOfEquipment < b.TypeOfEquipment);
}

int main()
{
    srand(time(NULL));
    int n1, n2;
    cout << "Lenght of FIRST vector: ";
    cin >> n1;

    int count = 0;

    vector<ManufacturingCompany> first(n1);
    vector<ManufacturingCompany> second;

    ManufacturingCompany arr[14] = {
        ManufacturingCompany("Japan", "alcohol"),
        ManufacturingCompany("China", "Fast food"),
        ManufacturingCompany("USA", "marketplace"),
        ManufacturingCompany("USSR", "factory"),
        ManufacturingCompany("-", "transport"),
        ManufacturingCompany("France", "-"),
        ManufacturingCompany(),
        ManufacturingCompany("-", "factory"),
        ManufacturingCompany("RF", "-"),
        ManufacturingCompany("-", "Marketplace"),
        ManufacturingCompany("German", "-"),
        ManufacturingCompany("Australia", "-"),
        ManufacturingCompany("-", "Fast food"),
        ManufacturingCompany("-", "clock"),
    };

    for (int i = 0; i < (int)first.size(); i++)
    {
        first[i] = arr[rand() % 14];
    }

    cout << "Vector first: ";
    for (int i = 0; i < (int)first.size(); i++)
    {
        cout << "(" << first[i].Country << ", " << first[i].TypeOfEquipment << "), ";
    }
    cout << endl;
    for (int i = 0; i < (int)first.size(); i++)
    {
        if (first[i].Country == "-" && first[i].TypeOfEquipment != "-")
        {
            second.push_back(first[i]);
        }
    }

    if (!second.empty())
    {
        cout << "Before sort: ";
        for (int i = 0; i < (int)second.size(); i++)
        {
            cout << "(" << second[i].Country << ", " << second[i].TypeOfEquipment << "), ";
        }
        cout << endl;
        cout << "After sort: ";
        sort(second.begin(), second.end(),compare);
        for (int i = 0; i < (int)second.size(); i++)
        {
            cout << "(" << second[i].Country << ", " << second[i].TypeOfEquipment << "), ";
        }
        cout << endl;
    }
    else
    {
        cout << "Vector is empty!" << endl;
    }
}

