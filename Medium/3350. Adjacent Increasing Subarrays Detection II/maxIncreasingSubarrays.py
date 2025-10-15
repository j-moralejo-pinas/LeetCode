class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        prev_subarray_length = 1
        curr_subarray_length = 1
        best_score = 1

        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                curr_subarray_length += 1
            else:
                best_score = max(
                    min(curr_subarray_length, prev_subarray_length),
                    curr_subarray_length // 2,
                    best_score,
                )
                prev_subarray_length = curr_subarray_length
                curr_subarray_length = 1

        return max(
            min(curr_subarray_length, prev_subarray_length),
            curr_subarray_length // 2,
            best_score,
        )
