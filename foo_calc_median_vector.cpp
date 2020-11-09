//Напишите функцию, которая принимает на вход вектор времени ответа и вычисляет медиану этого вектора.
//Вектор может быть неотсортированным.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

pair<bool, double> CalcMedian(vector<double>& samples) {
    // верните {true, медиана}, если она существует, то есть вектор непустой,
    // иначе - {false, 0}
    bool exist = false;
    double median = 0;
    sort(samples.begin(), samples.end());
    if (samples.size() % 2 == 0 && !samples.empty()) {
        // чётное
        median = 0.5 * (samples[(samples.size() / 2) - 1] + samples[(samples.size() / 2)]);
        exist = true;
    }
    else if (!samples.empty()) {
        // нечётное
        median = samples[samples.size() / 2];
        exist = true;
    }
    else {
        exist = false;
    }
    return { exist, median };
}

int main() {
    int size;
    cin >> size;

    vector<double> samples;
    for (int i = 0; i < size; ++i) {
        double sample;
        cin >> sample;
        samples.push_back(sample);
    }

    pair<bool, double> result = CalcMedian(samples);
    if (result.first) {
        cout << result.second << endl;
    }
    else {
        cout << "Empty vector"s << endl;
    }

    return 0;
}