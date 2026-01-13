#include <bits/stdc++.h>
using namespace std;

void solve(){
    /*
    we know  primes factors : p1^a1*p2^a2*p3^a3...........pk^ak
    so for numbers of factors formula = (a1+1)*(a2+1)*(a3+1).....(ak+1)
    example: n = 12
        12 = 2^2*3^1
        nof = (2+1)*(1+1) = 3*2 = 6

        ak = number of times of pk and pk is  number which divides n
    */
    long long n;
    cin >>n;
    long long ans=1;
    long long count;
    for (long long i = 2; i*i<=n; i++) { // i*i because we can find factors till its sqrt 
        count = 0;
        while(n%i==0){
            count++;
            n = n/i;
        }

        ans*=(count+1); // used formula given above
    }

    if(n>1) ans*=2; // if n is prime so ans = 2 (1,n) because int-{1,n} can't divide prime number
    cout << ans << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}