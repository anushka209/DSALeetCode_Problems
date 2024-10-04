class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        sort(skill.begin(),skill.end());
        int sum=skill[0]+skill[n-1];
        long long chemSum=0;

        for(int i=0;i<n/2;i++)
        {
            if(skill[i]+skill[n-i-1]!=sum)
                return -1;
            chemSum+=(long long)skill[i]*skill[n-i-1];
        }
        return chemSum;
    }
};