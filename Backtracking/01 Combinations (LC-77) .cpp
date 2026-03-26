// method -1
class Solution {
public:
    vector<vector<int>> ans;
     int N;
     void solve(vector<int>& candidates,int i, int k,vector<int>& temp)
     {
        if(temp.size()==k) 
        {
            ans.push_back(temp);
            return ;
        }
        if(i>=N) return ;

       // take current number
        temp.push_back(candidates[i]);
        solve(candidates,i+1,k,temp);
        temp.pop_back();

       // skip current number
        solve(candidates,i+1,k,temp);

     }

    vector<vector<int>> combine(int n, int k) {
        ans.clear();
        N=n;
        vector<int>candidate;
        for(int i=0;i<n;i++) candidate.push_back(i+1);
        vector<int> temp;
        solve(candidate , 0, k, temp);
        return ans;
    }
};
