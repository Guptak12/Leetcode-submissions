class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorv =0;
        int n = nums.size();
        bool flag=false;
        for(int i=0;i<n;i++){
            xorv ^=nums[i];
            if(nums[i]!=0){
                flag=true;
            }
        }

        if(xorv!=0) return n;
        if(flag) return nums.size()-1;
        return 0;
        
    }
};