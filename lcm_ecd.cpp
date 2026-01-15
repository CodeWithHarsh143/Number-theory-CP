#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a , long long b){
    while(b!=0){
        long long r = a%b;
        a=b;
        b=r;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    /*
    we know lcm(a,b)*gcd(a,b) = a*b
    --->lcm(a,b) = a*b/gcd(a,b)    
    */

    long long a,b,lcm;
    cin >> a >> b;
    lcm = (a/gcd(a,b))*b; // for preventing overflow
    cout << lcm << endl;
    

    return 0;

}
