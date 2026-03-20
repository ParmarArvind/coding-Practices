class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int coin5=0;
        int coin10=0;

        for(int i=0;i<n;i++)
        {
            if(bills[i]==5) coin5++;
            else if(bills[i]==10) 
            {
                coin5--;
                coin10++;
            }
            else{
                coin5--;
                if(coin10 >0) coin10--;
                else coin5 -=2;
            }
            if(coin5<0 || coin10 <0 ) return false;
        }

        return true;
    }
};
