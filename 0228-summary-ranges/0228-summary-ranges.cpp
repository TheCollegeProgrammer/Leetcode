class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;

        if (nums.empty())
            return ans;

        int start = 0;

        for (int i = 1; i <= nums.size(); i++) {

            // Range break ho gayi
            if (i == nums.size() || nums[i] != nums[i - 1] + 1) {

                if (start == i - 1) {
                    // Single number
                    ans.push_back(to_string(nums[start]));
                } 
                else { // Range
                    ans.push_back(
                        to_string(nums[start]) + "->" +
                        to_string(nums[i - 1])
                    );
                }
                start = i;
            }
        }
        return ans;
    }
};