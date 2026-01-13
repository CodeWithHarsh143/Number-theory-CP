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
    /*
    if n is not perfect square = n^f/2
    if n is perfect square = n^(f-1)/2*(sqrt(n))   
    */

    long long original = n;
    long long total_factors = 1;

    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            long long cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            total_factors *= (cnt + 1);
        }
    }

    if (n > 1) total_factors *= 2;

    long long root = sqrt(original);
    long long product;

    if (root * root == original) {
        // perfect square
        product = fastPow(original, (total_factors - 1) / 2) * root;
    } else {
        product = fastPow(original, total_factors / 2);
    }

    cout << product << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
