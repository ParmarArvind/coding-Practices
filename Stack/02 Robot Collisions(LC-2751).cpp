class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<tuple<int,int,char,int>> arr;
        for(int i = 0; i < n; i++) {
            arr.push_back({positions[i], healths[i], directions[i], i});
        }

        sort(arr.begin(), arr.end());

        stack<tuple<int,int,char,int>> st;

        for(int i = 0; i < n; i++) {
            auto [pos, health, dir, idx] = arr[i];

            if(dir == 'R') {
                st.push({pos, health, dir, idx});
            }
            else { // dir == 'L'
                while(!st.empty() && get<2>(st.top()) == 'R') {
                    auto [pos1, health1, dir1, idx1] = st.top();

                    if(health1 == health) {
                        st.pop();
                        health = 0;
                        break;
                    }
                    else if(health1 > health) {
                        st.pop();
                        st.push({pos1, health1 - 1, dir1, idx1});
                        health = 0;
                        break;
                    }
                    else {
                        st.pop();
                        health -= 1;
                    }
                }

                if(health > 0) {
                    st.push({pos, health, dir, idx});
                }
            }
        }

        // store survivors using index
        vector<int> ans(n, -1);

        while(!st.empty()) {
            auto [pos, health, dir, idx] = st.top();
            st.pop();
            ans[idx] = health;
        }

        vector<int> result;
        for(int i = 0; i < n; i++) {
            if(ans[i] != -1) result.push_back(ans[i]);
        }

        return result;
    }
};
