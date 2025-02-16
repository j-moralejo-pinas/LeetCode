import heapq


class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        x = len(nums)
        y = 0
        while y < x:
            if nums[y] >= k:
                x -= 1
                while nums[x] >= k and x > y:
                    x -= 1
                nums[y] = nums[x]
            y += 1
        del nums[x:]

        heapq.heapify(nums)
        x = 0
        while len(nums) > 1:
            y = heapq.heappop(nums) * 2 + nums[0]
            if y < k:
                heapq.heapreplace(nums, y)
            else:
                heapq.heappop(nums)
            x += 1

        return x + 1 if nums else x
