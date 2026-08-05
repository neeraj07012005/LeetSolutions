class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int sum =0;
       int size=INT_MAX;
       int l =0;
       for(int r=0; r<nums.size();r++){
        sum +=nums[r];
        while(sum>target){
            size=min(size, r-l+1);
            sum-=nums[l];
            l++;
        }
        if(sum>=target){
            size=min(size , r-l+1);
        }
        
       } 
       if(size==INT_MAX){
            return 0;
        }
       return size;
    }
};