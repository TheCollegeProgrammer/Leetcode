class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<bool> b(n+1,0);
        for(auto a : nums){
            b[a] = 1;
        }
        for(int i = 0; i < n+1; i++){
            if(b[i] == 0){
                return i;
            }
        }
    return -1;
    }
};