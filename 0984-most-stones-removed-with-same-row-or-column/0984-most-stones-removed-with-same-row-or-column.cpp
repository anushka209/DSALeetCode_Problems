class Solution {
public:
    vector<int>row[10001],col[10001];
    bitset<1001>vis; 

    void dfs(int idx, vector<vector<int>>& stones)
    {
        int i=stones[idx][0],j=stones[idx][1];
        vis[idx]=1;
        for(auto k:row[i])
        {
            if(!vis[k])
                dfs(k,stones);
        }
        for(auto k:col[j])
        {
            if(!vis[k])
                dfs(k,stones);
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        for(int idx=0;idx<n;idx++)
        {
            int i=stones[idx][0],j=stones[idx][1];
            row[i].push_back(idx);
            col[j].push_back(idx);
        }
        int comp=0;
        for(int idx=0;idx<n;idx++)
        {
            int i=stones[idx][0],j=stones[idx][1];
            if(!vis[idx])
            {
                dfs(idx,stones);
                comp++;
            }
        }
        return n-comp;
    }
};