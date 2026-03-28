//Approach (Using Difference Array Technique)
//T.C : O(m+n), m = length of queries, n = length of array
//S.C : O(n)
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int m = shifts.size();
        int n = s.size();
        vector<int> forward(n, 0);
        vector<int> backward(n, 0);

        for (int i = 0; i < m; i++) {
            int start = shifts[i][0];
            int end = shifts[i][1];
            int direction = shifts[i][2];

            if (direction) {
                forward[start]++;
                if (end + 1 < n) forward[end + 1]--;
            } else {
                backward[start]++;
                if (end + 1 < n) backward[end + 1]--;
            }
        }

        // prefix sum (FIXED)
        for (int i = 1; i < n; i++) {
            forward[i] = (forward[i] + forward[i - 1]) % 26;
        }
        for (int i = 1; i < n; i++) {
            backward[i] = (backward[i] + backward[i - 1]) % 26;
        }

        // apply shifts (slight fix for negative safety)
        for (int i = 0; i < n; i++) {
            int f = forward[i] % 26;
            int b = backward[i] % 26;

            int val = (s[i] - 'a' + f - b) % 26;
            if (val < 0) val += 26;

            s[i] = val + 'a';
        }

        return s;
    }
};

// better version of previous approach
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n , 0); // Difference array with size n + 1
        
        // Step 1: Populate the difference array
        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];
            
            if (direction == 1) { // Forward shift
                diff[start] += 1;
                if(end+1 < n)
                    diff[end + 1] -= 1;
            } else { // Backward shift
                diff[start] -= 1;
                if(end+1 < n)
                    diff[end + 1] += 1;
            }
        }
        
        // Step 2: Compute the prefix sum to get the net shifts for each character
        for (int i = 1; i < n; ++i) {
            diff[i] += diff[i - 1]; // Add the value from the previous index
        }
        
        // Step 3: Apply the shifts to the string
        for (int i = 0; i < n; ++i) {
            int shift = diff[i] % 26; // Ensure shift is within the range [0, 25]
            if (shift < 0)
                shift += 26; // Handle negative shifts (backward)
            
            // Apply the shift to character
            s[i] = ((s[i] - 'a' + shift) % 26) + 'a';
            /*
                Note : s[i]-'a' gives the corresponding number of character s[i]
                       +shift adds the shift
                       %26 is to wrap around (0-25)
                       'a' + in the end converts back the number to character
            */
        }
        
        return s;
    }
};
