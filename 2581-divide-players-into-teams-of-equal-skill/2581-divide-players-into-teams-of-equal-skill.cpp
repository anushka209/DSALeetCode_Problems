class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int l=0,r=skill.size()-1;
        long long sum=skill[l]+skill[r];
        l++;
        r--;
        while(l<=r)
        {
            long long res=skill[l]+skill[r];
            if(res!=sum)
                return -1;
            l++;
            r--;
        }
        long long ans=0;
        l=0,r=skill.size()-1;
        while(l<=r)
        {
            long long prod=skill[l]*skill[r];
            l++;
            r--;
            ans+=prod;
        }
        return ans;
    }
};