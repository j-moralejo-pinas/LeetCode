class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        count_nums = [0] * value
        for n in nums:
            count_nums[n % value] += 1
        min_val = 0
        min_count = 100001
        for i in range(value):
            if count_nums[i] < min_count:
                min_count = count_nums[i]
                min_val = i
        return value * min_count + min_val
