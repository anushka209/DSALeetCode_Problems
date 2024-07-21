class Solution {
public:
      bool doesAliceWin(string s) 
      {
         int n=s.size();
         int vcount=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                vcount++;
        }
        if(vcount==0)      //Bob wins
            return false;
        return true;       //Alice wins in all other cases
      }
};