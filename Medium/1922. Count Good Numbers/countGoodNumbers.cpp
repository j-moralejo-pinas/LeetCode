class Solution {
    public:
        long long ipow(long long base, long long exp) {
            long long result = 1;
            for (;;) {
                if (exp & 1)
                    result = (result * base) % 1000000007;
                exp >>= 1;
                if (!exp)
                    break;
                base = (base * base) % 1000000007;
            }
    
            return result;
        }
    
        int countGoodNumbers(long long n) {
            long long odd = n / 2;
            long long even = (n + 1) / 2;
            return (int)((ipow(5, even) * ipow(4, odd)) % 1000000007);
        }
    };