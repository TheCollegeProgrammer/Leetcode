class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++){
            if(mp.find(nums[i]) != mp.end()){ // iidhar map mai find kiya ki Interger exist karta hai ki nahi
                if(i - mp[nums[i]] <= k){ // yaha distance calculate karre hai
                    return true;
                }
            }
            mp[nums[i]] = i; // if found new int, add its index to map
        }
    return false;
    }
};