class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> n(nums.size());
        int left = 0;
        int pos = nums.size()-1;
        int right = nums.size()-1;
        while(left <= right){
            if(abs(nums[left]) > abs(nums[right])){
                n[pos] = nums[left] * nums[left];
                left++;
            }else{
                n[pos] = nums[right] * nums[right];
                right--;
            }
            pos--;
        }
    return n;
    }
};