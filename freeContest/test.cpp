#include <bits/stdc++.h>
using namespace std;

string testCase(int n){
    if (0 <= n && n < 10){
        return "00" + to_string(n);
    }
    else if (10 <= n && n < 100){
        return "0" + to_string(n);
    }
    else{
        return to_string(n);
    }
}

int main()
{
    srand(time(NULL));

    for (int iTest = 0; iTest < 100; iTest++)
    {
        system(("sol.exe<test/input." + testCase(iTest) + ">ouBL").c_str());
        if (system(("fc ouBL test/output." + testCase(iTest)).c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
