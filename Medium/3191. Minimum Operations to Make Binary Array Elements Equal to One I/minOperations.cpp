class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int count = 0;
            int last = nums.size()-2;
            for (int i = 0; i < last; i++){
                if(!nums[i]){
                    nums[i+1] ^= 1;
                    nums[i+2] ^= 1;
                    count++;
                }
            }
            if (!(nums.back() && nums[last])){
                return -1;
            }
            return count;
        }
    };