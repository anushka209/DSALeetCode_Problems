class Solution {
public:
    string fractionAddition(string expr) {
        int num=0,den=1;
        int i=0;
        int n=expr.size();

        while(i<n)
        {
            int curNum=0,curDem=0;
            bool sign=(expr[i]=='-');
            if(expr[i]=='+' || expr[i]=='-')
                i++;

            //build the curNum
            while(i<n && isdigit(expr[i]))
            {
                int val=expr[i]-'0';
                curNum=(curNum*10)+val;
                i++;
            }
             i++; //numerator / denominator  //skipping the division character '/'

            if(sign==true)
                curNum*=-1; 

            // Build the curDem
            while(i<n && isdigit(expr[i]))
            {
                int val=expr[i]-'0';
                curDem=(curDem*10)+val;
                i++;
            }
            num=num * curDem + curNum * den;
            den=den*curDem;
        }
        //num=-3 den=6 GCD=3
        int GCD=abs(__gcd(num,den)); //3
        num/=GCD; //-1
        den/=GCD; //2

        return to_string(num)+ "/" +to_string(den);
    }
};