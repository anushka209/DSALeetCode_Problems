class Solution {
public:
    vector<vector<string>> partition(string s) {
     vector<vector<string>>ans;
     vector<string>res;
     func(0,s,res,ans);
     return ans;
    }

    void func(int index,string s,vector<string> &res,vector<vector<string>>& ans)
    {
        if(index==s.size())       //base case
        {
            ans.push_back(res);
            return;
        }
        for(int i=index;i<s.size();i++)
        {
            if(isPalindrome(s,index,i))
            {
                res.push_back(s.substr(index,i-index+1));
                func(i+1,s,res,ans);
                res.pop_back();     //for backtracking
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