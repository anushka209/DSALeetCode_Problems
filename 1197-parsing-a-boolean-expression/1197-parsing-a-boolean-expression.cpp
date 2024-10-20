class Solution {
public:
    char solve(vector<char>& vec,char op)
    {
        if(op=='!')
            return vec[0]=='t' ? 'f' : 't';
        else if(op=='&')
        {
            for(int i=0;i<vec.size();i++)
            {
                if(vec[i]=='f')
                    return 'f';
            }
        return 't';
        }
        else if(op=='|')
        {
            for(int i=0;i<vec.size();i++)
            {
                if(vec[i]=='t')
                    return 't';
            }
        return 'f';
        }
        return 't';  // never reach here return anything
    }

    bool parseBoolExpr(string expr) {
        int n=expr.size();
        stack<char>st;
        for(int i=0;i<n;i++)
        {
            if(expr[i]==',')
                continue;
            if(expr[i]==')')
            {
                vector<char>vec;
                while(st.top()!='(')
                {
                    vec.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op=st.top();  // &,|,!
                st.pop();
                st.push(solve(vec,op));
            }
            else
                st.push(expr[i]);
        }
        return st.top()=='t' ? true : false;
    }
};