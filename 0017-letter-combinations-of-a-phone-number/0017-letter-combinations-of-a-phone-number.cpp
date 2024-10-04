class Solution {
    private:
    void find(int idx,string digits,string output,vector<string>& ans,string mapping[])
    {
       if(idx==digits.size())         //base case
       {
         ans.push_back(output);
         return;
       }
       int num=digits[idx]-'0';       //for get the integer value not ascii value of 2 or etc.
       string val=mapping[num];
       for(int i=0;i<val.size();i++)
       {
          output.push_back(val[i]);
          find(idx+1,digits,output,ans,mapping);
          output.pop_back();             //for empty output array ie.does backtracking
       }
    }

public:
    vector<string> letterCombinations(string digits) {
      vector<string>ans;
      if(digits.size()==0)   return ans;
      string output="";
      string mapping[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
      find(0,digits,output,ans,mapping);
      return ans;
    }
};