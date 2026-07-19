class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        st.push(asteroids[0]);
        vector<int> ans;
        for(int i =1 ;i < asteroids.size();i++){
            int curr = asteroids[i];
            if(curr<0){
                while(!st.empty() && st.top()>0 && st.top()<abs(curr)){
                    st.pop();
                }
                if(st.empty() || st.top()<0){
                    st.push(curr);
                }
                else if(st.top() == abs(curr)){
                    st.pop();
                }
                else if(st.top()>abs(curr)){
                    continue;
                }
            }
            else{
                st.push(curr);
            }
        }
        while(!st.empty()){
            int curr=st.top();
            ans.push_back(curr);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};