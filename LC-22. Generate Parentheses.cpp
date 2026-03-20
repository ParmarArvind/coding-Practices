//method -1 
class Solution {
public:
    vector<string> result;
    int N;

    bool isValid(string &curr)
    {
        stack<char>st;
        int left = 0;
        for(int i = 0; i < curr.size(); i++)
        {
            if(curr[i] == '(') st.push('(');
            else if(st.empty()) return false;
            else if(st.top() =='(') st.pop();
            else return false;// no matching 
        }
        return st.empty();
    }

    void solve(string& curr)
    {
        if(curr.size() == 2 * N)
        {
            if(isValid(curr))
            {
                result.push_back(curr);
            }
            return;
        }
        // DO 
        curr.push_back('(');
        solve(curr);
        // backtrack (undo)
        curr.pop_back();

        
        curr.push_back(')');
        solve(curr);
        curr.pop_back();
       
    }

    vector<string> generateParenthesis(int n) {
        N = n;
        string curr = "";
        solve(curr);
        return result;
    }
};

// method -2 . method-1's better version without stack use
class Solution {
public:
    vector<string> result;
    int N;

    bool isValid(string &curr)
    {
        int left = 0;
        for(int i = 0; i < curr.size(); i++)
        {
            if(curr[i] == '(') left++;
            else left--;

            if(left < 0 ) return false;
        }
        return left==0;
    }

    void solve(string& curr)
    {
        if(curr.size() == 2 * N)
        {
            if(isValid(curr))
            {
                result.push_back(curr);
            }
            return;
        }
        // DO 
        curr.push_back('(');
        solve(curr);
        // backtrack (undo)
        curr.pop_back();

        
        curr.push_back(')');
        solve(curr);
        curr.pop_back();
       
    }

    vector<string> generateParenthesis(int n) {
        N = n;
        string curr = "";
        solve(curr);
        return result;
    }
};

// methond -3  T.C : O(2^n)
//S.C : O(2*n) -> Removing constant -> O(n) -> recursion stack space - Max depth of recusion tree
class Solution {
public:
    vector<string> result;

    void solve(int n, string curr, int open, int close) {
        if(curr.length() == 2*n) {
            result.push_back(curr);
            return;
        }
        
        if(open < n) {
            curr.push_back('(');
            solve(n, curr, open+1, close);
            curr.pop_back();
        }
        if(close < open) {
            curr.push_back(')');
            solve(n, curr, open, close+1);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";

        solve(n, curr, 0, 0);

        return result;
    }
};
