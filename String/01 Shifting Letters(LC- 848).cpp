//method 1 2 pass with cummulative sum of array 
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {

        int n=shifts.size();

        // find cummulative sum
        for(int i=n-2;i>=0;i--)
        {
            shifts[i]= shifts[i]%26 + shifts[i+1]%26;
        }

        // apply changes
        for(int i=0;i<n;i++)
        {
            s[i]= (s[i]-'a'+shifts[i])%26  +'a';
        }

        return s;
    }
};

// methos 2  single pass without cummulative sum
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {

        int n=shifts.size();

        // find cummulative sum
        int total=0;
        for(int i=n-1;i>=0;i--)
        {
           total =(total+shifts[i])%26;
           s[i] =(s[i]-'a' +total)%26 +'a';
        }
        
        return s;
    }
};
