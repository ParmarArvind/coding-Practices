class Solution {
public:

    bool isPrime(int num)
    {
        int count=0;
        while(num != 0)
        {
            if(num % 2 == 1) count++;
            num=num/2;
        }
        if(count==1) return false;
        for(int i=2;i*i <= count;i++)
        {
            if(count%i==0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int count=0;
        for(int i=left;i<=right;i++)
        {
            if(isPrime(i)) count++;
        }
        return count;
    }
};

// method 2 use set
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
         unordered_set<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19 };
        
        int result = 0;

        for (int num = left; num <= right; num++) {
            int setBits = __builtin_popcount(num); // count set bits
            
            if(primes.count(setBits))
                result += 1;
        }
        return result;
    }
};
