class Solution {
public:
    bool dfs(int node,int col,vector<int>& color,vector<vector<int>>& graph)
    {
       color[node]=col;
       for(auto it : graph[node])
       {
         if(color[it]==-1)
         {
            if(dfs(it,!col,color,graph)==false)
                return false;
         }
         else if(color[it]==color[node])
            return false;
       }
       return true;
    }

    bool isBipartite(vector<vector<int>>& graph) 
    {
        // int n=graph.size();   // by BFS
        // vector<int> color(n,-1);
        // for(int i=0;i<n;i++)        // Check each component of the graph
        // {
        //    if(color[i]==-1)
        //    {
        //       queue<int>q;
        //       q.push(i);
        //       color[i]=0;

        //       while(!q.empty())
        //       {
        //         int node=q.front();
        //         q.pop();
        //         for(auto it : graph[node])
        //         {
        //             if(color[it]==-1)          //if the adjacent node is yet not colored, give opposite color to the node
        //             {
        //                 color[it]=!color[node];
        //                 q.push(it);
        //             }
        //          //if the adjacent having the same color not a bipartite graph
        //             else if(color[it]==color[node])
        //                 return false;
        //             }
        //         }
        //       }
        //    }
        // return true;

       int n=graph.size();
       vector<int>color(n,-1);   // dfs
       for(int i=0;i<n;i++)       //for components
       {
         if(color[i]==-1)
         {
            if(dfs(i,0,color,graph)==false)
                return false;
         }
       }
       return true;
    }
};