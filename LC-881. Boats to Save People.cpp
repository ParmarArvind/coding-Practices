class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i=0;
        int j=people.size()-1;
        int boats=0;
        while(i<=j)
        {
            int temp=limit;
            temp -=people[j];
            j--;
            boats++;
            if(people[i]<=temp)
            {
                i++;
            }
        }
        return boats;
    }
};
