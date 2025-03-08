class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            uint8_t firstPointer = 0, lastPointer = k;
            int sumWhites = 0;
            for(; firstPointer < k; firstPointer++){
                if (blocks[firstPointer] == 'W'){
                    sumWhites++;
                }
            }
            int minWhites = sumWhites;
            for(firstPointer = 0; lastPointer < blocks.size(); firstPointer++, lastPointer++){
                if (blocks[firstPointer] == 'W'){
                    sumWhites--;
                }
                if (blocks[lastPointer] == 'W'){
                    sumWhites++;
                }
                minWhites = min(minWhites, sumWhites);
            }
            return minWhites;
        }
    };