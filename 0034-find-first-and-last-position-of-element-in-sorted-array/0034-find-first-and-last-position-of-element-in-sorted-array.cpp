class Solution {
public:
    int first_occ(vector<int>& nums, int target)
    {
        int s=0,e=nums.size()-1;
        int ans=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                e=mid-1;
            }
            else if(nums[mid]<target)
                s=mid+1;
            else
                e=mid-1;
        }
        return ans;
    }

    int last_occ(vector<int>& nums, int target)
    {
        int s=0,e=nums.size()-1;
        int ans=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                s=mid+1;
            }
            else if(nums[mid]<target)
                s=mid+1;
            else
                e=mid-1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
      vector<int>ans;
      ans.push_back(first_occ(nums,target));
      ans.push_back(last_occ(nums,target));
      return ans;
    }
};