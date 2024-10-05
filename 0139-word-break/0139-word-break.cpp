class Solution {
public:
    unordered_set<string>st;
    int dp[301];
    bool solve(int idx,int n,string s,vector<string>& wordDict)
    {
        if(idx==n)
            return true;
        if(dp[idx]!=-1)  
            return dp[idx];
        if(st.find(s)!=st.end())
            return true;
        for(int l=1;l<=n;l++)
        {
            string temp=s.substr(idx,l);
            if(st.find(temp)!=st.end() && solve(idx+l,n,s,wordDict))
                return dp[idx]=true;
        }
        return dp[idx]=false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        for(string &word : wordDict)
            st.insert(word);
        return solve(0,n,s,wordDict);
    }
};