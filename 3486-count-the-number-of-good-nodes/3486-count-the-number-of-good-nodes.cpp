class Solution {
public:
    int goodNodes=0;

    int dfs(int node, int parent,vector<vector<int>> &adj) {
        int subtreeSize=1;
        unordered_set<int>s;

        for(int it : adj[node])
        {
            if(it==parent) continue;
            int currentSize = dfs(it,node,adj);
            subtreeSize += currentSize;
            s.insert(currentSize);
        }
        if(s.size()<=1)  //if <1 then leaf node or if =1 then only 1 node
            goodNodes++;
        return subtreeSize;
    }
    
    int countGoodNodes(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>> adj(n);

        for(auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1,adj);
        return goodNodes;
    }
};