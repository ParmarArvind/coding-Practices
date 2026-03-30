//method -1 recursion and memoization 
class Solution {
public:
    bool check(vector<string>& words ,int prev,int curr,int i,int j,int flag)
    {
        if(words[prev].size() + 1 != words[curr].size()) 
            return false;

        if(i == words[prev].size()) 
            return true;

        if(j == words[curr].size()) 
            return false;

        if(words[prev][i] == words[curr][j]) 
            return check(words, prev, curr, i+1, j+1, flag);

        if(flag) 
            return false;

        return check(words, prev, curr, i, j+1, 1);
    }
    int dp[1001][1001];
    int n;
    int solve(vector<string>& words ,int prev,int curr)
    {
        if(curr>=n) return 0;

        if(prev != -1 && dp[prev][curr] != -1) return dp[prev][curr];
        int take=0;
        if(prev != -1 )
        {
            if(check(words,prev,curr,0,0,0) ) take=1+solve(words,curr,curr+1);
        }
        else take=1+solve(words,curr,curr+1);
        
        int skip=solve(words,prev,curr+1);
        if(prev !=-1 ) return dp[prev][curr]= max(take,skip);
        return max(take,skip);
    }

    int longestStrChain(vector<string>& words) {
        n=words.size();
        auto lambda=[](auto &a,auto &b)
        {
            return a.size()<b.size();
        };
        
        memset(dp,-1,sizeof(dp));
        sort(words.begin(),words.end(),lambda);
        return solve(words,-1,0);

    }
};

// method -2 recursion and memoization  bubt better check function 
class Solution {
public:
    bool check(string &a, string &b) {
        if (a.size() + 1 != b.size()) return false;

        int i = 0, j = 0;
        bool skipped = false;

        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++; j++;
            } else {
                if (skipped) return false;
                skipped = true;
                j++;
            }
        }
        return true;
    }
    int dp[1001][1001];
    int n;
    int solve(vector<string>& words ,int prev,int curr)
    {
        if(curr>=n) return 0;

        if(prev != -1 && dp[prev][curr] != -1) return dp[prev][curr];
        int take=0;
        if(prev != -1 )
        {
            if(check(words[prev],words[curr]) ) take=1+solve(words,curr,curr+1);
        }
        else take=1+solve(words,curr,curr+1);
        
        int skip=solve(words,prev,curr+1);
        if(prev !=-1 ) return dp[prev][curr]= max(take,skip);
        return max(take,skip);
    }

    int longestStrChain(vector<string>& words) {
        n=words.size();
        auto lambda=[](auto &a,auto &b)
        {
            return a.size()<b.size();
        };
        
        memset(dp,-1,sizeof(dp));
        sort(words.begin(),words.end(),lambda);
        return solve(words,-1,0);

    }
};

// method -3 bottom up
class Solution {
public:
    bool check(string &a, string &b) {
        if (a.size() + 1 != b.size()) return false;

        int i = 0, j = 0;

        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) i++;

            j++;
        }
        return i==a.size();
    }

    int longestStrChain(vector<string>& words) {
        int n=words.size();
        auto lambda=[](auto &a,auto &b)
        {
            return a.size()<b.size();
        };
        
        vector<int>t(n+1,1);
        sort(words.begin(),words.end(),lambda);
        int maxLIS=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(check(words[j],words[i]))
                {
                    t[i]=max(t[i],t[j]+1);
                    maxLIS=max(maxLIS,t[i]);
                }

            }
        }
        return maxLIS;

    }
};

