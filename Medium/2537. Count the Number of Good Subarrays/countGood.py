class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        left_pointer = 0
        count = defaultdict(int)

        good_subarrays = 0
        total_pairs = 0

        len_nums = len(nums)

        for right_pointer, n in enumerate(nums):
            total_pairs += count[n]
            count[n] += 1
            while total_pairs >= k:
                good_subarrays += len_nums - right_pointer
                count[nums[left_pointer]] -= 1
                total_pairs -= count[nums[left_pointer]]
                left_pointer += 1

        return good_subarrays
