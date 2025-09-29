#include "SoftwareProduct.h"

// Класс: Операционная система
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

// Класс: Текстовый редактор
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
