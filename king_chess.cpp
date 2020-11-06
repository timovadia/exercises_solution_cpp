// Шахматный король ходит по горизонтали, вертикали и диагонали, но только на 1 клетку. 
// Даны две различные клетки шахматной доски, определите, может ли король попасть с первой клетки 
// на вторую одним ходом.

#include <iostream>
#include <cmath>

using namespace std;

int main() {
   int x1, y1, x2, y2;
   cin >> x1 >> y1 >> x2 >> y2;
   if (abs(x1 - x2) <= 1 && abs(y1 - y2) <= 1) {
       cout << "YES" << endl;
   } else {
      cout << "NO" << endl;
   }
   return 0;
}