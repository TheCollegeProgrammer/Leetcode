class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {

        vector<int> vec;
        for(int i = left; i <= right; ++i)
        {
            int n = i;
            bool con = true;
            while(n > 0)
            {
                int rem = n % 10; 
                if(rem == 0 || i % rem != 0) 
                {
                    con = false;
                    break;
                } 
                n /= 10;
            }
            if(con) vec.push_back(i);
        }
        return vec;
    }
};