class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char , int> mpp;
        int ans=-1;
        for(char c : s){
            mpp[c]++;
        }
        for(auto it : s){
            if( mpp[it]== 1){
                ans= s.find(it);
                return ans;
            }
        }
        return ans;
    }
};