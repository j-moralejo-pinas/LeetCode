class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        last_idx = [0]*101
        first_idx = -1
        for idx, n in enumerate(reversed(nums)):
            if last_idx[n] > 0:
                first_idx = len(nums) - idx - 1
                break
            last_idx[n] = 1
        first_idx //= 3
        return first_idx + 1
