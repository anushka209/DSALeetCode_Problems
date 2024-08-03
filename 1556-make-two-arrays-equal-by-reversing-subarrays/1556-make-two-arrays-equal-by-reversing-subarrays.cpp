class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // sort(target.begin(),target.end());        //by sorting
        // sort(arr.begin(),arr.end());
        // for(int i=0;i<arr.size();i++)
        // {
        //     if(arr[i]!=target[i])
        //         return false;
        // }
        // return true;

        vector<int>v1(1001);
        vector<int>v2(1001);
        for(int& i:target)
        {
            v1[i]++;
        }
        for(int& i:arr)
        {
            v2[i]++;
        }
        return v1==v2;
    }
};