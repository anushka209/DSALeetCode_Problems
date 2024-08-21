class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<=1) return s;
        int n=s.size();
        int st=0,e=0;
        int max_len=1;

        // for odd
        for(int i=0;i<n;i++)
        {
            int l=i,r=i;
            while(l>=0 && r<n)
            {
                if(s[l]==s[r])
                {
                    l--; r++;
                }
                else
                    break;
            }
            int len=r-l-1;
            if(len>max_len)
            {
                max_len=len;
                st=l+1;
                e=r-1;
            }
        }

        // for even
        for(int i=0;i<n;i++)
        {
            int l=i,r=i+1;
            while(l>=0 && r<n)
            {
                if(s[l]==s[r])
                {
                    l--; r++;
                }
                else
                    break;
            }
            int len=r-l-1;
            if(len>max_len)
            {
                max_len=len;
                st=l+1;
                e=r-1;
            }
        }
        return s.substr(st,max_len);
    }
};