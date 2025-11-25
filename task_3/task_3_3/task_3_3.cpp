#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <locale>

using namespace std;

void printStudentInfo() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    cout << "Студент: Братерский Александр Максимович" << endl;
    cout << "Группа: М10-134БВ-25" << endl;
    cout << "Задание: task_3" << endl;
    cout << "------------------------" << endl;
}

void createIncorrectBooksFile() {
    ifstream inputFile("books.txt");
    if (!inputFile.is_open()) {
        cout << "Ошибка открытия файла books.txt!" << endl;
        cout << "Убедитесь, что файл books.txt существует в текущей директории." << endl;
        return;
    }
    
    vector<string> names;
    vector<string> authors;
    vector<string> years;
    
    string line;
    while (getline(inputFile, line)) {
        if (line.find("Name:") != string::npos) {
            names.push_back(line);
        } else if (line.find("Author:") != string::npos) {
            authors.push_back(line);
        } else if (line.find("Year:") != string::npos) {
            years.push_back(line);
        }
    }
    inputFile.close();
    
 
    srand(time(0));
    random_shuffle(names.begin(), names.end());
    random_shuffle(authors.begin(), authors.end());
    random_shuffle(years.begin(), years.end());
    
    ofstream outputFile("incorrect_books.txt");
    if (!outputFile.is_open()) {
        cout << "Ошибка создания файла incorrect_books.txt!" << endl;
        return;
    }
    
    int entriesCount = min(min(names.size(), authors.size()), years.size());
    for (int i = 0; i < entriesCount; i++) {
        outputFile << (i + 1) << ". " << names[i].substr(names[i].find("Name:")) << endl;
        outputFile << "   " << authors[i].substr(authors[i].find("Author:")) << endl;
        outputFile << "   " << years[i].substr(years[i].find("Year:")) << endl;
        outputFile << "   ----------" << endl;
    }
    
    outputFile.close();
    cout << "Файл incorrect_books.txt успешно создан с " << entriesCount << " перемешанными записями!" << endl;
    
    
    cout << "\nПервая запись из incorrect_books.txt:" << endl;
    cout << "=====================================" << endl;
    ifstream showFile("incorrect_books.txt");
    string showLine;
    for (int i = 0; i < 4 && getline(showFile, showLine); i++) {
        cout << showLine << endl;
    }
    showFile.close();
}

int main() {
    printStudentInfo();
    createIncorrectBooksFile();
    
    cout << "Для продолжения нажмите любую клавишу . . .";
    cin.get();
    return 0;
}