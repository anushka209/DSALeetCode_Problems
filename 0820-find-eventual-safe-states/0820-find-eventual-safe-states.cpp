class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      int n=graph.size();
      vector<int> RevAdj[n];
      vector<int>indegree(n,0);
      for(int i=0;i<n;i++)
      {
         for(auto it:graph[i])
         {
            RevAdj[it].push_back(i);   // it->i reverse the edges to solve it using indegree concept
            indegree[i]++;
         }
      }
      queue<int>q;
      for(int i=0;i<n;i++)
      {
        if(indegree[i]==0)
            q.push(i);
      }
      vector<int>safe;
      while(!q.empty())
      {
        int node=q.front();
        q.pop();
        safe.push_back(node);
        for(auto it:RevAdj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
                q.push(it);
        }
      }
      sort(safe.begin(),safe.end());
      return safe;
    }
};