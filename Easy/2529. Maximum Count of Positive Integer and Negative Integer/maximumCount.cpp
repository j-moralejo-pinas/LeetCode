class Solution {
    public:
        short return_right(vector<int>& nums, short left, short num_to_check) {
    
            short right = nums.size();
            short middle = (right + left) / 2;
    
            while (middle > left && right > 0) {
                if (nums[middle] > num_to_check) {
                    right = middle;
                } else {
                    left = middle;
                }
                middle = (right + left) / 2;
            }
    
            return right;
        }
    
        int maximumCount(vector<int>& nums) {
    
            short max_positive_negative_numbers = return_right(nums, -1, -1);
    
            max_positive_negative_numbers =
                max(max_positive_negative_numbers,
                    (short)((int)nums.size() -
                        return_right(nums, max_positive_negative_numbers - 1, 0)));
    
            return max_positive_negative_numbers;
        }
    };