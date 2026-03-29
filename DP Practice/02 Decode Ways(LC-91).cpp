// method -1
class Solution {
public:
    int n;
    int dp[101];
    int solve(string& s, int i, string num) {
        if (num.size() > 0) {
            if (num.size() == 1 && num[0] == '0')
                return 0;
            if (num.size() == 2) {
                int number = (num[0] - '0') * 10 + num[1] - '0';
                if (number < 10 || number > 26)
                    return 0;
            }
        }

        if (i >= n)
            return 1;

        if (dp[i] != -1)
            return dp[i];

        string t;
        t.push_back(s[i]);
        int first = solve(s, i + 1, t);
        int second = 0;
        string t2 = "";

        if (i + 1 < n) {
            t2.push_back(s[i]);
            t2.push_back(s[i + 1]);
            second = solve(s, i + 2, t2);
        }

        return dp[i] = first + second;
    }
    int numDecodings(string s) {
        n = s.size();
        memset(dp, -1, sizeof(dp));

        return solve(s, 0, "");
    }
};

// method -2 better approach
class Solution {
public:
    int n;
    int dp[101];
    int solve(string &s,int i)
    {
        if(s[i]=='0') return 0;

        if(i>=n) return 1;

        if(dp[i]!=-1) return dp[i]; 
        
        int first=solve(s,i+1) ;
        int second=0;
        
        if(i+1<n)
        {
            int number=(s[i]-'0')*10+s[i+1]-'0';
            if(number>= 10 && number<=26)  second=solve(s,i+2);
        }

        return dp[i]=first+second;
    }
    int numDecodings(string s) {
        n=s.size();
        memset(dp,-1,sizeof(dp));
        return solve(s,0);
        
    }
};
};
