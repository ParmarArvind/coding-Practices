
class Solution {
public:
    int minCost(std::string colors, std::vector<int>& neededTime) {
        if (colors.size() < 2) {
            return 0; 
        }

        int total_min_cost = 0;
        int max_time_in_group = neededTime[0]; 
        
        for (int i = 1; i < colors.size(); ++i) {
            
            if (colors[i] == colors[i-1]) {
                
                if (neededTime[i] > max_time_in_group) {
                    
                    total_min_cost += max_time_in_group; 
                    max_time_in_group = neededTime[i]; 
                    
                } else {
                    
                    total_min_cost += neededTime[i];
                }

            } else {
                max_time_in_group = neededTime[i];
            }
        }

        return total_min_cost;
    }
};


//easy method 
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int prev=-1;
        int result=0;
        for(int i=0;i<n;i++)
            {
                if(prev==-1) prev=i;
                else if(colors[prev]==colors[i])
                {
                    if(neededTime[prev]<=neededTime[i])
                    {
                        result +=neededTime[prev];
                        prev=i;
                    }
                    else  result +=neededTime[i]; 
                }
                else prev=i;
            }
        return result;
    }
};
