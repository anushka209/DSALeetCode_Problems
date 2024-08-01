class Solution {
public:
int binary_search(vector<int> &nums,int s,int e,int target)
  {
    if(s>e) return -1;
    int mid=s+(e-s)/2;
    if(nums[mid]==target)
        return mid;
    else if(nums[mid]<target)
        return binary_search(nums,mid+1,e,target);
    else
        return binary_search(nums,s,mid-1,target);
  }

int search(vector<int> &nums, int target)
  {
    // Write your code here.
    return binary_search(nums,0,nums.size()-1,target);
  }
};