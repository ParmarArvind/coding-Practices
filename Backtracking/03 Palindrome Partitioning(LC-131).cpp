// methhod -1 backtracking
class Solution {
public:
    
    int n;
    bool check(string &s ,int start,int end)
    {
        while(start<end)
        {
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void solve(string &s,int idx,vector<string> &curr , vector<vector<string>> &result)
    {
        if(idx==n)
        {
            result.push_back(curr);
            return;
        }

        for(int i=idx;i<n;i++)
        {
            if(check(s,idx,i)) 
            {
                curr.push_back(s.substr(idx,i-idx+1));
                solve(s,i+1,curr,result);
                curr.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        n=s.size();
        vector<vector<string>>result;
        vector<string>curr;
        solve(s,0,curr,result);
      
        return result;
    }
};

// see dp concept for more methods

