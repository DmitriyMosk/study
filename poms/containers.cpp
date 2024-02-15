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

    // добавление абонентов в картотеку
    abonent.push_back(kartoteka("+79261234567", "Иванов Иван Иванович", "1234 567890"));
    abonent.push_back(kartoteka("+79181234567", "Петров Петр Петрович", "2345 678901"));
    abonent.push_back(kartoteka("+79001234567", "Сидоров Сидор Сидорович", "3456 789012"));

    // сортировка картотеки по алфавиту
    abonent.sort(Compare);

    // вывод всей картотеки
    cout << "Картотека абонентов:" << endl;
    for (const auto& kartoteka : abonent) {
        cout << kartoteka.GetPhoneNumber() << " " << kartoteka.GetFio() << " " << kartoteka.GetPassport() << endl;
    }

    // поиск абонента по номеру телефона
    string input_phone_number;
    cout << "Введите номер телефона для поиска: ";
    cin >> input_phone_number;

    bool found = false;
    for (const auto& kartoteka : abonent) {
        if (kartoteka.GetPhoneNumber() == input_phone_number) {
            cout << "Найден абонент: " << kartoteka.GetFio() << " " << kartoteka.GetPassport() << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Абонент с номером телефона " << input_phone_number << " не найден" << endl;
    }

    return 0;
}