class Solution {
public:
     void findNSR(vector<int>&NSR, vector<int>&height)
    {
        stack<int>st;
        int n=height.size();
       
        for(int j=n-1;j>=0;j--)
        {
            if(st.empty())
            {
                NSR[j]=n;
            }
            else
            {
                while(!st.empty() && height[st.top()] >= height[j] )
                {
                    st.pop();
                }
                if(st.empty())
                {
                    NSR[j]=n;
                }
                else {
                    NSR[j]=st.top();
                }
            }

            st.push(j);
        }
    }
    void findNSL(vector<int>&NSL, vector<int>&height)
    {
        stack<int>st;
        int n=height.size();
       
        for(int j=0;j<n;j++)
        {
            if(st.empty())
            {
                NSL[j]=-1;
            }
            else
            {
                while(!st.empty() && height[st.top()] >= height[j] )
                {
                    st.pop();
                }
                if(st.empty())
                {
                    NSL[j]=-1;
                }
                else {
                    NSL[j]=st.top();
                }
            }
            st.push(j);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> NSR(n);
        vector<int> NSL(n);
        findNSR(NSR,heights);
        findNSL(NSL,heights);

        int maxArea=0;
        for(int j=0;j<n;j++)
        {
            int width=NSR[j]-NSL[j]-1;
            int area=width*heights[j];
            maxArea=max(area,maxArea);
        }

        return maxArea;
    }
};
