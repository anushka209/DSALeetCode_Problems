class Solution {
public:
    int countPrimes(int n) {
       int count=0;
    //    vector<bool>prime(n+1,true);
    //    prime[0]=prime[1]=false;
    //     for(int i=2;i<n;i++)
    //     {
    //         if(prime[i])
    //         {
    //         count++;

    //         for(int j=2*i;j<n;j=j+i)
    //         {
    //             prime[j]=0;
    //         }
    //     }
    //     }
    //     return count;

        int arr[n+1];          // by sieve of eratosthenes
        for(int i=2;i<=n;i++)
        {
            arr[i]=1;
        }
        for(int i=2;i*i<=n;i++)
        {
            if(arr[i]==1)
            {
                for(int j=i*i;j<=n;j+=i)
                {
                    arr[j]=0;
                }
            }
        }
        for(int i=2;i<n;i++)
        {
            if(arr[i]==1)
                count++;
        }
        return count;
    }
};