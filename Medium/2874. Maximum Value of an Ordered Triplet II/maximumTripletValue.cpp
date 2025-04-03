class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long maxVal = 0;
            int max_i = 0, max_d = 0;
            for(int n : nums){
                maxVal = max(maxVal, (long long)max_d*n);
                max_d = max(max_d, max_i-n);
                max_i = max(max_i, n);
            }
            return maxVal;
        }
    };