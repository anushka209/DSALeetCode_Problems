class Solution {
public:
    int minAddToMakeValid(string s) {
        int close=0;
        stack<int>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                st.push(s[i]);
            else if(s[i]==')' && !st.empty())
                st.pop();
            else
                close++;
        }
        return st.size()+close;
    }
};