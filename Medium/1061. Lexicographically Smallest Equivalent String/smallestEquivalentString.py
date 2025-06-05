class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        connected_chars = [set([i]) for i in range(26)]
        for c1, c2 in zip(s1, s2):
            i1 = ord(c1) - ord("a")
            i2 = ord(c2) - ord("a")
            if connected_chars[i1] != connected_chars[i2]:
                if len(connected_chars[i1]) > len(connected_chars[i1]):
                    connected_chars[i1].update(connected_chars[i2])
                    for i3 in connected_chars[i2]:
                        connected_chars[i3] = connected_chars[i1]
                else:
                    connected_chars[i2].update(connected_chars[i1])
                    for i3 in connected_chars[i1]:
                        connected_chars[i3] = connected_chars[i2]
        for idx, cc in enumerate(connected_chars):
            if isinstance(cc, set):
                min_val = chr(min(cc) + ord("a"))
                for c_idx in cc:
                    connected_chars[c_idx] = min_val

        new_string_list = [connected_chars[ord(c) - ord("a")] for c in baseStr]

        return "".join(new_string_list)
