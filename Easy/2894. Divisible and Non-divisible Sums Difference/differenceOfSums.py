class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        n_by_m = n // m
        sum_n_by_m = m * n_by_m * (n_by_m + 1) // 2
        del n_by_m
        sum_n = n * (n + 1) // 2
        return sum_n - sum_n_by_m - sum_n_by_m