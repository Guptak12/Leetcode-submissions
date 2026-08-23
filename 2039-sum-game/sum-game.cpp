class Solution {
public:
    bool sumGame(string nums) {
        int n = nums.size();
        int ls=0,rs=0;
        int ln=0,rn=0;
        int i=0,j=n-1;

        while(i<j){
            if(nums[i]=='?'){
                ln++;
            }else{
                ls+=nums[i]-'0';
            }

            if(nums[j]=='?'){
                rn++;
            }else{
                rs+=nums[j]-'0';
            }
            i++;
            j--;
        }

        if(2*(ls-rs)==9*(rn-ln)){
            return false;
        }
        
        return true;
    }
};