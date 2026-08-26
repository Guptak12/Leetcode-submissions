class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int count = 0;
        int j = 0;
        string ans = "";

        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                count++;
            }

            while(count==k){
                string sub = s.substr(j,i-j+1);
                if(ans.empty()||sub.size()<ans.size()||(sub.size() == ans.size() && sub < ans)){
                    ans=sub;
                }

                if(s[j]=='1')count--;
                j++;
            }
        }
        
        return ans;

    }
};