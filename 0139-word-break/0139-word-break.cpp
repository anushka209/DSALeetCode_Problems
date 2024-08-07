class Solution {
public:
    unordered_set<string>st;
    int dp[301];
    bool find(int i,string &s)
    {
        if(i==s.size())
            return true;

        if(dp[i]!=-1) return dp[i];

        if(st.find(s)!=st.end())
            return true;
        for(int idx=1;idx<=s.size();idx++)
        {
            string temp=s.substr(i,idx);
            if(st.find(temp)!=st.end())
            {
                if(find(i+idx,s))
                    return dp[i]=true;
            }
        }
        return dp[i]=false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        // vector<bool>dp(n+1,false);
        memset(dp,-1,sizeof(dp));
       for(string &word: wordDict)
            st.insert(word);
        bool ans=find(0,s);
        return ans;
    }
};