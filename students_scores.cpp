// Выведите фамилии и имена учащихся в порядке убывания их среднего балла.

// Входные данные

// Заданы сначала количество учащихся n, затем n строк, каждая из которых содержит фамилию, 
// имя и три числа (оценки по трем предметам: математике, физике, информатике). 
// Данные в строке разделены одним пробелом. Оценки принимают значение от 1 до 5.

// Выходные данные

// Необходимо вывести пары фамилия-имя по одной на строке, разделяя фамилию и имя одним пробелом. 
// Выводить оценки не нужно. Если несколько учащихся имеют одинаковые средние баллы, то их нужно выводить в порядке, заданном во входных данных.

// Sample Input:
// 3
// Markov Valeriy 5 5 5
// Sergey Petrov 1 1 1
// Petrov Petr 3 3 3

// Sample Output:
// Markov Valeriy
// Petrov Petr
// Sergey Petrov

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct studScore {
    string surname;
    string name;
    double avg_score;
};

bool cmp(studScore a, studScore b) {
    return a.avg_score > b.avg_score;
}

int main() {
    int n, score1, score2, score3;
    string surname, name;
    cin >> n;
    vector<studScore> ss(n);
    for (int i = 0; i < n; i++) {
        cin >> surname >> name >> score1 >> score2 >> score3;
        studScore struct_temp; 
        struct_temp.surname = surname;
        struct_temp.name = name;
        struct_temp.avg_score = (double) (score1 + score2 + score3) / 3;
        ss[i] = struct_temp;
    }
    stable_sort(ss.begin(), ss.end(), cmp);
    for (auto elm : ss) {
        cout << elm.surname << " " << elm.name << endl;
    } 
    return 0;
}