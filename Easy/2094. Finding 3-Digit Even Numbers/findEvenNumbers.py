def recursive_search(
    digits: List[int], curr_val: int, new_digit: int
) -> List[int]:

    if curr_val >= 10:
        if new_digit & 1 == 0:
            curr_val *= 10
            curr_val += new_digit
            return [curr_val]
        return []

    curr_val *= 10
    curr_val += new_digit

    ret_list = []
    for i, n in enumerate(digits):
        if n > 0:
            digits[i] -= 1
            ret_list.extend(recursive_search(digits, curr_val, i))
            digits[i] += 1
    return ret_list

class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        counted_digits = [0] * 10
        for i in range(len(digits) - 1, -1, -1):
            counted_digits[digits[i]] += 1
            digits.pop()
        del digits
        ret_list = []
        for i in range(1, 10):
            if counted_digits[i] > 0:
                counted_digits[i] -= 1
                ret_list.extend(recursive_search(counted_digits, 0, i))
                counted_digits[i] += 1
        return ret_list
