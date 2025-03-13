class Solution:
    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        num_queries = 0
        curr_val = 0
        skyline = [0] * (len(nums))
        for i, v in enumerate(nums):
            curr_val += skyline[i-1]

            while curr_val < v:
                if num_queries >= len(queries):
                    return -1
                if queries[num_queries][1] >= i:
                    if queries[num_queries][0] <= i:
                        curr_val += queries[num_queries][2]
                    else:
                        skyline[queries[num_queries][0]-1] += queries[num_queries][2]
                    skyline[queries[num_queries][1]] -= queries[num_queries][2]
                num_queries += 1

        return num_queries