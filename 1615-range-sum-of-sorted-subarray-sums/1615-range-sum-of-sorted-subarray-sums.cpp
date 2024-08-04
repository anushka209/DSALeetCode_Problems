const int MOD = 1000000007; 
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // int m=(n*(n+1))/2;
        vector<int>temp;
        for(int i=0;i<n;i++)
        {
            long long sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=nums[j];
                temp.push_back(sum);
            }
        }
        sort(temp.begin(),temp.end());
        long long ans=0;
        for(int i=left;i<=right;i++)
        {
            ans+=temp[i-1];
        }
        return ans%MOD;
    }
};