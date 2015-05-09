// Given numRows, generate the first numRows of Pascal's triangle.

// For example, given numRows = 5,
// Return

// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        
        vector<vector<int>> result;
        if(numRows==0) return result;
    vector<int> tem;
    tem.push_back(1);
    result.push_back(tem);
    if(numRows==1) return result;
    tem.push_back(1);
    result.push_back(tem);
    if(numRows==2) return result;
    for(int i=2;i<numRows;i++){
        vector<int> solu(i+1,1);
        for(int j=1;j<i;j++){
            solu[j] = result[i-1][j-1]+result[i-1][j];
        }
        result.push_back(solu);
    }
    return result;
    }
    
};


// 可以用队列，计算下一行时，给上一行左右各加一个0，然后下一行的每个元素，就等于左上角和右上角之和。

// 另一种思路，下一行第一个元素和最后一个元素赋值为1，中间的每个元素，等于上一行的左上角和右上角元素之和。
// LeetCode, Pascal's Triangle
// 时间复杂度O(n^2)，空间复杂度O(n)
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        if(numRows == 0) return result;

        result.push_back(vector<int>(1,1)); //first row

        for(int i = 2; i <= numRows; ++i) {
            vector<int> current(i,1);  // 本行
            const vector<int> &prev = result[i-2];  // 上一行

            for(int j = 1; j < i - 1; ++j) {
                current[j] = prev[j-1] + prev[j]; // 左上角和右上角之和
            }
            result.push_back(current);
        }
        return result;
    }
};

// LeetCode, Pascal's Triangle
// 时间复杂度O(n^2)，空间复杂度O(n)
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        vector<int> array;
        for (int i = 1; i <= numRows; i++) {
            for (int j = i - 2; j > 0; j--) {
                array[j] = array[j - 1] + array[j];
            }
            array.push_back(1);
            result.push_back(array);
        }
        return result;
    }
};



class Solution {
public:
    vector<vector<int> > generate(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        

        if ( n<=0 )
            return vector<vector<int> >();
        vector<int> level;
        vector<vector<int> > ret;
        for(int i=1;i<=n;i++)
        {
            int k=(int)level.size();
            for(int  j=k-1;j>=1;j--)
                level[j]+=level[j-1];
            level.push_back(1);
            ret.push_back(level);
        }
        return ret;
    }
};

