#include <bits/stdc++.h>
using namespace std;

long long fastPow(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res *= base;
        base *= base;
        exp >>= 1;
    }
    return res;
}

void solve() {
    long long n;
    cin >> n;

    long long temp = n;
    long long ans = 1;

    for (long long i = 2; i * i <= temp; i++) {
        if (temp % i == 0) {
            long long cnt = 0;
            while (temp % i == 0) {
                cnt++;
                temp /= i;
            }
            ans *= (fastPow(i, cnt + 1) - 1) / (i - 1);
        }
    }

    // If a prime factor > 1 remains
    if (temp > 1) {
        ans *= (temp + 1);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
