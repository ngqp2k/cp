#include <bits/stdc++.h>
using namespace std;

string add(string s1, string s2) {
    if (s1.length() < s2.length())
        swap(s1, s2);
    while (s2.length() < s1.length())
        s2 = "0" + s2;

    string ans = "";
    int tmp = 0;
    for (int i = s1.length() - 1; i >= 0; --i) {
        int x = (s1[i] - '0');
        int y = (s2[i] - '0');
        int sum = x + y + tmp;
        tmp = sum / 10;
        sum = sum % 10;
        ans = to_string(sum) + ans;
    }
    if (tmp)
        ans = "1" + ans;
    return ans;
}