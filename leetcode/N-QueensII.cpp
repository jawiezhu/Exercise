// Follow up for N-Queens problem.

// Now, instead outputting board configurations, return the total number of distinct solutions.

class Solution {
public:

bool isSafe(vector<int> &A,int r){
    for(int i=0;i<r;i++){
        if((A[i]==A[r])||(abs(A[i]-A[r]))==(r-i))
            return false;
    }
    return true;
}

void queen(int n,int &result,int cur,vector<int> &A){
    if(cur==n){
        result++;
        return ;
    }else{
        for(int i=0;i<n;i++){
            A[cur]=i;
            if(isSafe(A,cur))
                queen(n,result,cur+1,A);
        }
    }
}

    int totalNQueens(int n) {
        int result=0;
        vector<int> A(n,-1);
        queen(n,result,0,A);
        return result;
    }
};