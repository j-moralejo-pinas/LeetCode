#pragma GCC optimize(O3,unroll-loops)
#pragma GCC target(avx,mmx,sse2,sse3,sse4)

class Solution {
public:
    bool addNumber(vector<int32_t>& lexicographicalSequence, uint8_t idx,
                   vector<bool>& numbersToTest) {

        uint8_t nextIdx;
        for (uint8_t it = 0; it < numbersToTest.size(); it++) {
            if (!numbersToTest[it])
                continue;
            if (numbersToTest.size() - it > 1) {
                if (idx + numbersToTest.size() - it >= lexicographicalSequence.size() ||
                    lexicographicalSequence[idx + numbersToTest.size() - it] > 0) {
                    continue;
                }
                    lexicographicalSequence[idx + numbersToTest.size() - it] = numbersToTest.size() - it;
                
            }
            
                lexicographicalSequence[idx] = numbersToTest.size() - it;
                numbersToTest[it] = false;
                nextIdx = idx + 1;
                for (; nextIdx < lexicographicalSequence.size(); nextIdx++) {
                    if (lexicographicalSequence[nextIdx] == 0) {
                        break;
                    }
                }
                if (nextIdx == lexicographicalSequence.size()) {
                    return true;
                }

                if (addNumber(lexicographicalSequence, nextIdx,
                              numbersToTest)) {
                    return true;
                }
                numbersToTest[it] = true;
                lexicographicalSequence[idx] = 0;
                if (numbersToTest.size() - it > 1) {
                    lexicographicalSequence[idx + numbersToTest.size() - it] = 0;
                }
            
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int32_t> lexicographicalSequence(n * 2 - 1, 0);
        vector<bool> numbersToTest(n, true);
        addNumber(lexicographicalSequence, 0, numbersToTest);
        return lexicographicalSequence;
    }
};