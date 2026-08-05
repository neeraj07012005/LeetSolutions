class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int ,int> mpp;
        int ans = INT_MIN ;
        int l = 0 ;
        int sum =0;
        for(int r = 0 ; r < nums.size() ; r++){
            mpp[nums[r]]++;
            sum+= nums[r];
            while(mpp[nums[r]]>1){
                mpp[nums[l]]--;
                sum-=nums[l];
                if(mpp[nums[l]]<0){
                    mpp.erase(nums[l]);
                    
                }
                l++;
            }
            
            ans = max(sum , ans);
        }
        return ans;
    }
};