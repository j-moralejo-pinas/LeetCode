#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")

class Solution {
public:
    bool isSumPartitionsEqualsToNumber(const uint_fast32_t numToPartition,
                                       const uint_fast32_t num, const uint_fast32_t currSum) {
        if (numToPartition + currSum == num) {
            return true;
        }
        uint_fast16_t divisor = 10;
        uint_fast32_t leftSide = numToPartition;
        while (leftSide > 0) {
            leftSide = numToPartition / divisor;
            if (isSumPartitionsEqualsToNumber(
                    leftSide, num, currSum + (numToPartition % divisor))) {
                return true;
            }
            divisor *= 10;
        }
        return false;
    }

    int punishmentNumber(int n) {
        uint_fast16_t i;
        uint_fast32_t sumPunishmentNumber = 0, sqI;
        for (i = 1; i <= n; i++) {
            sqI = i * i;
            if (isSumPartitionsEqualsToNumber(sqI, i, 0)) {
                sumPunishmentNumber += sqI;
            }
        }
        return sumPunishmentNumber;
    }
};