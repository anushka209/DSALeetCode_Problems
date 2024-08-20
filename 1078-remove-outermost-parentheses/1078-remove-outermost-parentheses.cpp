class Solution {
public:
    string removeOuterParentheses(string s) {
      int count=0;
      string ans="";
      bool flag=true;
      for(int i=0;i<s.size();i++)
      {
        if(s[i]=='(')
            count++;
        else if(s[i]==')')
            count--;
        if(count==1 && flag==true)    // first open bracket
        {
            flag=false;
            continue;
        }
        if(count==0 && flag==false)     //last closing bracket
        {
            flag=true;
            continue;
        } 
        ans+=s[i];
      }
      return ans;
    }
};