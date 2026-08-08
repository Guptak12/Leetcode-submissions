class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        vector<int> res;
        int n = word1.size();
        int m =word2.size();
        vector<int> right(n);
        int k = m-1;
        int cnt=0;

        for(int i=n-1;i>=0;i--){
            right[i]=cnt;
            if(k>=0&&word1[i]==word2[k]){
                k--;
                cnt++;
            }
        }
        int j=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(j==m) break;

            if(word1[i]==word2[j]){
                res.push_back(i);
                j++;
            }else if(count==0&&right[i]>=m-1-j){
                res.push_back(i);
                j++;
                count=1;
            }
        }

        if(j==m)return res;
        return {};
    }
};