class Solution {
public:
    vector<vector<int>> adj;
    vector<int> subtreeSize;
    int goodNodes = 0;

    int dfs(int node, int parent) {
        int totalNodes=1;
        int childSize = -1;
        bool isGood = true;
    
        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;
        
            int currentSize = dfs(neighbor, node);
        
            if (childSize == -1) {
                childSize = currentSize;
            } else if (childSize != currentSize) {
                isGood = false;
            }  
            totalNodes += currentSize;
        }
    
        if (isGood) goodNodes++;
        return totalNodes;
    }
    
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        adj.resize(n);
        subtreeSize.resize(n);
    
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1);
        return goodNodes;
    }
};