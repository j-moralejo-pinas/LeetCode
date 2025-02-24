class Solution {
    public:
        int dfsBob(vector<vector<int>>& edges, vector<int>& amount, int& prevBob,
                   int& bob, int dist) {
    
            if (bob == 0) {
                return dist;
            }
            int newDist;
            dist++;
            vector<int>& edgesBob = edges[bob];
            int edgesBobSize = edgesBob.size();
            for (int i = 0; i < edgesBobSize; i++) {
                if (edgesBob[i] == prevBob) {
                    continue;
                }
    
                newDist = dfsBob(edges, amount, bob, edgesBob[i], dist);
                if (newDist > 0) {
                    dist--;
                    int newDistDivTwo = newDist / 2;
                    if (dist == newDistDivTwo && newDist % 2 == 0) {
                        amount[bob] /= 2;
                    } else if (dist <= newDistDivTwo) {
                        amount[bob] = 0;
                    }
                    return newDist;
                }
            }
            return 0;
        }
    
        int dfs(vector<vector<int>>& edges, vector<int>& amount, int& prevAlice,
                int& alice) {
    
            vector<int>& edgesAlice = edges[alice];
            int edgesAliceSize = edgesAlice.size();
            if (alice != 0 && edgesAliceSize == 1) {
                return amount[alice];
            }
    
            int bestReward = INT_MIN;
    
            for (int i = 0; i < edgesAliceSize; i++) {
    
                if (edgesAlice[i] == prevAlice) {
                    continue;
                }
                bestReward =
                    max(bestReward, dfs(edges, amount, alice, edgesAlice[i]));
            }
    
            return bestReward + amount[alice];
        }
    
        int mostProfitablePath(vector<vector<int>>& edges, int bob,
                               vector<int>& amount) {
            vector<vector<int>> edgesMap(amount.size());
            for (vector<vector<int>>::iterator it = edges.begin();
                 it != edges.end(); ++it) {
    
                edgesMap[(*it)[0]].push_back((*it)[1]);
                edgesMap[(*it)[1]].push_back((*it)[0]);
            }
            dfsBob(edgesMap, amount, bob, bob, 0);
            int alice = 0;
            return dfs(edgesMap, amount, alice, alice);
        }
    };