class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int n=expression.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            char op=expression[i];
            if(op=='+' || op=='-' || op=='*')
            {
                string left=expression.substr(0,i);
                string right=expression.substr(i+1);
                vector<int>leftAns=diffWaysToCompute(left);
                vector<int>rightAns=diffWaysToCompute(right);
                for(int x: leftAns)
                {
                    for(int y: rightAns)
                    {
                        if(op=='+')
                            ans.push_back(x+y);
                        else if(op=='-')
                            ans.push_back(x-y);
                        else if(op=='*')
                            ans.push_back(x*y);
                    }
                }
            }
        }
            if(ans.empty())
                ans.push_back(stoi(expression));
        return ans;
    }
};