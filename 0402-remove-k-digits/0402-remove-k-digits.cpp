class Solution {
public:
    string removeKdigits(string num, int k) {
    stack<int>s;
    if(num.size()==k)
       return "0";
    for(int i=0;i<num.size();i++)
    {
      while (!s.empty() && s.top() > num[i] && k>0) 
      {
       s.pop();
       k--;
      }
      if(!s.empty() || num[i]!='0')      // to avoid when we have 0 in starting
        s.push(num[i]);
    }

    while (!s.empty() && k > 0) {     //when string is in increasing order
      s.pop();
      k--;
    }

    if(s.empty() && k>=0)
      return "0";

    string ans="";
    while(!s.empty())
    {
      ans+=s.top();
      s.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};