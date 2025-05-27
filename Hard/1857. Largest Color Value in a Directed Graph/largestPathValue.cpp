class Solution {
public:
    bool recursiveSearchBestPath(int node, vector<vector<int>>& adjacencyList,
                                 vector<bool>& visitedNodes,
                                 vector<bool>& currentPath,
                                 vector<array<int, 26>>& colorValues,
                                 string& colors) {
        visitedNodes[node] = true;
        currentPath[node] = true;

        for (int n : adjacencyList[node]) {

            if (currentPath[n]) {
                return true;
            } else if (!visitedNodes[n]) {
                if (recursiveSearchBestPath(n, adjacencyList, visitedNodes,
                                            currentPath, colorValues, colors)) {
                    return true;
                }
            }

            for (int i = 0; i < 26; ++i) {
                colorValues[node][i] =
                    max(colorValues[node][i], colorValues[n][i]);
            }
        }

        colorValues[node][colors[node] - 'a']++;
        currentPath[node] = false;

        return false;
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        vector<vector<int>> adjacencyList(colors.size(), vector<int>());
        for (vector<int>& e : edges) {
            adjacencyList[e[0]].push_back(e[1]);
        }

        vector<array<int, 26>> colorValues(colors.size());
        vector<bool> visitedNodes(colors.size());
        vector<bool> currentPath(colors.size());

        int bestNumber = 0;

        for (int i = 0; i < colors.size(); ++i) {
            if (!visitedNodes[i]) {
                if (recursiveSearchBestPath(i, adjacencyList, visitedNodes,
                                            currentPath, colorValues, colors)) {
                    return -1;
                }
                for (int c : colorValues[i]) {
                    bestNumber = max(bestNumber, c);
                }
            }
        }
        return bestNumber;
    }
};