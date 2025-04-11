class Solution:
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        count = 0
        for i in range(low, high + 1):
            if 1000 <= i < 10000:
                first = i % 100
                second = i // 100
                if first % 10 + first // 10 == second % 10 + second // 10:
                    count += 1
            elif i < 100:
                if i % 11 == 0:
                    count += 1
        return count