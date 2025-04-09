class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        nums = set(nums)
        if min(nums) < k:
            return -1
        if k in nums:
            return len(nums) - 1
        return len(nums)
