class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen=0,l=0,r=0;
        int n=s.size();
        int maxf=0;
        map<char,int>mpp;
        while(r<n)
        {
            mpp[s[r]]++;
            maxf=max(maxf,mpp[s[r]]);
            int len=r-l+1;
            int conv=len-maxf;      //conversions needed
            if(conv>k)
            {
                mpp[s[l]]--;
                // maxf=0;
                // for(int i=0;i<mpp.size();i++)
                //     maxf=max(maxf,mpp[i].second);
                l++;
            }
            if(conv<=k)
                maxlen=max(maxlen,len);
            r++;
        }
        return maxlen;
    }
};