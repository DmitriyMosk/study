#include <iostream>
#include <list>
#include <string>

using namespace std;

class kartoteka {
public:
    kartoteka(string phone_number, string fio, string passport_number)
        : phone_number_(phone_number), fio_(fio), passport_number_(passport_number) {}
 
    const string& GetPhoneNumber() const {
        return phone_number_;
    }

    const string& GetFio() const {
        return fio_;
    }

    const string& GetPassport() const {
        return passport_number_;
    }

private:
    string phone_number_;
    string fio_;
    string passport_number_;
};

bool Compare(const kartoteka& subscriber1, const kartoteka& subscriber2) {
    return subscriber1.GetFio() < subscriber2.GetFio();
}

int main() {
    list<kartoteka> abonent;

    // ���������� ��������� � ���������
    abonent.push_back(kartoteka("+79261234567", "������ ���� ��������", "1234 567890"));
    abonent.push_back(kartoteka("+79181234567", "������ ���� ��������", "2345 678901"));
    abonent.push_back(kartoteka("+79001234567", "������� ����� ���������", "3456 789012"));

    // ���������� ��������� �� ��������
    abonent.sort(Compare);

    // ����� ���� ���������
    cout << "��������� ���������:" << endl;
    for (const auto& kartoteka : abonent) {
        cout << kartoteka.GetPhoneNumber() << " " << kartoteka.GetFio() << " " << kartoteka.GetPassport() << endl;
    }

    // ����� �������� �� ������ ��������
    string input_phone_number;
    cout << "������� ����� �������� ��� ������: ";
    cin >> input_phone_number;

    bool found = false;
    for (const auto& kartoteka : abonent) {
        if (kartoteka.GetPhoneNumber() == input_phone_number) {
            cout << "������ �������: " << kartoteka.GetFio() << " " << kartoteka.GetPassport() << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "������� � ������� �������� " << input_phone_number << " �� ������" << endl;
    }

    return 0;
}