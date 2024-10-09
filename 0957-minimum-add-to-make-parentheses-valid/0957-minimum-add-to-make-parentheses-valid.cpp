class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0,close=0;
        // stack<int>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
               // st.push(s[i]);
               open++;
           // else if(s[i]==')' && !st.empty())
               // st.pop();
            else if(s[i]==')' && open>0)
               open--;
            else
                close++;
        }
      //  return st.size()+close;
      return open+close;
    }
};