class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int currPosValue = 0, currNegValue = 0, maxValue = 0;
            for (int i = 0; i < nums.size(); i++){
                currPosValue += nums[i];
                currNegValue += nums[i];
                currPosValue = max(0, currPosValue);
                currNegValue = min(0, currNegValue);
                maxValue = max(currPosValue, maxValue);
                maxValue = max(-currNegValue, maxValue);
            }
            return maxValue;
        }
    };