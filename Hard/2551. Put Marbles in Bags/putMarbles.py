class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:
        if k == 1 or k == len(weights):
            return 0
        sum_elems = [weights[i] + weights[i + 1] for i in range(len(weights) - 1)]
        sum_elems.sort()

        return sum(sum_elems[1-k:]) - sum(sum_elems[:k-1])
        # max_list = []
        # min_list = []
        # for i in range(k - 1):
        #     sum_elems = weights[i] + weights[i + 1]
        #     heapq.heappush(max_list, sum_elems)
        #     heapq.heappush(min_list, -sum_elems)

        # for i in range(k - 1, len(weights) - 1):
        #     sum_elems = weights[i] + weights[i + 1]
        #     heapq.heappush(max_list, sum_elems)
        #     heapq.heappush(min_list, -sum_elems)
        #     heapq.heappop(max_list)
        #     heapq.heappop(min_list)

        # return sum(max_list) + sum(min_list)
