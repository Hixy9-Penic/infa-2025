#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <codecvt>

using namespace std;

void printStudentInfo() {
  
    setlocale(LC_ALL, "ru_RU.UTF-8");
    cout << "Студент: Братерский Александр Максимович" << endl;
    cout << "Группа: М10-134БВ-25" << endl;
    cout << "Задание: task_1" << endl;
    cout << "------------------------" << endl;
}

void createBooksFile() {
    ofstream file("books.txt");
    if (!file.is_open()) {
        cout << "Ошибка создания файла books.txt!" << endl;
        return;
    }
    
    file << "1. Name:Anna Karenina" << endl;
    file << "   Author: Leo Tolstoy" << endl;
    file << "   Year: 1877" << endl;
    file << "   ----------" << endl;
    
    file << "2. Name: Dead Souls" << endl;
    file << "   Author: Nikolai Gogol" << endl;
    file << "   Year: 1842" << endl;
    file << "   ----------" << endl;
    
    file << "3. Name: Fathers and Sons" << endl;
    file << "   Author: Ivan Turgenev" << endl;
    file << "   Year: 1862" << endl;
    file << "   ----------" << endl;
    
    file << "4. Name: Crime and Punishment" << endl;
    file << "   Author: Fyodor Dostoevsky" << endl;
    file << "   Year: 1866" << endl;
    file << "   ----------" << endl;
    
    file << "5. Name: The Master and Margarita" << endl;
    file << "   Author: Mikhail Bulgakov" << endl;
    file << "   Year: 1928" << endl;
    file << "   ----------" << endl;
    
    file.close();
    cout << "Файл books.txt успешно создан с 5 записями о книгах!" << endl;
}

int main() {
    printStudentInfo();
    createBooksFile();
    
    cout << "Для продолжения нажмите любую клавишу . . .";
    cin.get();
    return 0;
}