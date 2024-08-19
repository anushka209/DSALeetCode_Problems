class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n=energyDrinkA.size();
        long long ans=0;
        long long currA=0,currB=0;
        for(int i=0;i<n;i++)
        {                                   // Calculate the new boost values considering the switch
            long long newA=max(currA + energyDrinkA[i],currB);
            long long newB=max(currB + energyDrinkB[i],currA);

            currA=newA;     // Update the current boosts
            currB=newB;
        }
        ans=max(currA,currB);
        return ans;
    }
};