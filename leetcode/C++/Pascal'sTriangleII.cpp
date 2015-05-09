// Given an index k, return the kth row of the Pascal's triangle.

// For example, given k = 3,
// Return [1,3,3,1].

// Note:
// Could you optimize your algorithm to use only O(k) extra space?

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> array;
        for (int i = 0; i <= rowIndex; i++) {
            for (int j = i - 1; j > 0; j--) {
                array[j] = array[j - 1] + array[j];
            }
            array.push_back(1);
            
        }
        return array;
    }
};



class Solution {
public:
    vector<int> getRow(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if ( n<0 )
    		return vector<int>();
		vector<int> level;
		for(int i=0;i<=n;i++)
		{
			int k=(int)level.size();
			for(int  j=k-1;j>=1;j--)
				level[j]+=level[j-1];
			level.push_back(1);
		}
		return level;
    }
};


//
// 对于产生一个新的行用从后往前的方法来更新，这样就只需一个O(k)的空间。

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> a(rowIndex + 1);
        
        a[0] = 1;
        for(int i = 1; i <= rowIndex; i++)
            for(int j = i; j >= 0; j--)
                if (j == i)
                    a[j] = a[j-1];
                else if (j == 0)
                    a[j] = a[j];
                else
                    a[j] = a[j-1] + a[j];
                    
        return a;                    
    }
};