class Solution:
    # @param s, a string
    # @return an integer
    def titleToNumber(self, s):
        num=0
        for i in range(0,len(s)):
            num=num+pow(26,i)*(ord(s[len(s)-i-1])-64)
        return num

//ord与chr作用相反
//ord 字符转整型
//chr 整型转字符