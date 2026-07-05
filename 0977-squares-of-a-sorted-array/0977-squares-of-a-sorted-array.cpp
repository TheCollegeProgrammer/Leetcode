class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> n;
        for(auto i : nums){
            n.push_back(i*i);
        }
        sort(n.begin(), n.end());
    return n;
    }
};