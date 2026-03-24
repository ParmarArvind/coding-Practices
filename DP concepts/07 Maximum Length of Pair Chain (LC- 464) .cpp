//method -1 recursion and memoizzation
class Solution {
public:
    int n;
    int t[1001][1001];
    int solve(vector<vector<int>>& pairs, int curr, int prev)
    {
        if(curr==n) return 0;
        
        if(prev != -1 && t[curr][prev] != -1) return t[curr][prev]; 
        int take =0;
        if(prev==-1){
            
            take = 1+solve(pairs, curr+1 ,curr);
        }
        else if(pairs[prev][1]<pairs[curr][0] )
        {
            take=1+solve(pairs,curr+1,curr);
        }
        int skip=solve(pairs,curr+1,prev);
        if(prev==-1) return  max(take,skip);
        return t[curr][prev]= max(take,skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        n=pairs.size();
        memset(t,-1,sizeof(t));
        sort(pairs.begin(), pairs.end());
        int length=solve(pairs ,0,-1);
        return length;

    }
};

//method -2 greddy
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        auto lambda =[](auto & a,auto & b)
        {
            return a[1]<b[1];
        };
        sort(pairs.begin(), pairs.end(),lambda);
        int prev=pairs[0][1];
        int length=1;
        for(int i=1;i<pairs.size();i++)
        {
            if(prev<pairs[i][0]) {
                length++;
                prev=pairs[i][1];
            }
        }

        return length;

    }
};
