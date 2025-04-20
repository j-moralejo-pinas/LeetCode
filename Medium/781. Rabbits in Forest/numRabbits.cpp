class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            unordered_map<short, int> countedRabbits;
            int minRabbits = 0;
            for (int a : answers){
                countedRabbits[a] += 1;
                if (countedRabbits[a] == a + 1){
                    minRabbits += a + 1;
                    countedRabbits.erase(a);
                }
            }
            for (auto& pair : countedRabbits){
                minRabbits += pair.first + 1;
            }
            return minRabbits;
        }
    };