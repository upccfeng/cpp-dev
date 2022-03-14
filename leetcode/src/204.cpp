
#include "assert.h"
#include <vector>
#include <cmath>

namespace p_204
{
    class Solution {

        int removeMultiple(std::vector<bool>& primes, long long k) // Use long long avoid k*k overflow
        {
            int cnt = 0;
            for (long long i = k * k; i < primes.size(); i += k)
            {
                if (primes[i])
                {
                    cnt++;
                    primes[i] = false;
                }
            }

            return cnt;
        }

    public:
        int countPrimes(int n)
        {
            if (n < 2)
            {
                return 0;
            }

            std::vector<bool> primes(n, true);

            primes[0] = false;
            primes[1] = false;

            int cnt = n - 2;
            int bound = std::pow(primes.size() - 1, 0.5);
            for (int i = 2; i <= bound; i++)
            {
                if (primes[i])
                {
                    int removed = removeMultiple(primes, i);
                    cnt -= removed;
                }
            }

            return cnt;
        }
    };
} // namespace p_204

/*
# Problem:
https://leetcode.com/problems/count-primes/

## HINT:
* Use sieve method.
* Iterator from 2 -> sqrt(n)

## Time Complexity:
BigO(n * log(log(n))) by sieve of Eratosthenes

## Space Complexity:
BigO(n)
*/