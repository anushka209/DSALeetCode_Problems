class Solution {
private:
bool valid(char ch)
{
    if((ch>='A'&&ch<='Z')||(ch>='a'&& ch<='z')||(ch>='0'&&ch<='9'))
    {
        return 1;
    }
    return 0;
}

char tolower(char ch)
{
 if((ch>='a'&& ch<='z')||(ch>='0'&&ch<='9'))
    return ch;
    else{
        char temp = ch-'A'+'a';
        return temp;
    }
}

bool checkPalin(string a)
{
   int b=0,e=a.length()-1;
        while(b<=e)
        {
            if(a[b]!=a[e])
            {
            return 0;
            }  
            else{
                b++;
                e--;
            }
        }
        return 1;
}
public:
    bool isPalindrome(string s) {
       string temp="";
       for(int i=0;i<s.length();i++)
       {
           if(valid(s[i]))
           {
              temp.push_back(s[i]);
           }
       }
       for(int i=0;i<temp.length();i++)
       {
           temp[i]=tolower(temp[i]);
       }
    return checkPalin(temp);
    }
};