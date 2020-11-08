//Напишите функцию MoveStrings. 
//Она принимает векторы строк source и destination и дописывает все строки из первого вектора в конец второго.
//После выполнения функции вектор source должен быть пустым.

#include <iostream>
#include <vector>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination) {
    for (auto& now : source) {
        destination.push_back(now);
    }
    source.clear();
}

int main() {
    vector<string> source = { "two", "three", "four" };
    vector<string> destination = { "one" };
    MoveStrings(source, destination);
    source.empty() ? cout << "Source is empty" << endl : cout << "Wrong" << endl;// Если вектор query_words пуст. Метод empty вернёт true, метод size -- 0. 
    for (auto& elm : destination) {
        cout << elm << " ";
    }
    return 0;
}