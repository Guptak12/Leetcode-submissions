class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> s;
        int n = nums1.size();


        for(int i=0;i<n;i++){
            s.insert(nums1[i]);
        }
        vector<int> res;
        
        for(int j=0;j<n;j++){
            auto it = s.upper_bound(nums2[j]);
            if(it!=s.end()){
                res.push_back(*it);
                s.erase(it);
            }else{
                res.push_back(*s.begin());
                s.erase(s.begin());
            }
        }


        return res;

        

    }
};