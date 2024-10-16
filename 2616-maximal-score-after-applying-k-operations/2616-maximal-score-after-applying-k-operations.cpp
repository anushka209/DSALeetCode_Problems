class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++)
            pq.push(nums[i]);
        long long ans=0;
        while(k>0)
        {
            int res=pq.top();
            pq.pop();
            ans+=res;
            int val=ceil(res/3.0);
            pq.push(val);
            k--;
        }
        return ans;
    }
};