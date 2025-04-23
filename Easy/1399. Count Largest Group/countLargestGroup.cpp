class Solution {
    public:
        int countLargestGroup(int n) {
            vector<short> count(36, 0);
            char nGroupsMaxSize = 0;
            short maxSize = 0;
            for(; n >= 1; --n){
                char sum = 0;
                short j = n;
                while(j > 0){
                    sum += j % 10;
                    j /= 10;
                }
                sum -= 1;
                count[sum] += 1;
                if (count[sum] > maxSize) {
                    maxSize = count[sum];
                    nGroupsMaxSize = 1;
                } else if (count[sum] == maxSize){
                    nGroupsMaxSize += 1;
                }
            }
            return nGroupsMaxSize;
        }
    };