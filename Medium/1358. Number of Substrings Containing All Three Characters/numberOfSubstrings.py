class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        num_substrings = 0
        last_positions = [-1,-1,-1]
        for idx, letter in enumerate(s):
            last_positions[ord(letter) - 97] = idx
            num_substrings += min(last_positions) + 1
        return num_substrings