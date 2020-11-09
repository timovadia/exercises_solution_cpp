//Напишите функцию, которая принимает вектор строк и возвращает число строк, начинающихся на большую или маленькую букву "a".

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsFirstLetterA(const string& s) {
    return !s.empty() && (s[0] == 'a' || s[0] == 'A');
}

int CountStartsWithA(const vector<string>& xs) {
    return count_if(xs.begin(), xs.end(), IsFirstLetterA);
}

int main() {
    cout << CountStartsWithA({ "And"s, "another"s, "one"s, "gone"s, "another"s, "one"s "bites"s, "the"s, "dust"s });
    return 0;
}