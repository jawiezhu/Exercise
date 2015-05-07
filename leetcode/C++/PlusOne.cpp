Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

// 精度不够，该方法行不通
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sizeofDigits=digits.size();
        vector<int> newdigits;
        int tmp=0;

        for(int i=0;i<sizeofDigits;i++)
        {
        	tmp=tmp*10+digits[i];
        }

        tmp=tmp+1;

        while(tmp<1)
        {
        	newdigits.push_back(tmp%10);
        	tmp=tmp/10;
        }

        reverse(newdigits.begin(),newdigits.end());
        return newdigits;
    }
};



//==========
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret(digits);
        reverse(ret.begin(), ret.end());
        
        int flag = 1;
        for(int i = 0; i < ret.size(); i++)
        {
            ret[i] += flag;
            flag = ret[i] / 10;
            ret[i] %= 10; 
        }
        
        if (flag == 1)
            ret.push_back(1);
        
        reverse(ret.begin(), ret.end());
        
        return ret;
    }
};


//
// LeetCode, Plus One
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        add(digits, 1);
        return digits;
    }
private:
    // 0 <= digit <= 9
    void add(vector<int> &digits, int digit) {
        int c = digit;  // carry, 进位

        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            *it += c;
            c = *it / 10;
            *it %= 10;
        }

        if (c > 0) digits.insert(digits.begin(), 1);
    }
};


// LeetCode, Plus One
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        add(digits, 1);
        return digits;
    }
private:
    // 0 <= digit <= 9
    void add(vector<int> &digits, int digit) {
        int c = digit;  // carry, 进位

        for_each(digits.rbegin(), digits.rend(), [&c](int &d){
            d += c;
            c = d / 10;
            d %= 10;
        });

        if (c > 0) digits.insert(digits.begin(), 1);
    }
};
