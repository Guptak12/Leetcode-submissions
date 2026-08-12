class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int mx=1;
        unordered_map<int,int> m;
        int i=0,j=0;
        while(i<n&&j<n){
            if(m[nums[i]]>=k){
                while(nums[j]!=nums[i]){
                    m[nums[j]]--;
                    j++;
                }
                j++;
            }else{
                m[nums[i]]++;
            }

            mx=max(mx,i-j+1);
            i++;
        }

        return mx;
    }
};