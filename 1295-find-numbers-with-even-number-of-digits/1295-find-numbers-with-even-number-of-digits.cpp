class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int a = 0;
        for(int n : nums){
        int count = 0;
            while(n > 0){
                count++;
                n /= 10; 
            }
            if(count % 2 == 0){
                 a++;   
                }
        }
    return a;
    }
};