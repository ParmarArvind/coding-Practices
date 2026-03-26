class Solution {
public:
     vector<vector<int>> ans;
     int n;
     void solve(vector<int>& candidates,int i, vector<int>& temp,int target)
     {

        if(target==0) 
        {
            ans.push_back(temp);
            return ;
        }
        if(target<0) return ;
        if(i>=n) return ;

       // take current element
        if(target>= candidates[i]) {
            temp.push_back(candidates[i]); //DO 
            solve(candidates,i,temp,target-candidates[i]);
            temp.pop_back(); // UNDO
        }

       //skip current element
        solve(candidates,i+1,temp,target);

     }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n=candidates.size();
        ans.clear();
        vector<int>temp;
        solve(candidates,0,temp,target);

        return ans;
        
    }
};
