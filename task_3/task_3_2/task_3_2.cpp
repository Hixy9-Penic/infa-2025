#include <iostream>
#include <fstream>
#include <string>
#include <locale>

using namespace std;

void printStudentInfo() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    cout << "Студент: Братерский Александр Максимович" << endl;
    cout << "Группа: М10-134БВ-25" << endl;
    cout << "Задание: task_2" << endl;
    cout << "------------------------" << endl;
}

void readAndDisplayBooks() {
    ifstream file("books.txt");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла books.txt!" << endl;
        cout << "Убедитесь, что файл books.txt существует в текущей директории." << endl;
        return;
    }
    
    string line;
    cout << "Содержимое файла books.txt:" << endl;
    cout << "===========================" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

int main() {
    printStudentInfo();
    readAndDisplayBooks();
    
    cout << "Для продолжения нажмите любую клавишу . . .";
    cin.get();
    return 0;
}