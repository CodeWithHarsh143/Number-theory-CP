def sieve():
    n = int(input())
    primes = [1 for _ in range(n+1)]
    primes[0],primes[1] = 0,0
    for i in range(2,int(n**0.5)+1):
        if primes[i]==1:
            j = i*i
            while j<=n:
                primes[j] = 0
                j+=i
    for i in range(2,n+1):
        if primes[i]==1:
            print(i)
