// Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

// For example,
// Given n = 3, there are a total of 5 unique BST's.

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3


class Solution {
public:
    int numTrees(int n) {
      vector<int> num;
      num.push_back(1);
      for(int i=1;i<=n;i++)
      {
          num.push_back(0);
          if(i<3)
            num[i]=i;
          else
          {
              for(int j=1;j<=i;j++)
                num[i]+=num[j-1]*num[i-j];
          }
      }
      
      return num[n];
    }
};


class Solution {
public:
    int mh[10000];
    int h(int n)
    {
        if(mh[n] != 0)
            return mh[n];
        mh[n] = (4*n-2)*h(n-1) / (n + 1);
        return mh[n];
    }
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        mh[1] = 1;
        mh[0] = 1;
        return h(n);
    }
};