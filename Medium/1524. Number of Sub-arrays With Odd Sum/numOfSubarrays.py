class Solution:

    def numOfSubarrays(self, arr: List[int]) -> int:
        num_odd_sub_arrays = num_odd = num_even = 0
        for i in arr:
            num_even += 1
            if i % 2:
                num_odd, num_even = num_even, num_odd
            num_odd_sub_arrays += num_odd

        return num_odd_sub_arrays % (1000000007)
