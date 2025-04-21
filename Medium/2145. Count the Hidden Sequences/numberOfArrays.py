class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        max_val = 0
        min_val = 0
        curr_val = 0
        for d in differences:
            curr_val += d
            if curr_val > max_val:
                max_val = curr_val
            elif curr_val < min_val:
                min_val = curr_val
        return max(0, 1 + upper - lower - max_val + min_val)