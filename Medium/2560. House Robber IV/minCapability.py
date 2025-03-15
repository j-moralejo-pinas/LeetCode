class Solution:
    def minCapability(self, nums: List[int], k: int) -> int:
        values = sorted(list(set(nums)))
        left = 0
        right = len(values) - 1

        while left < right:
            middle = (left + right) // 2
            val = values[middle]
            stolen_houses = 0
            taken = False
            for n in nums:
                if taken:
                    taken = False
                elif n <= val:
                    stolen_houses += 1
                    taken = True
                    # if stolen_houses == k:
                    #     break

            if stolen_houses >= k:
                right = middle
            else:
                left = middle + 1
        return values[left]
