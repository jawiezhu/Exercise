class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        res=A[0]
        for i in range(1,len(A)):
            res=res^A[i]
        return res


class Solution2:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        dict={}
        for i in range(len(A)):
            if A[i] not in dict:
                dict[A[i]]=1
            else:
                dict[A[i]]+=1
        for word in dict:
            if dict[word]==1:
                return word
           