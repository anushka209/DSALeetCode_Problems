class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0,r=0,maxlen=0,maxf=0;
        map<char,int>mpp;
        while(r<n)
        {
            mpp[s[r]]++;
            maxf=max(maxf,mpp[s[r]]);   // find maximum frequency
            int len=r-l+1;
            int conv=len-maxf;  // conversion needed
            if(conv>k)
            {
                mpp[s[l]]--;
                // maxf=0;                          //not needed to do becoz if maxF was decreased then maxlen cannot be increased..to get maxlen as more
                // for(int i=0;i<mpp.size();i++)        // than previous we have to increase the maxF so not required to decrease or update maxF.
                //     maxf=max(maxf,mpp[i].second);
                l++;
            }
            if(conv<=k)
            {
                maxlen=max(maxlen,len);
            }
            r++;
        }
        return maxlen;
    }
};