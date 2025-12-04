#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <locale>

using namespace std;

void printStudentInfo() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    cout << "Студент: Братерский Александр Максимович" << endl;
    cout << "Группа: М10-134БВ-25" << endl;
    cout << "Задание: task_4" << endl;
    cout << "------------------------" << endl;
}

void analyzeTextFile() {
    string filename;
    cout << "Введите имя текстового файла (например, input.txt): ";
    cin >> filename;
    
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла: " << filename << endl;
        cout << "Убедитесь, что файл существует в текущей директории." << endl;
        return;
    }
    
    int lineCount = 0;
    int wordCount = 0;
    string line;
    
    while (getline(file, line)) {
        lineCount++;
        
        // Подсчет слов в строке
        stringstream ss(line);
        string word;
        while (ss >> word) {
            wordCount++;
        }
    }
    file.close();
    
    // Вывод результатов в консоль
    cout << "\nРезультаты анализа файла:" << endl;
    cout << "=========================" << endl;
    cout << "Имя файла: " << filename << endl;
    cout << "Всего строк: " << lineCount << endl;
    cout << "Всего слов: " << wordCount << endl;
    
    // Запись результатов в файл report.txt
    ofstream reportFile("report.txt");
    if (!reportFile.is_open()) {
        cout << "Ошибка создания файла report.txt!" << endl;
        return;
    }
    
    reportFile << "Отчет анализа файла" << endl;
    reportFile << "===================" << endl;
    reportFile << "Имя файла: " << filename << endl;
    reportFile << "Всего строк: " << lineCount << endl;
    reportFile << "Всего слов: " << wordCount << endl;
    reportFile << "Отчет создан: Братерский Александр Максимович, Группа М10-134БВ-25" << endl;
    
    reportFile.close();
    cout << "\nОтчет сохранен в файл report.txt" << endl;
    
    // Показываем содержимое report.txt
    cout << "\nСодержимое report.txt:" << endl;
    cout << "======================" << endl;
    ifstream showReport("report.txt");
    string reportLine;
    while (getline(showReport, reportLine)) {
        cout << reportLine << endl;
    }
    showReport.close();
}

int main() {
    printStudentInfo();
    analyzeTextFile();
    
    cout << "Для продолжения нажмите любую клавишу . . .";
    cin.ignore();
    cin.get();
    return 0;
}