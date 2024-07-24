class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++)
        {
           int ele=nums[i];
           string s="";
           if(ele==0)
                s=to_string(mapping[0]);
            else
            {
                while(ele>0)
                {
                    int digit=ele%10;
                    s=to_string(mapping[digit])+s;
                    ele=ele/10;
                }
            }
            int val=stoi(s);
            v[i]={val,i};
        }
        sort(v.begin(),v.end());
        vector<int>sortNum;
        for(auto & it:v)
        {
            sortNum.push_back(nums[it.second]);
        }
        return sortNum;
    }
};