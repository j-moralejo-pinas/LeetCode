class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        count = 0
        for i, n in enumerate(nums):
            for j in range(i+1, len(nums)):
                if (i * j) % k == 0 and n == nums[j]:
                    count += 1
                
        return count