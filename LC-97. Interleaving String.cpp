//method -1 using 3D dp
class Solution {
public:
    int n,m,N;
    int dp[101][101][201];
    bool solve(int i,int j,int k,string& s1, string& s2, string& s3)
    {
        if(i==n && j==m && k==N) return true;
        if(k==N) return false;

        if(dp[i][j][k] !=-1 ) return dp[i][j][k];
        bool result=false;
        if(s1[i]==s3[k])
        result= solve(i+1,j,k+1,s1,s2,s3);

        if(result) return dp[i][j][k]= true;

        if(s2[j]==s3[k])
        result= solve(i,j+1,k+1,s1,s2,s3);

        return dp[i][j][k]=result;
    }
    bool isInterleave(string s1, string s2, string s3) {

        n=s1.size();
        m=s2.size();
        N=s3.size();

        memset(dp,-1,sizeof(dp));

        return solve(0,0,0,s1,s2,s3);
    }
};


// method 2 using D dp
class Solution {
public:
    int n,m,N;
    int dp[101][101];
    bool solve(int i,int j,string& s1, string& s2, string& s3)
    {
        if(i==n && j==m && i+j==N) return true;
        if(i+j==N) return false;

        if(dp[i][j] !=-1 ) return dp[i][j];
        bool result=false;
        if(s1[i]==s3[i+j])
        result= solve(i+1,j,s1,s2,s3);

        if(result) return dp[i][j]= true;

        if(s2[j]==s3[i+j])
        result= solve(i,j+1,s1,s2,s3);

        return dp[i][j]=result;
    }
    bool isInterleave(string s1, string s2, string s3) {

        n=s1.size();
        m=s2.size();
        N=s3.size();

        memset(dp,-1,sizeof(dp));

        return solve(0,0,s1,s2,s3);
    }
};
