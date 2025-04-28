class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        left = -1
        right = 0
        curr_sum = nums[0]
        n_subarrays = 0
        while True:
            subarray_len = right - left
            if curr_sum * subarray_len < k:
                n_subarrays += subarray_len
                right += 1
                if right >= len(nums):
                    break
                curr_sum += nums[right]
            else:
                left += 1
                curr_sum -= nums[left]
        return n_subarrays