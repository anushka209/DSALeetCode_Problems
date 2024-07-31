class Solution {
public:
    int width;
    int solve(vector<vector<int>>& books,int n,int idx, int remWidth,int height,vector<vector<int>> &dp)
    {
        if(idx>=n) return height;
        int bookW=books[idx][0];
        int bookH=books[idx][1];

        if(dp[idx][remWidth]!=-1) return dp[idx][remWidth];

        int keep=INT_MAX;
        int skip=INT_MAX;

        //keep
        if(bookW<=remWidth)
            keep=solve(books,n,idx+1,remWidth-bookW,max(height,bookH),dp);

        //skip and put in next shelf
        skip=height + solve(books,n,idx+1,width-bookW,bookH,dp);
        return dp[idx][remWidth]=min(keep,skip);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        width=shelfWidth;
        vector<vector<int>>dp(n+1,vector<int>(shelfWidth+1,-1));
        return solve(books,n,0,shelfWidth,0,dp);
    }
};