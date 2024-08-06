class Solution {
public:
    int minimumPushes(string word) {
        int ans=0;
        unordered_map<int,int>mpp;

        int assign_key=2;
        for(char &ch : word)
        {
            if(assign_key>9)
                assign_key=2;

            mpp[assign_key]++;
            ans+=mpp[assign_key];
            assign_key++;
        }
        return ans;
    }
};