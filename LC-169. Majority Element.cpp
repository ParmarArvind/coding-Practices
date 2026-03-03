//  method -1   O(n*n)
class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n=arr.size();
        int eleCount= 0;
        int ans=arr[0];
        for (int i = 0; i < n - 1; i++) 
        {
            int count=1;
            for (int j = i + 1; j < n; j++)
             {
                if (arr[i] == arr[j]) 
                {
                    count++;
                }
            }
            if(eleCount< count)
            {
                eleCount=count;
                ans=arr[i];
            } 
        }
        return ans;
    }
    
};


// method -2 O(n*logn)
class Solution {
public:
    int majorityElement(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int eleCount= 1;

        int prev=arr[0];
        for (int i = 1; i < n; i++) 
        {
           if(arr[i]==prev)
           {
            eleCount++;
           }
           else
           {
            prev=arr[i];
            eleCount=1;
           }
           if(eleCount > n/2) return arr[i];
        }
        return arr[0];
    }
    
};
