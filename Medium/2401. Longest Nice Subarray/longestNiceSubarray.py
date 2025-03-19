class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        longest = []
        first_pos = 0
        elem_sum = 0
        for idx, e in enumerate(nums):
            if e & elem_sum != 0:
                longest.append(idx - first_pos)
                while e & elem_sum != 0:
                    elem_sum ^= nums[first_pos]
                    first_pos += 1
            elem_sum |= e
        longest.append(len(nums) - first_pos)
        return max(longest)

    def longestNiceSubarray_less_memory_slower(self, nums: List[int]) -> int:
        longest = 0
        first_pos = 0
        elem_sum = 0
        for idx, e in enumerate(nums):
            if e & elem_sum != 0:
                longest = max(longest, idx - first_pos)
                while e & elem_sum != 0:
                    elem_sum ^= nums[first_pos]
                    first_pos += 1
            elem_sum |= e
        return max(longest, len(nums) - first_pos)
