class Solution {
public:
    // int f(int i,int j,string &s, string &p,vector<vector<int>>& dp)   //memoization
    // {
    //     if(i<0 && j<0) return true;  //base cases
    //     if(i<0 && j>=0) return false;
    //     if(j<0 && i>=0)
    //     {
    //         for(int x=0;x<=i;x++)
    //         {
    //             if(p[x]!='*')
    //                 return false;
    //         }
    //         return true;
    //     }
    //     if(dp[i][j]!=-1) return dp[i][j];

    //     if(s[i]==p[j] || p[j]=='?')
    //         return dp[i][j]=f(i-1,j-1,s,p,dp);
    //     if(p[j]=='*')
    //         return dp[i][j]=f(i-1,j,s,p,dp) || f(i,j-1,s,p,dp);
    //     return dp[i][j]=false;
    // }

    bool all(string& s, int j) {
        for(int i=1; i<=j; i++) {
            if(s[i-1] != '*') return false;
        }
        return true;
    } 

    bool isMatch(string s, string p) {
        // int n=s.size();
        // int m=p.size();
        // vector<vector<bool>>dp(n+1,vector<bool>(m+1,0));
        // dp[0][0]=true;
        // for(int i=1;i<=n;i++)    //base cases
        // {
        //     dp[i][0]=false;
        // }
        // for(int j=1;j<=m;j++)
        // {
        //     bool flag=true;
        //     for(int x=1;x<=j;x++)
        //     {
        //         if(s[x-1]!='*')
        //         {
        //             flag=false;
        //             break;
        //         }
        //     }
        //     dp[0][j]=flag;
        // }

        // for(int i=1;i<=n;i++)
        // {
        //     for(int j=1;j<=m;j++)
        //     {
        //         if(s[i-1]==p[j-1] || p[j-1]=='?')
        //             dp[i][j]=dp[i-1][j-1];
        //         else if(p[j-1]=='*')
        //             dp[i][j]=dp[i-1][j] || dp[i][j-1];
        //         else
        //             dp[i][j]=false;
        //     }
        // }
        // return dp[n][m];

         int n = s.size();
        int m = p.size();

        vector<vector<bool>> dp(n+1, vector<bool>(m+1, 0));

        dp[0][0] = true;

        for(int j=1; j<=m; j++) {
            dp[0][j] = all(p, j);
        }

        for(int i=1; i<=n; i++) {
            dp[i][0] = false;
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i-1] == p[j-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    if(p[j-1] == '*') {
                        dp[i][j] = dp[i-1][j] || dp[i][j-1];
                    }
                    else dp[i][j] = false;
                }
            }
        }
        
        return dp[n][m];
    }
};