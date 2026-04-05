class Solution {
public:
    vector<int> findGoodIntegers(int n) {

        int m = cbrt(n);
        vector<int> result;
        unordered_map<int,int> freq;

        for(int b = 1; b <= m; b++)
        {
            for(int a = 1; a <= b; a++)
            {
                int x = a*a*a + b*b*b;;
                if(x > n) break;
                freq[x]++;
                if(freq[x] == 2) result.push_back(x);
            }
        }

        sort(result.begin(), result.end());

        return result;
    }
};
