// Задача №3
// “Копирование строк”

// Создайте класс, описывающий строку произвольной длины. 
// Не забывайте про принципы абстракции и инкапсуляции.
// В классе реализуйте конструктор копирования, 
// оператор присваивания копированием и деструктор. Продемонстрируйте использование вашего класса.

#include <iostream>

class MyString {
private:
    char* str;
    int length;

public:

    // Консутруктор 
    MyString(char* s = "") {
        length = 0;
        while (s[length] != '\0') {
            length++;
        }
        str = new char[length + 1];
        for (int i = 0; i < length; ++i) {
            str[i] = s[i];
        }
        str[length] = '\0';
    }

    // Конструктор копирования
    MyString(MyString& other) {
        length = other.length;
        str = new char[length + 1];
        for (int i = 0; i < length; ++i) {
            str[i] = other.str[i];
        }
        str[length] = '\0';
    }

    // Оператор присваивания копированием
    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            for (int i = 0; i < length; ++i) {
                str[i] = other.str[i];
            }
            str[length] = '\0';
        }
        return *this;
    }

    // Деструктор 
    ~MyString() {
        delete[] str;
    }

    char* getString() {
        return str;
    }

    unsigned int getLength() {
        return length;
    }
};

int main() {
    MyString str1("eXAMPLE");
    MyString str2(str1);
    MyString str3 = str2;
    MyString str4;
    str4 = str3;

    std::cout << "str1: " << str1.getString() << ", length: " << str1.getLength() << std::endl;
    std::cout << "str2: " << str2.getString() << ", length: " << str2.getLength() << std::endl;
    std::cout << "str3: " << str3.getString() << ", length: " << str3.getLength() << std::endl;
    std::cout << "str4: " << str4.getString() << ", length: " << str4.getLength() << std::endl;

    return 0;
}