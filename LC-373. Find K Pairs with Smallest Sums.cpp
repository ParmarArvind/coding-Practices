//brute force  but TLE
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        int m=nums2.size();

        vector<vector<int>>result;
         priority_queue<
            tuple<long,int,int>,
            vector<tuple<long,int,int>>,
            greater<tuple<long,int,int>>
        > pq;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                long sum= (long)nums1[i] + (long)nums2[j];
                pq.push({sum,nums1[i],nums2[j]});
            }
        }

        while(k-- && !pq.empty())
        {
            auto [sum,num1,num2] = pq.top();
            pq.pop();

            result.push_back({num1, num2});
        }
        return result;
    }
};

//method -2  brute force accepted
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        int m=nums2.size();

        vector<vector<int>>result;
         priority_queue<
            tuple<long,int,int>,
            vector<tuple<long,int,int>>
        > pq;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                long  sum = (long)nums1[i]+ (long)nums2[j];
                if(pq.size()<k)  pq.push({sum,nums1[i] , nums2[j]});
                else if( get<0>(pq.top()) >sum)
                {
                    pq.pop();
                    pq.push({sum,nums1[i] , nums2[j]});
                }
                else break;
            }
        }

        while(k-- && !pq.empty())
        {
            auto [sum,num1,num2] = pq.top();
            pq.pop();

            result.push_back({num1, num2});
        }
        return result;
    }
};
