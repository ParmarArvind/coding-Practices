class Solution {
  // TC=log(n) +log(n) =2*log(n) =log(n) 
  // SC =log(n) 
    public int binaryGap(int n) {
        StringBuilder s=new StringBuilder();
        
        while(n!=0)
        {
            if(n%2 == 1) s.append('1');
            else s.append('0');
            n/=2;
        }

        int prev=-1;
        int result=0;
        for(int i=0;i<s.length();i++)
        {
            if(s.charAt(i)=='1')
            {
                if(prev==-1) prev=i;
                else 
                {
                    result=Math.max(result,i-prev);
                    prev=i;
                }
            }
        }
        return result;
    }
}
