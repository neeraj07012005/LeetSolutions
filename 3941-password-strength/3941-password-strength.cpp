class Solution {
public:
    int passwordStrength(string password) {
        int ans = 0;
        unordered_set<char> st;

        for (char c : password) {
            st.insert(c);
        }

        for (char c : st) {
            if (c >= 'a' && c <= 'z') {
                ans++;
            }
            else if (c >= 'A' && c <= 'Z') {
                ans += 2;
            }
            else if (c >= '0' && c <= '9') {
                ans += 3;
            }
            else if (c == '!' || c == '@' || c == '#' || c == '$') {
                ans += 5;
            }
        }

        return ans;
    }
};