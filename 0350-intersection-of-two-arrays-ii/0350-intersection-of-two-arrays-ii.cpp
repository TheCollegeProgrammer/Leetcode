class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> n;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int a = 0;
        int b = 0;
        while(a < nums1.size() && b < nums2.size()){
            if(nums1[a] == nums2[b]){
                n.push_back(nums1[a]);
                a++;
                b++;
            }else if(nums1[a] > nums2[b]){
                b++;
            }else{
                a++;
            }
        }
    return n;
    }
};