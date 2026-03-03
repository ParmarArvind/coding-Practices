class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        vector<int>ans;
        ans.push_back(arr[0]);
        for(int i=1; i<arr.size();i++)
        {
            if(arr[i]!=arr[i-1])
            {
                ans.push_back(arr[i]);
            }
            
        }
        int k= ans.size();
        arr.clear(); 
        for(int i=0; i<ans.size();i++)
        {
            arr.push_back(ans[i]);
        }
        return k;

    }
};

// in-place
class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int k=1;
        int prev=arr[0];
        for(int i=1; i<arr.size();i++)
        {
            if(arr[i] != prev)
            {
                arr[k]=arr[i];
                k++;
            }
            prev=arr[i];
        }
        return k;

    }
};
