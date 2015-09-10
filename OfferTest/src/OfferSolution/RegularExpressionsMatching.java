package OfferSolution;

public class RegularExpressionsMatching {
	public static boolean match(String input,String pattern){
		if(input==null || pattern==null) return false;
		return matchCore(input,0,pattern,0);
	}

	private static boolean matchCore(String input, int i, String pattern, int p) {
		// TODO Auto-generated method stub
		
		//ƥ�䴮��ģʽ������β��˵��ƥ��ɹ�
		if(i>=input.length() && p>=pattern.length()) return true;
		
		//ֻ��ģʽ�������β��˵��ƥ��ʧ��
		if(i!=input.length() && p>=pattern.length()) return false;
		
		//ģʽ��δ������ƥ�䴮�п��ܽ����п���δ����
		
		//pλ�õ���һ���ַ���Ϊ*��
		if(p+1<pattern.length() && pattern.charAt(p+1)=='*'){
			//ƥ�䴮�Ѿ�����
			if(i>=input.length()){
				return matchCore(input,i,pattern,p+2);
			}else{//ƥ�䴮Ϊ����
				if(pattern.charAt(p)==input.charAt(i)|| pattern.charAt(p)=='.'){
					return // ƥ�䴮����ƶ�һ��λ�ã�ģʽ������ƶ�����λ��
							matchCore(input,i+1,pattern,p+2)
								 // ƥ�䴮����ƶ�һ��λ�ã�ģʽ�����ƶ�
								|| matchCore(input,i+1,pattern,p)
								// ƥ�䴮���ƶ���ģʽ������ƶ�����λ��
								|| matchCore(input,i,pattern,p+2);
				}else{
					return matchCore(input,i,pattern,p+2);
				}
			}
		}
		// ƥ�䴮�Ѿ�����
		if(i>=input.length()){
			return false;
		}else{
			// ƥ�䴮��û�н���
			if(input.charAt(i)==pattern.charAt(p)||pattern.charAt(p)=='.'){
				return matchCore(input,i+1,pattern,p+1);
			}
		}
		
		return false;
	}
	
	
	public static void main(String[] args) {
        System.out.println(match("", "") + "[" + true + "]");
        System.out.println(match("", ".*") + "[" + false + "]");
        System.out.println(match("", ".") + "[" + false + "]");
        System.out.println(match("", "c*") + "[" + true + "]");
        System.out.println();

        System.out.println(match("a", ".*") + "[" + true + "]");
        System.out.println(match("a", "a.") + "[" + false + "]");
        System.out.println(match("a", "") + "[" + false + "]");
        System.out.println(match("a", ".") + "[" + true + "]");
        System.out.println(match("a", "ab*") + "[" + true + "]");
        System.out.println(match("a", "ab*a") + "[" + false + "]");
        System.out.println();

        System.out.println(match("aa", "aa") + "[" + true + "]");
        System.out.println(match("aa", "a*") + "[" + true + "]");
        System.out.println(match("aa", ".*") + "[" + true + "]");
        System.out.println(match("aa", ".") + "[" + false + "]");
        System.out.println();

        System.out.println(match("ab", ".*") + "[" + true + "]");
        System.out.println(match("ab", ".*") + "[" + true + "]");
        System.out.println();

        System.out.println(match("aaa", "aa*") + "[" + true + "]");
        System.out.println(match("aaa", "aa.a") + "[" + false + "]");
        System.out.println(match("aaa", "a.a") + "[" + true + "]");
        System.out.println(match("aaa", ".a") + "[" + false + "]");
        System.out.println(match("aaa", "a*a") + "[" + true + "]");
        System.out.println(match("aaa", "ab*a") + "[" + false + "]");
        System.out.println(match("aaa", "ab*ac*a") + "[" + true + "]");
        System.out.println(match("aaa", "ab*a*c*a") + "[" + true + "]");
        System.out.println(match("aaa", ".*") + "[" + true + "]");
        System.out.println();

        System.out.println(match("aab", "c*a*b") + "[" + true + "]");
        System.out.println();

        System.out.println(match("aaca", "ab*a*c*a") + "[" + true + "]");
        System.out.println(match("aaba", "ab*a*c*a") + "[" + false + "]");
        System.out.println(match("bbbba", ".*a*a") + "[" + true + "]");
        System.out.println(match("bcbbabab", ".*a*a") + "[" + false + "]");
    }
}
