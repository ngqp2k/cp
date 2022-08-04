#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string sumBigNum(string s1, string s2) {
    string res = "";
    if (s1.length() < s2.length())
        swap(s1, s2);
    int n = s1.length();
    while (s2.length() < s1.length()) s2 = '0' + s2;
    int carry = 0;
    for (int i = n - 1; i >= 0; --i) {
        int numS1 = s1[i] - '0';
        int numS2 = s2[i] - '0';
        int numRes = numS1 + numS2 + carry;
        res = char((numRes % 10) + 48) + res;
        carry = numRes >= 10 ? 1 : 0;
    }
    if (carry > 0)
        res = '1' + res;
    return res;
}

bool compare(string s1, string s2) {
    int n1 = s1.length(), n2 = s2.length();
    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;
    for (int i = 0; i < n1; i++)
        if (s1[i] < s2[i])
            return true;
        else if (s1[i] > s2[i])
            return false;
    return false;
}

string subBigNum(string s1, string s2)
{
    char minus;
    if (compare(s1, s2)) {
        swap(s1, s2);
        minus = '-';
    }
    string s = "";
    int n1 = s1.length(), n2 = s2.length();
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int carry = 0;
    for (int i = 0; i < n2; i++) {
        int sub = ((s1[i] - '0') - (s2[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
        s.push_back(sub + '0');
    }
    for (int i = n2; i < n1; i++) {
        int sub = ((s1[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
        s.push_back(sub + '0');
    }
    reverse(s.begin(), s.end());
    return (minus + s);
}

int main() {
	string s1, s2; cin >> s1 >> s2;
	cout << s1 << " + " << s2 << " = " << sumBigNum(s1, s2) << "\n";
	cout << s1 << " - " << s2 << " = " << subBigNum(s1, s2) << "\n";
}