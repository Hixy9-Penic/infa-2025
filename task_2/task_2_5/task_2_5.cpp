#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

void printStudentInfo() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Student: Братерский Александр Максимович" << std::endl;
    std::cout << "Group: М10-134БВ-25" << std::endl;
    std::cout << "Task: task_5" << std::endl;
}

template<typename K, typename V>
void printMap(const map<K, V>& myMap) {
    cout << "My map has " << myMap.size() << " of keys and has these pairs:" << endl;
    for (const auto& pair : myMap) {
        cout << "[" << pair.first << "] -> {" << pair.second << "}" << endl;
    }
}

template<typename K, typename V>
void printMap(const map<K, vector<V>>& myMap) {
    cout << "My map has " << myMap.size() << " of keys and has these pairs:" << endl;
    for (const auto& pair : myMap) {
        cout << "[" << pair.first << "] -> {";
        for (size_t i = 0; i < pair.second.size(); ++i) {
            cout << pair.second[i];
            if (i < pair.second.size() - 1) {
                cout << ", ";
            }
        }
        cout << "}" << endl;
    }
}

template<typename K, typename V>
void printMap(const map<vector<K>, V>& myMap) {
    cout << "My map has " << myMap.size() << " of keys and has these pairs:" << endl;
    for (const auto& pair : myMap) {
        cout << "[";
        for (size_t i = 0; i < pair.first.size(); ++i) {
            cout << pair.first[i];
            if (i < pair.first.size() - 1) {
                cout << ", ";
            }
        }
        cout << "] -> {" << pair.second << "}" << endl;
    }
}

int main() {
    printStudentInfo();

    map<int, string> simpleMap = {
        {1, "One"},
        {2, "Two"},
        {3, "Three"}
    };

    cout << "Simple map (int -> string):" << endl;
    printMap(simpleMap);
    cout << endl;

    map<string, vector<int>> studentGrades = {
        {"McLovin", {5, 4, 5}},
        {"Prigozhin", {3, 4, 5}},
        {"Sidorovich", {4, 4, 3}}
    };

    cout << "Map with vector values (string -> vector<int>):" << endl;
    printMap(studentGrades);
    cout << endl;

    map<vector<int>, string> coordinatesMap = {
        {{1, 2, 3}, "Point A"},
        {{4, 5, 6}, "Point B"},
        {{7, 8, 9}, "Point C"}
    };

    cout << "Map with vector keys (vector<int> -> string):" << endl;
    printMap(coordinatesMap);
    system("pause");
    return 0;
}