class Solution {
public:
    int binaryGap(int n) {
        string s;
        while(n!=0)
        {
            if(n%2 == 1) s.push_back('1');
            else s.push_back('0');
            n/=2;
        }

        int prev=-1;
        int result=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                if(prev==-1) prev=i;
                else 
                {
                    result=max(result,i-prev);
                    prev=i;
                }
            }
        }
        return result;
    }
};
