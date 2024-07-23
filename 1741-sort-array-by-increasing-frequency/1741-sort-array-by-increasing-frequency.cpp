class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mpp;      //store number & count
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (mpp[a] != mpp[b]) {
                // if freq of numbers are not equal then return in increasing
                // order based on freq.
                return mpp[a] < mpp[b];
            } else {
                // otherwise sort them in decreasing order based on number in nums.
                return a > b;
            }
        });
        return nums;
    }
};