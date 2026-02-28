class Solution {
public:
    double myPow(double x, int n) {
        long long power = n;

        if(power < 0) {
            x = 1/x;
            power = -power;
        }

        double result = 1.0;

        while(power > 0) {
            if(power % 2 == 1) {
                result *= x;
            }

            x *= x;
            power /= 2;
        }

        return result;
    }
};


// recursive version
class Solution {
public:
    
    double solve(double x, long long power) {
        if(power == 0) 
            return 1.0;

        // Recursive call for half part 
        double half = solve(x, power / 2);


        if(power % 2 == 0)
            return half * half;
        else
            return half * half * x;
    }

    double myPow(double x, int n) {
        long long power = n;  // handles INT overflow

        if(power < 0) {
            x = 1 / x;
            power = -power;
        }

        return solve(x, power);
    }
};
