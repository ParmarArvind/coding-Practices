//method -1 recursion and memoization
class Solution {
public:
    int t[38];
    int solve(int n)
    {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        if(t[n]!=-1) return t[n];
        return t[n]=solve(n-1)+solve(n-2)+solve(n-3);
    }
    int tribonacci(int n) {
        memset(t,-1,sizeof(t));
        return solve(n);
    }
};

// method -2 bottom up
class Solution {
public:
    
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        vector<int>t(n+1);
        t[0]=0;
        t[1]=1;
        t[2]=1;

        for(int i=3;i<=n;i++)
        {
            t[i]=t[i-1]+t[i-2]+t[i-3];
        }

        return t[n];
    }
};

// method -3 O(1) extra space
class Solution {
public:
    
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        int a=0;
        int b=1;
        int c=1;
        int d;
        for(int i=3;i<=n;i++)
        {
            d=c+b+a;
            a=b;
            b=c;
            c=d;
        }
        return d;
    }
};
