class Solution:
    def maxDistinctElements(self, nums: List[int], k: int) -> int:
        nums.sort()
        unique_count = 0
        curr_min_unique = -1e10
        for n in nums:
            min_val = max(curr_min_unique, n - k)
            if min_val <= n + k:
                unique_count += 1
                curr_min_unique = min_val + 1
        return unique_count
