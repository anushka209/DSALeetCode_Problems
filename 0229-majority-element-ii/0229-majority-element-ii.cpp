class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        // map<int,int>mpp;          // by hashing
        // int mini=(int)(n/3)+ 1;
        // vector<int>ans;
        // for(int i=0;i<n;i++)
        // {
        //     mpp[nums[i]]++;
        //     if(mpp[nums[i]]==mini)
        //     {
        //         ans.push_back(nums[i]);
        //     }
        //     if(ans.size()==2) break;
        // }
        // return ans;
        int cnt1=0,cnt2=0;
        int ele1=INT_MIN,ele2=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(cnt1==0 && nums[i]!=ele2)
            {
                cnt1=1;
                ele1=nums[i];
            }
            else if(cnt2==0 && nums[i]!=ele1)
            {
                cnt2=1;
                ele2=nums[i];
            }
            else if(ele1==nums[i]) cnt1++;
            else if(ele2==nums[i]) cnt2++;
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        vector<int>ans;
        cnt1=0,cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(ele1==nums[i]) cnt1++;
            if(ele2==nums[i]) cnt2++;
        }
        int mini=(int)(n/3)+1;
        if(cnt1>=mini)
            ans.push_back(ele1);
        if(cnt2>=mini)
            ans.push_back(ele2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};