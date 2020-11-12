//В приют привозят собак разных пород.
//В словаре shelter по названию хранится количество особей каждого вида на текущий момент.
//Приют может принять определённое количество собак каждой породы. Оно указано в словаре max_amount.
//Напишите функцию, которая будет на основании вектора с именами поступивших собак обновлять словарь shelter и 
//возвращать общее количество попавших в приют собак.
//Гарантируется, что никакие другие собаки, кроме известных из словаря max_amount, в приют не приедут.
//
//Пример входных данных для функции
//map<string, int>& shelter = { {"landseer"s, 1}, {"otterhound"s, 2}, {"pekingese"s, 2}, {"pointer"s, 3} };
//const map<string, int>& max_amount = { {"landseer"s, 2}, {"otterhound"s, 3}, {"pekingese"s, 4}, {"pointer"s, 7} };
//const vector<string>& new_dogs = { "landseer"s, "otterhound"s, "otterhound"s, "otterhound"s, "pointer"s };
//
//Пример вывода функции
//3


#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int CountAndAddNewDogs(const vector<string>& new_dogs,
    const map<string, int>& max_amount, map<string, int>& shelter) {
    //обычным способом
    /*int count = 0;
      for (auto& dog : new_dogs) {
        int max_dogs = max_amount.find(dog)->second;
        int now_dogs = shelter.find(dog)->second;
        if (now_dogs < max_dogs) {
            shelter[dog] = now_dogs + 1;
            count++;
        }
    }*/

    //через лямбду
    int count = count_if(new_dogs.begin(), new_dogs.end(),
        [&shelter, &max_amount](const string& dog) {
            //return shelter[dog] < max_amount.at(dog) ? shelter[dog] += 1 : 0;

            //или лучше так
            int& current_amount = shelter[dog];
            if (current_amount < max_amount.at(dog)) {
                return ++current_amount;
            }
            else return 0;
        });
    return count;
}


int main() {
    map<string, int> shelter = { {"landseer"s, 1}, {"otterhound"s, 2}, {"pekingese"s, 2}, {"pointer"s, 3} };
    const map<string, int>& max_amount = { {"landseer"s, 2}, {"otterhound"s, 3}, {"pekingese"s, 4}, {"pointer"s, 7} };
    const vector<string>& new_dogs = { "landseer"s, "otterhound"s, "otterhound"s, "otterhound"s, "pointer"s };
    int taken_dogs = CountAndAddNewDogs(new_dogs, max_amount, shelter);
    cout << taken_dogs << endl;
    return 0;
}