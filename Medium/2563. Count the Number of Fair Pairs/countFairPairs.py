class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        
        max_right_idx = len(nums)
        count = 0
        for i, n in enumerate(nums):
            if i >= max_right_idx or i >= len(nums) - 1 and n + nums[i+1] > upper:
                break
            max_val = upper - n
            min_val = lower - n
            left = i + 1
            right = max_right_idx
            while left < right - 1:
                middle = (left + right) // 2
                if nums[middle] <= max_val:
                    left = middle
                else:
                    right = middle
            max_right_idx = right
            left = i
            while left < right - 1:
                middle = (left + right) // 2
                if nums[middle] < min_val:
                    left = middle
                else:
                    right = middle
            count += (max_right_idx - right)

        return count