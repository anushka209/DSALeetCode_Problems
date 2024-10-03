class Solution {
public:
//    int myAtoi(string s,int last)
//    {
//     if(last==0)
//         return s[last]-'0';
//     long ans=myAtoi(s,last-1);
//     long res=s[last]-'0';
//     long p=ans*10+res;
//     if(p>INT_MAX)  return INT_MAX;
//     else if(p<INT_MIN)  return INT_MIN;
//     else return (int)(p);
//    }

    int myAtoi(string s) {
        if(s.size()==0)
            return 0;
        int i=0;
        while(i<s.size() && s[i]==' ')
            i++;
        s=s.substr(i);  // i to last of string.
        int sign=+1;
        long ans=0;
        if(s[0]=='-')
            sign=-1;
        int max=INT_MAX,min=INT_MIN;
        i = (s[0]=='+' || s[0]=='-') ? 1 : 0;
        while(i<s.size())
        {
            if(s[0]==' ' || !isdigit(s[i]))
                break;
            ans=ans*10+s[i]-'0';
            if(sign==-1 && sign*ans<min) return min;
            if(sign==+1 && sign*ans>max) return max;
            i++;
        }
        return (int)sign*ans;

        //------------recursive approach
        // int len=s.size();
        // return myAtoi(s,len-1);
    }
}; 