#include <iostream>
#include <vector>
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

    // Виртуальный метод для отображения информации
    virtual void displayInfo() const {
        cout << "Программный продукт: " << name 
             << ", Разработчик: " << developer 
             << ", Год выпуска: " << releaseYear << endl;
    }

    // Виртуальный метод для вычисляемого параметра
    virtual string getLatestVersion() const = 0;

    // Виртуальный деструктор
    virtual ~SoftwareProduct() {}
};

// Производный класс: Операционная система
class OperatingSystem : public SoftwareProduct {
private:
    string kernelVersion; // Версия ядра

public:
    // Конструктор
    OperatingSystem(string n, string d, int y, string kv)
        : SoftwareProduct(n, d, y), kernelVersion(kv) {}

    // Переопределение метода отображения информации
    void displayInfo() const override {
        cout << "ОС: " << name << ", Разработчик: " << developer 
             << ", Год выпуска: " << releaseYear 
             << ", Версия ядра: " << kernelVersion << endl;
    }

    // Реализация вычисляемого параметра
    string getLatestVersion() const override {
        return "Версия ядра: " + kernelVersion;
    }
};

// Производный класс: Текстовый редактор
class TextEditor : public SoftwareProduct {
private:
    string editorVersion; // Версия редактора

public:
    // Конструктор
    TextEditor(string n, string d, int y, string ev)
        : SoftwareProduct(n, d, y), editorVersion(ev) {}

    // Переопределение метода отображения информации
    void displayInfo() const override {
        cout << "Текстовый редактор: " << name 
             << ", Разработчик: " << developer 
             << ", Год выпуска: " << releaseYear 
             << ", Версия редактора: " << editorVersion << endl;
    }

    // Реализация вычисляемого параметра
    string getLatestVersion() const override {
        return "Версия редактора: " + editorVersion;
    }
};

// Главное меню программы
void menu(vector<SoftwareProduct*>& products) {
    int choice;

    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Добавить операционную систему\n";
        cout << "2. Добавить текстовый редактор\n";
        cout << "3. Показать все продукты\n";
        cout << "4. Показать последнюю версию программы\n";
        cout << "5. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        if (choice == 1) { // Добавить ОС
            string name, developer, kernelVersion;
            int year;

            cout << "Введите имя ОС, разработчика, год выпуска и версию ядра: ";
            cin >> name >> developer >> year >> kernelVersion;

            products.push_back(new OperatingSystem(name, developer, year, kernelVersion));
            cout << "Операционная система добавлена.\n";
        }
        else if (choice == 2) { // Добавить текстовый редактор
            string name, developer, editorVersion;
            int year;

            cout << "Введите имя редактора, разработчика, год выпуска и версию редактора: ";
            cin >> name >> developer >> year >> editorVersion;

            products.push_back(new TextEditor(name, developer, year, editorVersion));
            cout << "Текстовый редактор добавлен.\n";
        }
        else if (choice == 3) { // Показать все продукты
            cout << "Список программных продуктов:\n";
            for (const auto& product : products) {
                product->displayInfo();
            }
        }
        else if (choice == 4) { // Показать последнюю версию
            cout << "Последние версии программ:\n";
            for (const auto& product : products) {
                cout << product->getLatestVersion() << endl;
            }
        }
        else if (choice == 5) { // Выход
            cout << "Завершение программы.\n";
            break;
        }
        else {
            cout << "Некорректный ввод. Попробуйте снова.\n";
        }
    }
}

int main() {
    vector<SoftwareProduct*> products; // Массив указателей на базовый класс

    menu(products);

    // Очистка памяти
    for (auto product : products) {
        delete product;
    }

    return 0;
}
