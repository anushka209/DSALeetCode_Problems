class Solution {
public:
    string solve(int n)
    {
        if(n==1)
           return "0";
        string first=solve(n-1)+'1';
        for(int i=first.size()-2;i>=0;i--)
        {
            first+=(first[i]=='1')?'0':'1';
        }
        return first;
    }
    
    char findKthBit(int n, int k) {
        string final=solve(n);
        return final[k-1];
    }
};