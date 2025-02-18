#pragma GCC optimize(O3, unroll - loops)
#pragma GCC target(avx, mmx, sse2, sse3, sse4)

class Solution {

public:
    string smallestNumber(string pattern) {
        pattern.push_back('I');
        vector<char> st(pattern.size(), '0');
        uint8_t stIndex = 0, lastPIndex = 0;

        for (uint8_t i = 0; i < pattern.size(); i++) {
            st[stIndex] = i + '1';
            stIndex++;
            if (pattern[i] == 'I') {
                while (stIndex > 0) {
                    stIndex--;
                    pattern[lastPIndex] = st[stIndex];
                    lastPIndex++;
                }
            }
        }
        return pattern;
    }
};