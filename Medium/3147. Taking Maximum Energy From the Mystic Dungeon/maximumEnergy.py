class Solution:
    def maximumEnergy(self, energy: List[int], k: int) -> int:
        max_val = -1001
        for i in range(k):
            current_val = 0
            for j in range(len(energy) - 1 - i, -1, -k):
                current_val += energy[j]
                max_val = max(max_val, current_val)
        return max_val
