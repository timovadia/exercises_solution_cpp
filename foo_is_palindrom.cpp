// По данной строке определите, является ли она палиндромом 
// (то есть, читается одинаково как слева-направо, так и справа-налево).

// Входные данные
// На вход подается 1 строка без пробелов.

// Выходные данные
// Необходимо вывести yes, если строка является палиндромом, и no в противном случае.

#include <iostream>
#include <string>

using namespace std;

void IsPalindrome(string s) {
    string s_rev = "";
    for (int i = s.size() - 1; i >= 0; i--) {
        s_rev = s_rev + s[i];
    }
    if (s == s_rev) {
        cout << "yes" << endl;
    } else cout << "no" << endl;
}

int main() {
    string s;
    cin >> s;
    IsPalindrome(s);
    return 0;
}