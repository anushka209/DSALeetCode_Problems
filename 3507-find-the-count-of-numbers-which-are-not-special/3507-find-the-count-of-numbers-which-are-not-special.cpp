class Solution {
public:
    int nonSpecialCount(int l, int r) {     //using sieve of eratosthenes
        // int count=0;
        // for(int i=l;i<=r;i++)
        // {
        //     int div=0;
        //     for(int j=1;j<i;j++)
        //     {
        //         if(i%j==0)
        //             div++;
        //     }
        //     if(div!=2)
        //         count++;
        // }
        // return count;

        int maxi=sqrt(r);
        vector<int>v(maxi+1,1);
        v[1]=0;

        for(int i=2;i<=maxi;i++)
        {
            if(v[i]==1)
            {
                for(int j=i*i;j<=maxi;j+=i)
                {
                    v[j]=0;
                }
            }
        }
        int count=0;
        for(int i=2;i<=maxi;i++)
        {
            if(v[i]==1)
            {
                int val=i*i;
                if(val>=l && val<=r)
                    count++;
            }
        }
        return (r-l+1)-count;
    }
};