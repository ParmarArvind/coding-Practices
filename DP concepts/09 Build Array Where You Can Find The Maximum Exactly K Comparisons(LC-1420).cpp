class Solution {
public:
    int N,M,K;
    int mod=1e9+7;
    int t[51][101][101];
    int solve(int count,int search_cost ,int maxVal)
    {
        if(search_cost>K) return 0;
        if(count==N )
        {
            if(search_cost==K) return 1;
            return 0;
        }

        if(t[count][search_cost][maxVal] != -1) return t[count][search_cost][maxVal];
        int result=0;
        for(int i=1;i<=M;i++)
        {
            if(i>maxVal) result =(result+solve(count+1,search_cost+1,i))%mod;
            else result =(result+ solve(count+1,search_cost,maxVal))%mod;
        }
        return t[count][search_cost][maxVal]=result;
    }
    int numOfArrays(int n, int m, int k) {
        N=n;
        M=m;
        K=k;
        memset(t,-1,sizeof(t));
        return solve(0,0,0);
        
    }
};
