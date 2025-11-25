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
    
    file << "1. Name: To Kill a Mockingbird" << endl;
    file << "   Author: Harper Lee" << endl;
    file << "   Year: 1960" << endl;
    file << "   ----------" << endl;
    
    file << "2. Name: 1984" << endl;
    file << "   Author: George Orwell" << endl;
    file << "   Year: 1949" << endl;
    file << "   ----------" << endl;
    
    file << "3. Name: Pride and Prejudice" << endl;
    file << "   Author: Jane Austen" << endl;
    file << "   Year: 1813" << endl;
    file << "   ----------" << endl;
    
    file << "4. Name: The Great Gatsby" << endl;
    file << "   Author: F. Scott Fitzgerald" << endl;
    file << "   Year: 1925" << endl;
    file << "   ----------" << endl;
    
    file << "5. Name: Moby Dick" << endl;
    file << "   Author: Herman Melville" << endl;
    file << "   Year: 1851" << endl;
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