class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        people_know_n_days = [0] * forget
        people_know_n_days[0] = 1
        people_that_spread = 0
        people_that_know = 1
        zero_index = 1
        for _ in range(n - 1):
            people_that_spread += people_know_n_days[zero_index - delay]
            substract = people_know_n_days[zero_index - forget]
            people_that_spread -= substract
            people_that_know += people_that_spread
            people_that_know -= substract
            people_know_n_days[zero_index] = people_that_spread

            zero_index = zero_index + 1
            if zero_index == forget:
                zero_index = 0

        return people_that_know % (1000000007)
