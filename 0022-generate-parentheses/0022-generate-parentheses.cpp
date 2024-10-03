class Solution {
public:
    void find(string curr,int open,int close,int n,vector<string>& ans)
    {
        if(curr.size()==2*n)
        {
            ans.push_back(curr);
            return;
        }
        if(open<n)
            find(curr+'(',open+1,close,n,ans);
        if(close<open)
            find(curr+')',open,close+1,n,ans);
    }

    vector<string> generateParenthesis(int n) {
      vector<string>ans;
      find("",0,0,n,ans);
      return ans;
    }
};