class Solution {
public:
    const int MOD = 1e9 + 7;
    
    // Recursive fast power: computes (base^exp) % MOD in O(log exp)
    long long power(long long base, long long exp) {
        // Base case
        if (exp == 0) return 1;
        
        base %= MOD;
        
        // Recursive case: split exponent in half
        long long half = power(base, exp / 2);
        long long result = (half * half) % MOD;
        
        // If exponent is odd, multiply by one more 'base'
        if (exp % 2 == 1)
            result = (result * base) % MOD;
        
        return result;
    }
    int countGoodNumbers(long long n) {
        long long evenPositions = (n + 1) / 2; // ceil(n/2) — indices 0,2,4,...
        long long oddPositions  = n / 2;       // floor(n/2) — indices 1,3,5,...
        
        long long evenCount = power(5, evenPositions); // even digits: 0,2,4,6,8
        long long oddCount  = power(4, oddPositions);  // prime digits: 2,3,5,7
        
        return (int)((evenCount * oddCount) % MOD);
    }
};