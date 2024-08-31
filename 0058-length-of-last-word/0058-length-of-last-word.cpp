class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int len=0;
        bool count=false;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]!=' ')
            {
                len++;
                count=true;
            }
            else if(count)
                break;
        }
        return len;
    }
};