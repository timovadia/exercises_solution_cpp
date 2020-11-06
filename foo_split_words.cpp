#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> SplitIntoWords(string text) {
    vector<string> words;
    string word;
    for (int i = 0; i < text.size(); ++i) {
        if (text[i] == ' ') {
            words.push_back(word);
            word = ""s;
        } else {
            word += text[i];
        }
    }
    words.push_back(word);
    return words;
}

int main() {
    string query;
    getline(cin, query);
    
    vector<string> v_words = SplitIntoWords(query);
    for (string word : v_words) {
            cout << '[' << word << ']' << endl;
    }
}