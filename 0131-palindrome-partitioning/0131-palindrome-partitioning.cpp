class Solution {
public:
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>>ans;
        vector<string>res;
        find(0,s,res,ans);
        return ans;
    }

    void find(int idx,string s,vector<string>& res,vector<vector<string>>& ans)
    {
        if(idx==s.size())              //base case
        {
            ans.push_back(res);
            return;
        }
        for(int i=idx;i<s.size();i++)
        {
            if(isPalindrome(s,idx,i))
            {
                res.push_back(s.substr(idx,i-idx+1));
                find(i+1,s,res,ans);
                res.pop_back();         //for backtracking
            }
        }
    }

    bool isPalindrome(string s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--])
               return false;
        }
        return true;
    }
};