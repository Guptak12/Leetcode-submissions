class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i=0;
        int j=0;

        unordered_map<char,int> mp;

        int n = s.size();
        int mx=0;
        while(i<n){
            if(mp[s[i]]<2){
                mp[s[i]]++;
            }else{
                while(s[j]!=s[i]){
                    mp[s[j]]--;
                    j++;
                }
                j++;
            }

            mx=max(mx,i-j+1);
            i++;
            
        }

        return mx;
    }
};