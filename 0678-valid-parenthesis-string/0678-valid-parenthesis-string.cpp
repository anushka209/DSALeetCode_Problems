class Solution {
public:
//     bool check(string s,int idx,int count)
//     {
//         if(count<0) return false;         // gives TLE so solve using dp
//         if(idx==s.size())
//             return (count==0);
//         if(s[idx]=='(')
//             return check(s,idx+1,count+1);
//         if(s[idx]==')')
//             return check(s,idx+1,count-1);
//  // in case of *---if replace with (   or   )    or   empty
//         return check(s,idx+1,count+1) || check(s,idx+1,count-1) || check(s,idx+1,count);
//     }

    bool checkValidString(string s) {
       // return check(s,0,0);
       int min=0,max=0;
       for(int i=0;i<s.size();i++)
       {
        if(s[i]=='(')
        {
            min++;
            max++;
        }
        else if(s[i]==')')
        {
            min--;
            max--;
        }
        else                 // in case of *
        {
            min--;
            max++;
        }
        if(min<0) min=0;
        if(max < 0)  return false;
       }
       return (min==0);
    }
};