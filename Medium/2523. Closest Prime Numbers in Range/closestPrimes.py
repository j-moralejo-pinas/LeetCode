class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:

        numbers = [True] * (right + 1)
        numbers[0] = False
        numbers[1] = False

        best_prime_pair = [-1, -1]
        lowest_prime_dist = math.inf
        last_prime = -1

        for i in range(2, int(sqrt(right)) + 1):
            if numbers[i]:
                if i >= left:
                    if last_prime > 0:
                        curr_dist = i - last_prime
                        if lowest_prime_dist > curr_dist:
                            lowest_prime_dist = curr_dist
                            best_prime_pair[0] = last_prime
                            best_prime_pair[1] = i
                            if curr_dist <= 2:
                                return best_prime_pair
                    last_prime = i

                for m in range(i * i, right + 1, i):
                    numbers[m] = False

        for i in range(int(sqrt(right)) + 1, right + 1):
            if numbers[i]:
                if i >= left:
                    if last_prime > 0:
                        curr_dist = i - last_prime
                        if lowest_prime_dist > curr_dist:
                            lowest_prime_dist = curr_dist
                            best_prime_pair[0] = last_prime
                            best_prime_pair[1] = i
                            if curr_dist <= 2:
                                return best_prime_pair
                    last_prime = i

        return best_prime_pair
