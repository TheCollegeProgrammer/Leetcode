class Solution {
public:
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int vowels = 0;
        int ans = 0;
        for(int i = 0; i < k; i++){
            if(isVowel(s[i])){
                vowels++;
            }
        }
        ans = vowels;

        for(int i = k; i < s.size(); i++){
            if(isVowel(s[i - k])){
                vowels--;
            }
            if(isVowel(s[i])){
                vowels++;
            }
            ans = max(ans, vowels);
        }
    return ans;
    }
};