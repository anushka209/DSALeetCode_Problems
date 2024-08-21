class Solution {
public:
    int beauty(vector<int> &h)
    {
       int mf=-1,lf=1e9;
       for(int i=0;i<26;i++)
       {
          mf=max(mf,h[i]);
          if(h[i]>=1)        //condition apply here becoz some ele have frequency 0 so we have to take only which have least ie.1 or more.
            lf=min(lf,h[i]);
       }
       return mf-lf;
    }         

    int beautySum(string s)
    {
       int ans=0;
       int n=s.size();
       for(int i=0;i<n;i++)
       {
        vector<int>h(26,0);
        for(int j=i;j<n;j++)
        {
            h[s[j]-'a']++;
            ans+=beauty(h);
        }
       }
       return ans;
    }
};