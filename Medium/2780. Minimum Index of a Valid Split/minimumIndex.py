class Solution:
    def minimumIndex(self, nums: List[int]) -> int:
        counts = {}
        half_size = (len(nums) + 1) / 2
        max_val = -1
        for n in nums:
            if not n in counts:
                counts[n] = 0
            counts[n] += 1
        #     if counts[n] > half_size:
        #         max_val = n
        #         break
        # if max_val < 0:
        #     return -1
        for v, count in counts.items():
            if count > half_size:
                max_val = v
                counts.clear()
                break

        if max_val < 0:
            return -1
        dominant_left = 1
        for i, n in enumerate(nums):
            if n == max_val:
                dominant_left -= 1
                if dominant_left == 0:
                    # index = i
                    break
            else:
                dominant_left += 1
        return i
