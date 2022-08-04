// C++ program to compute
// factorial of big numbers
#include <iostream>
using namespace std;

#define MAX 100000


int multiply(int x, int res[], int res_size) {

// Initialize carry
    int carry = 0;

    for (int i = 0; i < res_size; i++) {
        int prod = res[i] * x + carry;

        // Store last digit of
        // 'prod' in res[]
        res[i] = prod % 10;

        // Put rest in carry
        carry = prod / 10;
    }

// Put carry in res and
// increase result size
    while (carry) {
        res[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    }
    return res_size;
}

void power(int x, int n)
{

    if (n == 0 ) {
        cout << "1";
        return;
    }
    int res[MAX];
    int res_size = 0;
    int temp = x;

    while (temp != 0) {
        res[res_size++] = temp % 10;
        temp = temp / 10;
    }

// Multiply x n times
// (x^n = x*x*x....n times)
    for (int i = 2; i <= n; i++)
        res_size = multiply(x, res, res_size);

    // cout << x << "^" << n << " = ";
    for (int i = res_size - 1; i >= 0; i--)
        cout << res[i];
}

int main() {
    // freopen("in", "r", stdin);
    freopen("ou", "w", stdout);
    int exponent = 2000;
    int base = 2000;
    power(base, exponent);
    return 0;
}
