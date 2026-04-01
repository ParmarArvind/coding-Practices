class Solution {
public:
    int n,m;
    bool check(string& sequence, string& word,int i)
    {
        if(i+m >n) return false;
        int j=0;
        while(j<m)
        {
            if(sequence[i]==word[j])
            {
                i++;
                j++;
            }
            else return false;
        }
        return true;
    }

    int dp[101];
    int solve(string& sequence, string& word,int i)
    {
        if(i>n-m) return 0;
        if(dp[i] != -1) return dp[i];
        if(check(sequence,word,i)) return dp[i]=1+solve(sequence,word,i+m);
        return dp[i]=0;
    }
    int maxRepeating(string sequence, string word) {
        n=sequence.size();
        m=word.size();
        if(n<m) return 0;
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(sequence, word, i));
        }
        return ans;
    }
};
