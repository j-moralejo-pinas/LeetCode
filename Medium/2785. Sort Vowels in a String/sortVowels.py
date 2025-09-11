index_to_vowel = ["A", "E", "I", "O", "U", "a", "e", "i", "o", "u"]
vowel_to_index = {v: i for i, v in enumerate(index_to_vowel)}
class Solution:
    def skip_consonants(self, s: str, new_s_list: list[str], index: int) -> int:
        while index < len(s) and s[index] not in vowel_to_index:
            new_s_list.append(s[index])
            index += 1
        return index
    def sortVowels(self, s: str) -> str:
        vowel_count = [0] * 10
        for c in s:
            if c in vowel_to_index:
                vowel_count[vowel_to_index[c]] += 1
        c_index = 0
        new_s_list = []
        c_index = self.skip_consonants(s, new_s_list, c_index)
        for v_index, count in enumerate(vowel_count):
            vowel = index_to_vowel[v_index]
            for _ in range(count):
                new_s_list.append(vowel)
                c_index = self.skip_consonants(s, new_s_list, c_index + 1)
        return "".join(new_s_list)