// Вводится один символ, измените его регистр. 
// То есть, если была введена строчная буква - сделайте ее заглавной и наоборот. 
// Символы, не являющиеся латинской буквой, нужно выводить без изменений.

#include <iostream>
#include <cctype>

using namespace std;
  
int main() {
    char s, s_up, s_low;
    cin >> s;
    s_up = (char) toupper(s);
    s_low = (char) tolower(s);
    if ((int) s == (int) s_up) {
        cout << s_low << endl;
    } else cout << s_up << endl;
    return 0;
}