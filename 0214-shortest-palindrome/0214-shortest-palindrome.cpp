class Solution {
public:
    string shortestPalindrome(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        string temp=s+"#"+rev;
        vector<int>ans(temp.length(),0);
        int len=0,i=1;
        while(i<temp.length())
        {
            if(temp[i]==temp[len])
            {
                ans[i]=++len;
                i++;
            }
            else if(len>0)
                len=ans[len-1];
            else
                i++;
        }
        string add=s.substr(ans.back());
        reverse(add.begin(),add.end());
        return add+s;
    }
};