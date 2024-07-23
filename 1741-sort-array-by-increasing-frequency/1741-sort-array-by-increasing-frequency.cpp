class Solution {
public:
    bool comp(int a, int b, unordered_map<int, int>& mpp) {
    if (mpp.at(a) != mpp.at(b)) {
        return mpp.at(a) < mpp.at(b);    //increasing order based on frequency
    } 
    else 
        return a > b;       // decreasing order by the number
}

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mpp;      //store number & count
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        // sort(nums.begin(), nums.end(), [&](int a, int b) {
        //     if (mpp[a] != mpp[b]) {
        //         // if freq of numbers are not equal then return in increasing order based on freq.
        //         return mpp[a] < mpp[b];
        //     } else {
        //         // otherwise sort them in decreasing order based on number in nums.
        //         return a > b;
        //     }
        // });
        sort(nums.begin(), nums.end(), [&](int a, int b) {
        return comp(a,b,mpp);
        });
        return nums;
    }
};