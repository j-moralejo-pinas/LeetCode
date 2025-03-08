class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        sum_whites = 0
        for i in range(k):
            if blocks[i] == "W":
                sum_whites += 1

        min_whites = sum_whites

        for i in range(1, len(blocks) - k + 1):
            if blocks[i - 1] == "W":
                sum_whites -= 1
            if blocks[i + k - 1] == "W":
                sum_whites += 1
            min_whites = min(min_whites, sum_whites)

        return min_whites
