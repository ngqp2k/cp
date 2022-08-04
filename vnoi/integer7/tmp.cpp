#include <stdio.h>

#include <algorithm>
using namespace std;

#define long long long
typedef pair<long, long> ii;
#define X first
#define Y second

ii extended_gcd(long a, long b) {
    ii qr, st;
    if (b == 0)
        return ii(1, 0);
    else {
        qr = ii(a / b, a % b);
        st = extended_gcd(b, qr.Y);
        return ii(st.Y, st.X - qr.X * st.Y);
    }
}

long gcd(long a, long b) {
    if (a == 0)
        return b;
    else
        return gcd(b % a, a);
}

long a, b, c, g;
int main() {
    scanf("%lld%lld%lld", &a, &b, &c);
    g = gcd(a, b);
    ii st = extended_gcd(a, b);
    printf("%lld %lld\n", c / g * st.X, c / g * st.Y);
}
