class Solution:
    # @param A, a list of integers
    # @param target, an integer to be inserted
    # @return integer
    def searchInsert(self, A, target):
        if len(A)==0:return None
        for i in range(0,len(A)):
            if target<=A[i]:
                return i
        return len(A)
            