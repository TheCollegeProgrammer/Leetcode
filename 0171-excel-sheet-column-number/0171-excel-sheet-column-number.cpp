class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int sum = 0;
        int count = 1;
        for(int i = 0; i < n; i++){
            int value = columnTitle[i] - 'A' + 1;
            sum = sum * 26 + value;
        }
    return sum;
    }
};