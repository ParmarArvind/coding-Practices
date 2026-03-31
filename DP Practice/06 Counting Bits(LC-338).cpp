//method -1 recursion and memoization  O(n)
class Solution {
public:
    int t[100001];
    int solve(int num)
    {
        if(num==0) return t[num]= 0;
        if(t[num]!=-1) return t[num];
        if(num%2==1) return t[num]=1+solve(num/2);
        return  t[num]=solve(num/2);
    }
    vector<int> countBits(int n) {
        vector<int> result(n+1);
        memset(t,-1,sizeof(t));
        for(int i=0;i<=n;i++)
        {
            result[i]=solve(i);
        }
        return result;
    }
};


//method -2 bottom up
class Solution {
public:
    
    vector<int> countBits(int n) {
        if(n==0) return {0};
        if(n==1) return {0,1};
        vector<int> result(n+1);
        result[0]=0;
        result[1]=1;
        
        for(int i=2;i<=n;i++)
        {
            if(i%2==1) result[i]= 1+result[i/2];
            else result[i]= result[i/2];
        }
        return result;
    }
};
