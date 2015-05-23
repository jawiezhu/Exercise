// Given two strings s and t, determine if they are isomorphic.

// Two strings are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

// For example,
// Given "egg", "add", return true.

// Given "foo", "bar", return false.

// Given "paper", "title", return true.

// Note:
// You may assume both s and t have the same length

//就是记录遍历s的每一个字母，并且记录s[i]到t[i]的映射，
// 当发现与已有的映射不同时，说明无法同构，
// 直接return false。但是这样只能保证从s到t的映射，
// 不能保证从t到s的映射，所以交换s与t的位置再重来一遍上述的遍历就OK了。
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char>mp;
        for(int i=0;i<s.size();i++)
        {
        	if(mp.find(s[i])==mp.end()) mp[s[i]]=t[i];
        	else if(mp[s[i]]!=t[i]) return false;
        }

        mp.clear();

        for(int i=0;i<s.size();i++)
        {
        	if(mp.find(t[i])==mp.end()) mp[t[i]]=s[i];
        	else if(mp[t[i]]!=s[i]) return false;
        }

        return true;
    }
};


//建一个map保存映射关系, 同时用一个set保持 被映射的char, 保证同一个char 不会被映射两次. 
public class Solution {
    //test case: "egg", "add"
    
    public boolean isIsomorphic(String s, String t) {
        //init check
        if(s==null || t==null) return false;
        if(s.length() != t.length()) return false;
        
        Map<Character, Character> map = new HashMap<Character, Character>();
        Set<Character> set = new HashSet<Character>();
        
        for(int i=0; i<s.length(); i++) {
            char c1 = s.charAt(i);
            char c2 = t.charAt(i);
            
            if(map.containsKey(c1)) {
                if(map.get(c1) != c2) return false;
            } else {
                if(set.contains(c2)) return false;
                else {
                    map.put(c1, c2);
                    set.add(c2);
                }
            }
        }
        return true;
    }
}//


//
// 返回true需要满足两个条件：
// 1、不能出现s中的一个字符对应到t中两个不同的字符
// 2、不能出现s中的两个不同字符对应到t中同一个字符
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m != n)
            return false;
        unordered_map<char, char> m1;   //s --> t
        unordered_map<char, char> m2;   //t --> s
        for(int i = 0; i < m; i ++)
        {
            char schar = s[i];
            char tchar = t[i];
            // the same char in s map to different chars in t
            if(m1.find(schar) != m1.end() && m1[schar] != tchar)
                return false;
            // two different chars in s map tp the same char in t
            if(m2.find(tchar) != m2.end() && m2[tchar] != schar)
                return false;
            m1[schar] = tchar;
            m2[tchar] = schar;
        }
        return true;
    }
};

//
// 不必考虑两个字符串长度不同的情况。遍历字符串，使用map得到两个字符串中字符的映射，若新出现的字符对与map中保存的不同，则返回false。
// 需要注意，使用一个map对于 “ab”, “aa” 的情况可能无法判断，因为从a->a 和 b->a的key是不一样的，在map中无法查找到，而反过来则是 a->a 和 a->b显然是错误的，
// 因此，我们可以对两个字符串分别作为map的key，进行两次判断，避免错误的发生。
// 另一种做法是，仅使用一个字符串作为map的key，但是使用一个set保存每个key的value。
// 若处理完成后，set中元素个数小于map元素个数，则说明存在两个不同的key映射到了同一个value情况，返回false.
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
            return false;
        unordered_map<char, char> stringMap;
        for(size_t i = 0; i != s.size(); ++i)
        {
            char sc = s[i];
            char tc = t[i];
            if (stringMap.find(sc) == stringMap.end())
            {
                stringMap[sc] = tc;
            }
            else
            {
                if (stringMap[sc] != tc)
                    return false;
            }
        }

        unordered_set<char> stringSet;
        unordered_map<char, char>::iterator it = stringMap.begin();
        for(; it != stringMap.end(); ++it)
        {
            if (stringSet.find(it->second) != stringSet.end())
                return false;
            else
                stringSet.insert(it->second);
        }

        return true;
    }
};


//
//分析，题目要求判断一个字符串中是否可以有另一个字符串中得数字替换而来，
//如果直接尝试替换的话，其实实现比较麻烦，不如直接对两个字符串分解进行转换，看转换后的结果是否一致。
// 转换算法如下，依次用‘0’， ‘1‘...替换字符串出现的字符，如‘abc’替换为’012‘， ’abbc‘替换成’0112‘。
// 所以需要设置一张转换表，记录转换后每个字符对应的替代字符。代码如下：
class Solution {
public:
     string transferStr(string s){
        char table[128] = {0};
        char tmp = '0';
        for (int i=0; i<s.length(); i++) {
            char c = s.at(i);
            if (table[c] == 0) {
                table[c] = tmp++;
            }
            s[i] = table[c];
        }
        return s;
    }
    bool isIsomorphic(string s, string t) {
        
        if (s.length() != t.length()) {
            return false;
        }
        if (transferStr(s) == transferStr(t)) {
            return true;
        }
        return false;
    }
};


//

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int sTotTable[256];
        int tTosTable[256];
        int size = s.length();
        for (int i = 0; i < 256; i++)
        {
            sTotTable[i] = 300;
            tTosTable[i] = 300;
        }

        for (int i = 0; i < size; i++)
        {
            if (sTotTable[s[i]] == 300)
            {
                if (tTosTable[t[i]] == 300)
                {
                    sTotTable[s[i]] = t[i];
                    tTosTable[t[i]] = s[i];
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (sTotTable[s[i]] != t[i])
                {
                    return false;
                }
            }
        }

        return true;
    }
};