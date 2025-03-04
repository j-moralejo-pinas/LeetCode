class Solution {
    public:
        bool checkPowersOfThree_worse(int n) {
            vector<int> powers = {1};
    
            while (powers.back() < n) {
                powers.push_back(powers.back() * 3);
            }
    
            for (vector<int>::reverse_iterator it = powers.rbegin();
                 it != powers.rend(); it++) {
                if (n - *it >= 0) {
                    n -= *it;
                }
                if (n == 0) {
                    break;
                }
            }
    
            return n == 0;
        }
    
        bool checkPowersOfThree(int n) {
            while (n > 0) {
                if (n % 3 == 2)
                    return false;
                n /= 3;
            }
            return true;
        }
    };