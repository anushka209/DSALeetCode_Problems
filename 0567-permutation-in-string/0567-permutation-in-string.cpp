class Solution {
    private:
    // bool checkEqual(int a[26],int b[26])
    // {
    //     for(int i=0;i<26;i++)
    //     {
    //         if(a[i]!=b[i])
    //         return 0;
    //     }
    //     return 1;
    // }
public:
    bool checkInclusion(string s1, string s2) {
    //  int count1[26]={0};
    //  for(int i=0;i<s1.length();i++)
    //  {
    //      int index = s1[i]-'a';
    //      count1[index]++;
    //  }   

    //  int i=0;
    //  int windowSize=s1.length();
    //  int count2[26]={0};

    //  while(i<windowSize && i<s2.length())
    //  {
    //      int index = s2[i]-'a';
    //      count2[index]++;
    //      i++;
    //  }
    //  if(checkEqual(count1,count2))
    //     return 1;

    //  while(i<s2.length())
    //  {
    //      char newChar=s2[i];
    //      int index = newChar -'a';
    //      count2[index]++;
     
    //  char oldChar = s2[i-windowSize];
    //    index = oldChar - 'a';
    //  count2[index]--;

    //  i++;
    //  if(checkEqual(count1,count2))
    //  return 1;
    // }
    // return 0;

      unordered_map<char,int>mpp;
      for(auto &x : s1)
          mpp[x]++;
        int l=0,r=0;
        int n=s2.size();
        int req=s1.size();
        while(r<n)
        {
            if(mpp[s2[r]]>0)         // Decrease frequency of current character
                req--;
            mpp[s2[r]]--;
            r++;

            if(req==0)        // When the window size equals the length of s1, check if all characters match
               return true;

            if(r-l == s1.length())       // If the window size exceeds the size of s1, shrink the window
            {
                if(mpp[s2[l]]>=0)
                    req++;
                mpp[s2[l]]++;
                l++;
            }
        }
     return false;
    }
};