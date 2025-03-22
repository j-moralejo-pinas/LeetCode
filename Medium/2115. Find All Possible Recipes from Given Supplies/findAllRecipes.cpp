class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            unordered_map<string, vector<int>> recPerIng;
            vector <int> ingFound(recipes.size(), 0);
            vector <int> nIng;
            vector<string> outRecipes;
            for (int i = 0; i < recipes.size(); i++){
                nIng.push_back(ingredients[i].size());
                for (string& ing : ingredients[i]){
                    recPerIng[ing].push_back(i);
                }
            }
            for (int j = 0; j < supplies.size(); j++){
                vector<int>& recList = recPerIng[supplies[j]];
                for (int i = 0; i < recList.size(); i++){
                    int recListI = recList[i];
                    ingFound[recListI]++;
                    if (ingFound[recListI]>= nIng[recListI]){
                        supplies.push_back(recipes[recListI]);
                        outRecipes.push_back(move(recipes[recListI]));
                    }
                }
            }
    
            return outRecipes;
        }
    };