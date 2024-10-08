class Solution {
public:
    int minSwaps(string s) {
       // stack<char>st;

       int size=0;
       for(int i=0;i<s.size();i++)
       {
         if(s[i]=='[')
            // st.push(s[i]);
            size++;

         //else if(s[i]==']' && !st.empty())
           // st.pop();
        else if(size>0)
            size--;
       }
       // return (st.size()+1)/2;
       return (size+1)/2;
    }
};