class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        max_i = 0
        max_d = 0
        max_val = 0

        for n in nums:
            max_val = max(max_val, max_d * n)
            max_d = max(max_d, max_i - n)
            max_i = max(n, max_i)

        return max_val

    def maximumTripletValue_slower(self, nums: List[int]) -> int:
        biggest_left = [nums[0]] * (len(nums) - 2)
        biggest_right = [nums[-1]] * (len(nums) - 2)

        for i in range(1, len(nums) - 2):
            biggest_left[i] = max(nums[i], biggest_left[i - 1])
            biggest_right[-i - 1] = max(nums[-i - 1], biggest_right[-i])

        max_val = 0
        for i in range(len(biggest_left)):
            max_val = max((biggest_left[i] - nums[i + 1]) * biggest_right[i], max_val)

        return max_val
