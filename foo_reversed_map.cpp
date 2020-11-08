//Напишите функцию, которая переворачивает словарь : ключи становятся значениями, а значения — ключами.
//Сделайте перевёрнутый словарь.

#include <iostream>
#include <map>

using namespace std;

map<string, string> BuildReversedMap(const map<string, string>& m) {
    //формируем перевернутый словарь -- rev_m
    //меняем местами элементы пары исходного словаря
    map<string, string> rev_m;
    for (const auto& elm : m) {
        rev_m[elm.second] = elm.first;
    }
    return rev_m;
}

void PrintMap(const map<string, string>& m) {
    //cout << "Size = "s << m.size() << endl;
    for (const auto& elm : m) {
        cout << elm.first << ", "s << elm.second << endl;
    }
}

int main() {
    map<string, string> map_zoo = { {"cat", "felis catus"}, {"dog", "canis lupus"} };
    map<string, string> rev_map_zoo = BuildReversedMap(map_zoo);
    PrintMap(rev_map_zoo);
    return 0;
}