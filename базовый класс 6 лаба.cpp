#ifndef SOFTWAREPRODUCT_H
#define SOFTWAREPRODUCT_H

#include <iostream>
#include <string>
using namespace std;

// Базовый класс: Программный продукт
class SoftwareProduct {
protected:
    string name;        // Название продукта
    string developer;   // Разработчик
    int releaseYear;    // Год выпуска

public:
    // Конструктор по умолчанию
    SoftwareProduct() : name("Неизвестно"), developer("Неизвестно"), releaseYear(0) {}

    // Конструктор с параметрами
    SoftwareProduct(string n, string d, int y) : name(n), developer(d), releaseYear(y) {}

    // Метод отображения информации
    virtual void displayInfo() const {
        cout << "Программный продукт: " << name 
             << ", Разработчик: " << developer 
             << ", Год выпуска: " << releaseYear << endl;
    }

    // Виртуальная функция (вычисляемый параметр)
    virtual string getLatestVersion() const = 0;

    // Виртуальный деструктор
    virtual ~SoftwareProduct() {}
};

#endif // SOFTWAREPRODUCT_H
