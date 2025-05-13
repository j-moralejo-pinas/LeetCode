class Solution:
    def lengthAfterTransformations(self, s: str, t: int) -> int:

        num_characters = collections.deque([0] * 26)
        a = ord("a")
        for char in s:
            num_characters[ord(char) - a] += 1
        for _ in range(t):
            new_a_and_b = num_characters.pop()
            num_characters.appendleft(new_a_and_b)
            num_characters[1] += new_a_and_b

        return sum(num_characters) % 1000000007

    def lengthAfterTransformations_slower(self, s: str, t: int) -> int:
        num_characters = [0] * 26
        a = ord("a")
        for char in s:
            num_characters[ord(char) - a] += 1
        for _ in range(t):
            new_a_and_b = num_characters[-1]
            for c_idx in range(25, 0, -1):
                num_characters[c_idx] = num_characters[c_idx - 1]
            num_characters[0] = new_a_and_b
            num_characters[1] += new_a_and_b

        return sum(num_characters) % 1000000007
