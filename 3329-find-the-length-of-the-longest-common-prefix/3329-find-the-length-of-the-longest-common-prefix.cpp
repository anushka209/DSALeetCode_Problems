class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
       int maxlen=0;
       unordered_map<string,int>PrefixMap;

       // build prefix map for arr1
       for(int num:arr1)
       {
         string str=to_string(num);
         string prefix="";
         for(char ch:str)
         {
            prefix+=ch;
            PrefixMap[prefix]++;
         }
       }

       // check common prefix in arr2
       for(int num:arr2)
       {
         string str=to_string(num);
         string prefix="";
         for(char ch:str)
         {
            prefix+=ch;
            if(PrefixMap.find(prefix)!=PrefixMap.end())
            {
                maxlen=max(maxlen,static_cast<int>(prefix.length()));
            }
         }
       }
       return maxlen;
    }
};