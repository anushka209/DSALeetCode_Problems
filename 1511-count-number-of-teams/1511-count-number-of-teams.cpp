class Solution {
public:
    int numTeams(vector<int>& r) {
        int n=r.size();
        int teams=0;
        for(int j=1;j<n-1;j++)
        {
        int ls=0,rs=0,ll=0,rl=0;
            //find left smaller & greater
            for(int i=0;i<j;i++)
            {
                if(r[i]<r[j]) ls++;
                else if(r[i]>r[j]) ll++;
            }
            //find right smaller & greater
            for(int i=j+1;i<n;i++)
            {
                if(r[i]<r[j]) rs++;
                else if(r[i]>r[j]) rl++;
            }
        teams+=(ls*rl)+(ll*rs);
        }
        return teams;
    }
};