#pragma GCC optimize(O3,unroll-loops)
#pragma GCC target(avx,mmx,sse2,sse3,sse4)

class Solution {
public:

    int recursiveSearch(unordered_map<char, uint8_t>& charCount){
        int totalSum = 0;
        for (unordered_map<char, uint8_t>::iterator it = charCount.begin(); it !=charCount.end(); it++){
            if(it->second > 0){
                totalSum++;
                it->second--;
                totalSum += recursiveSearch(charCount);
                it->second++;
            }
        }
        return totalSum;
    }
    int numTilePossibilities(string tiles) {
        unordered_map<char, uint8_t> charCount;
        unordered_map<char, uint8_t>::iterator mapIterator;
        for (string::iterator it = tiles.begin(); it!=tiles.end(); it++){
            mapIterator = charCount.insert(make_pair(*it, 0)).first;
            mapIterator->second++;
        }
        return recursiveSearch(charCount);
    }
};