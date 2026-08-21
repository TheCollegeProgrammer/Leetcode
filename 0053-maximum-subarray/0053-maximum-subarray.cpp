class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = 0, Max_sum = INT_MIN;
        for(int val : nums){
            current_sum += val;
            Max_sum = max(current_sum, Max_sum);

            if(current_sum < 0){
                current_sum = 0;
            } 
        }
        return Max_sum;
    }
};