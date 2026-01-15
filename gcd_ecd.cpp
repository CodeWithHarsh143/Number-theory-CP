#include <bits/stdc++.h>
using namespace std;

long long recursive_eucl_gcd(long long a, long long b){
    a = llabs(a);
    b = llabs(b);// to make it positive
    return (b==0)? a: recursive_eucl_gcd(b,a%b);
}

long long itrative_eucl_gcd(long long a , long long b){
    // preferd in cp
    a = llabs(a);
    b = llabs(b);
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
    we know gcd(a,b) = gcd(a-b,b) if a>=b
    so we can use this proberty till a>=b or we can say a==0
    then we know gcd(a,0) or gcd(0,b) = a or b
   expample gcd(a-b,b) = gcd((a-b)-b,b) = gcd((a-b)-2b,b) jab tal a<b na hojye or 0 nai hojye
    means a-b jab tak neg nai hojye
    so a-b -> a-2b -> a-3b -> a-4b -> till a<b or a-b became neg lets suppose it take q steps and every time
    we take a-q*b we get remaining which left( bacially remender) 
    so we can write as a-q*b = r ( and we know remender = a%b)
    so, a-q*b = a%b ( a minus multiple of b  =  remender (that's what a%b does))
    -----> a-q*b = a%b
    -----> gcd(a,b) = gcd(a-q*b,b)
    -----> gcd(a,b) = gcd(r,b)
    -----> gcd(a,b) = gcd(b,a%b) (swap because till q a became less than b so a became big it or till b became zero because gcd(a,0) = a)
    we know when a<b then a%b = a---(1)
    so after gcd(a,b) --> swap -- > gcd(b,a%b) =gcd(b,a) using eq (1) so in this step nothing is reduce but we swap it
    Time complexity: O(log(min(a,b))
    space Complexity: O(1)
    */
    long long ans;
    long long a, b;
    cin >> a >> b;
    ans = itrative_eucl_gcd(a,b);
    cout << ans << endl;
    return 0;

}
