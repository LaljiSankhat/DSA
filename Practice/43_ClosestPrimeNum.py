# leetcode 2523. Closest Prime Numbers in Range



from math import sqrt


def closestPrimes(left, right):

    # Sieve eratosthesis TC : O(n log(log n))
    # here we not find primes but we mark ans non prime which is not a prime no
    # we start from 2 then mark all multiple of 2 as not prime 
    # then do same for 3 and mark all multiples of 3 as not prime
    # we go unitll sqrt(n) 

    def get_primes():
        is_prime = [True] * (right + 1)
        is_prime[0] = is_prime[1] = False

        for n in range(2, int(sqrt(right)) + 1):
            if not is_prime[n]:
                continue
            for m in range(n + n, right + 1, n):
                is_prime[m] = False
        primes = []
        for i in range(len(is_prime)):
            if is_prime[i] and i >= left :
                primes.append(i)
        return primes    

    
    primes = get_primes() # get all primes from [left, right] inclusive 
    res = [-1, -1]
    diff = right  - left + 1


    for i in range(1, len(primes)):
        if primes[i] - primes[i - 1] < diff:
            diff = primes[i] - primes[i - 1]
            res = [primes[i - 1], primes[i]]



    return res

print(closestPrimes(10, 19))