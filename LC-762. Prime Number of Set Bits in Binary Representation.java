class Solution {
    public boolean isPrime(int num)
    {
        int count=0;
        while(num!=0)
        {
            if(num%2==1) count++;
            num=num/2;
        }
        if(count<2) return false;
        int i=2;
        while(i*i<=count)
        {
            if(count%i==0) return false;
            i++;
        }
        return true;
    }
    public int countPrimeSetBits(int left, int right) {
        int count=0;
        for(int i=left;i<=right;i++)
        {
            if(isPrime(i)==true) count=count+1;
        }
        return count;
    }
}

// second method using set

class Solution {
    public int countPrimeSetBits(int left, int right) {
        int result = 0;

        HashSet<Integer> primes = new HashSet<Integer>(Arrays.asList(2, 3, 5, 7, 11, 13, 17, 19));

        for(int num = left; num <= right; num++) {
            int setBits = Integer.bitCount(num); // count set bits

            if(primes.contains(setBits)) {
                result++;
            }
        }

        return result;
    }
}
