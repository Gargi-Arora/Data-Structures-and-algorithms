class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        
        // 1. Skip leading whitespace
        while (i < n && s[i] == ' ') i++;
        
        // 2. Handle sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // 3. Recursively build the number, checking overflow as we go
        long result = convert(s, i, n, 0);
        result *= sign;
        
        // 4. Clamp to 32-bit int range
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;
        
        return (int)result;
    }
    private:
    long convert(const string &s, int i, int n, long acc) {
        // Base case: end of string or non-digit character
        if (i == n || !isdigit(s[i]))
            return acc;
        
        // Overflow guard — stop early so 'acc' never blows past safe range
        if (acc > INT_MAX) return acc; // will get clamped in caller anyway
        
        int digit = s[i] - '0';
        return convert(s, i + 1, n, acc * 10 + digit);
    }
};