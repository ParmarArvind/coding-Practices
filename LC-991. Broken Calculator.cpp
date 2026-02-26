// wrong approach -  71 / 84 testcases passed
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int op=0;
        while(startValue!=target)
        {
            if(abs(startValue*2 -target) >abs((startValue-1)*2 -target))
            {
                startValue--;
            }
            else startValue *=2;
            op++;
        }
        return op;
    }
};

// method -1 
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int op=0;
        while(startValue!=target)
        {
            if(target<startValue) target++;
            else if(target%2==0) target /= 2;
            else target++;
            op++;
        }
        return op;
    }
};

// method 2 same but use of recursion 
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if(startValue>=target) return startValue-target;
        
        if(target%2 == 0 ) return 1+ brokenCalc(startValue,target/2);
        // else 
        return 1+brokenCalc(startValue,target+1);
    }
};
