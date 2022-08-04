#include <bits/stdc++.h>
using namespace std;

int main() {
  int a = 10;
  int & res = a;
  cout << a << "\n";
  res = 11;
  cout << a << "\n";
}
