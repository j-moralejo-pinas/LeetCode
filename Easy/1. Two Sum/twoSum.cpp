#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, uint16_t>> numsAndIndexes;
        numsAndIndexes.reserve(nums.size());
        array<int, 3> auxArray = {0, 0, 0};
        bool lastElementRepeated = false;
        for (; auxArray[0] < nums.size(); auxArray[0]++) {
            if (auxArray[0] > 0){
                if (auxArray[1] == nums[auxArray[0]]){
                    if (lastElementRepeated){
                        continue;
                    } else {
                        lastElementRepeated = true;
                    }
                } else {
                    lastElementRepeated = false;
                }
            }
            numsAndIndexes.push_back(make_pair(nums[auxArray[0]], auxArray[0]));
            auxArray[1] = nums[auxArray[0]];
        }
        sort(numsAndIndexes.begin(), numsAndIndexes.end(),
             [](pair<int, uint16_t> a, pair<int, uint16_t> b) { return a.first < b.first; });
        auxArray[0] = 0;
        auxArray[1] = (int)(numsAndIndexes.size() - 1);
        do {
            auxArray[2] = numsAndIndexes[auxArray[0]].first + numsAndIndexes[auxArray[1]].first;
            if (auxArray[2] > target) {
                auxArray[1]--;
            } else if (auxArray[2] < target) {
                auxArray[0]++;
            }
        } while (auxArray[2] != target);
        return vector<int>({numsAndIndexes[auxArray[0]].second, numsAndIndexes[auxArray[1]].second});
    }
};