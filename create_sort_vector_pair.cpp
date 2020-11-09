//Считайте количество людей, имя и возраст каждого. 
//Выведите все имена с новой строки по старшинству — от старых к молодым.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int count;
    cin >> count;
    vector<pair<int, string>> v_person_data;
    for (int i = 0; i < count; ++i) {
        string name;
        int age;
        cin >> name >> age;
        v_person_data.push_back({ age, name });
    }

    sort(v_person_data.begin(), v_person_data.end());
    reverse(v_person_data.begin(), v_person_data.end());

    for (auto& person : v_person_data) {
        cout << person.second << endl;
    }
    return 0;
}