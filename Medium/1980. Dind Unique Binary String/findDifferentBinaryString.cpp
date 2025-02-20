class Solution {
public:
    bool testString(unordered_set<string>& numsSet, string& resString,
                    uint8_t idx) {
        if (idx == resString.size()) {
            if (numsSet.count(resString) == 0) {
                return true;
            }
        } else {
            resString[idx] = '0';
            if (testString(numsSet, resString, idx + 1))
                return true;
            resString[idx] = '1';
            if (testString(numsSet, resString, idx + 1))
                return true;
        }
        return false;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> numsSet(nums.begin(), nums.end());
        string resString(nums.size(), '0');
        testString(numsSet, resString, 0);
        return resString;
    }

    // And of course the truly intelligent idea that I couldn't think about was the maths trick that teachers use to demonstrate that there is more rational numbers than integer numbers
    string findDifferentBinaryString_alt(vector<string>& nums) {
        string resString(nums.size(), '0');
        for (int i = 0; i < nums.size(); i++) {
            resString[i] = (nums[i][i] == '0') ? '1' : '0'; 
        }
        return ans;
    }
};