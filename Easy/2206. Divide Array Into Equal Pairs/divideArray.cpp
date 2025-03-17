class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            vector<bool> numsWithoutPair(501);
    
            for (int& n : nums) {
                numsWithoutPair[n] = !numsWithoutPair[n];
            }
            for (bool val : numsWithoutPair) {
                if (val) {
                    return false;
                }
            }
            return true;
        }
    };