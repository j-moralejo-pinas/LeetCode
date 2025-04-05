class Solution {
    public:
        int recursive(vector<int>& nums, int currPos, int currVal) {
            currVal ^= nums[currPos];
            int totalSum = currVal;
    
            for (currPos++; currPos < nums.size(); currPos++) {
                totalSum += recursive(nums, currPos, currVal);
            }
            return totalSum;
        }
        int subsetXORSum(vector<int>& nums) {
            int totalSum = 0;
    
            for (int i = 0; i < nums.size(); i++) {
                totalSum += recursive(nums, i, 0);
            }
            return totalSum;
        }
    };