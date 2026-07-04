class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int count = 0;
        for(int i = 0; i < accounts.size(); i++){
            int curr = 0;
            for(int j = 0; j < accounts[0].size(); j++){
                curr += accounts[i][j];
            }
            if(curr > count){
                count = curr;
            }
        }
    return count;
    }
};