class Solution {
public:
    int maximumSwap(int num) {
        string nums=to_string(num);
        int n=nums.size();
        int maxi=-1,swap1=-1,swap2=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(maxi==-1 || nums[i]>nums[maxi])
            {
                maxi=i;
            }
            else if(nums[i]<nums[maxi])
            {
                swap1=i;
                swap2=maxi;
            }
        }
        if(swap1!=-1 && swap2!=-1)
        {
            swap(nums[swap1],nums[swap2]);
        }
        return stoi(nums);
    }
};