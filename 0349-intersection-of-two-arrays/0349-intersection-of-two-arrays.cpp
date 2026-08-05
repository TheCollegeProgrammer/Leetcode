class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
                
        unordered_set<int> st;
        unordered_set<int> ans;

        // Store all elements of nums1
        for (int num : nums1) {
            st.insert(num);
        }

        // Check common elements
        for (int num : nums2) {
            if (st.count(num)) {
                ans.insert(num);
            }
        }

        // Convert set to vector
        vector<int> result(ans.begin(), ans.end());

        return result;
    }
};