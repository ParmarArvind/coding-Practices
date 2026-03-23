//Approach - 1 rec+memo

class Solution {
public:
    int MOD=1e9+7;
    typedef long long ll;
    int m,n;
    vector<vector<pair<ll,ll>>> t;

    pair<ll ,ll> solve(vector<vector<int>>&grid, int i,int j){
        if(i==m-1 && j==n-1) return { grid[i][j] ,grid[i][j] };

        ll maxProduct=LLONG_MIN;
        ll minProduct=LLONG_MAX;

        if(t[i][j] != make_pair(LLONG_MIN,LLONG_MAX )) return t[i][j];
        if(i+1 < m ){
            auto [downMax,downMin]=solve(grid, i+1 ,j);
            maxProduct = max({maxProduct ,grid[i][j]*downMax ,grid[i][j]*downMin});
            minProduct = min({minProduct ,grid[i][j]*downMax ,grid[i][j]*downMin});
        }
        
        if(j+1 < n)
        {
            auto [rightMax,rightMin]=solve(grid, i ,j+1);
            maxProduct = max({maxProduct ,grid[i][j]*rightMax ,grid[i][j]*rightMin});
            minProduct = min({minProduct ,grid[i][j]*rightMax ,grid[i][j]*rightMin});
        }

        return t[i][j]={maxProduct, minProduct};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();

        t= vector<vector<pair<ll ,ll>>> (m, vector<pair<ll,ll>>( n, make_pair(LLONG_MIN,LLONG_MAX) ) );
        auto [maxProduct,minProduct]=solve(grid, 0,0);
        return  maxProduct<0 ? -1 :  maxProduct % MOD ;
    }
};

//Approach - 2 (Bottom Up)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    typedef long long ll;
    int MOD = 1e9+7;

    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        

        //bottom up dp lena padega
        vector<vector<pair<ll, ll>>> t(m, vector<pair<ll, ll>>(n));
        //t[i][j] = {maxVal, minVal} to reach from (0, 0) to (i, j)

        t[0][0] = {grid[0][0], grid[0][0]};

        //filling the first row
        for(int j = 1; j < n; j++) {
            t[0][j].first  = t[0][j-1].first  * grid[0][j]; //maxVal
            t[0][j].second = t[0][j-1].second * grid[0][j]; //minVal
        }

        //filling the first column
        for(int i = 1; i < m; i++) {
            t[i][0].first  = t[i-1][0].first  * grid[i][0]; //max Val
            t[i][0].second = t[i-1][0].second * grid[i][0]; //min val
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                ll upMax = t[i-1][j].first;
                ll upMin = t[i-1][j].second;

                ll leftMax = t[i][j-1].first;
                ll leftMin = t[i][j-1].second;

                t[i][j].first  = max({upMax * grid[i][j], upMin * grid[i][j], leftMax * grid[i][j], leftMin * grid[i][j]});
                t[i][j].second = min({upMax * grid[i][j], upMin * grid[i][j], leftMax * grid[i][j], leftMin * grid[i][j]});
            }
        }

        auto [maxProd, minProd] = t[m-1][n-1];

        return maxProd < 0 ? -1 : maxProd % MOD;
    }
};
