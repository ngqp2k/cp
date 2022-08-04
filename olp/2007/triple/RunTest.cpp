#include <bits/stdc++.h>
using namespace std;

string testCase(int n){
    if (0 <= n && n < 10){
        return to_string(n);
    }
    else{
        return to_string(n);
    }
}

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= 10; iTest++)
    {
        // if (iTest == 7 || iTest == 8 || iTest == 9) continue;
        system(("sol.exe<test/test" + testCase(iTest) + "/triple.inp>ouBL").c_str());
        if (system(("fc ouBL test/test" + testCase(iTest) + "/triple.out").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
        // cout << (("sol.exe<test/test" + testCase(iTest) + "/triple.inp>ouBL")) << "\n";

    }
    return 0;
}
