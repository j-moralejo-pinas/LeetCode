class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:

        if len(nums) < 2:
            return nums
        last_zero = 0

        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1]:
                if nums[i] != 0:
                    nums[i - 1] = 0
                    nums[last_zero] = nums[i] * 2
                    nums[i] = 0
                    last_zero += 1
            else:
                if nums[i - 1] != 0:
                    if i - 1 > last_zero:
                        nums[last_zero] = nums[i - 1]
                        nums[i - 1] = 0
                    last_zero += 1

        if nums[-1] != 0:
            aux = nums[-1]
            nums[-1] = 0
            nums[last_zero] = aux
        return nums
