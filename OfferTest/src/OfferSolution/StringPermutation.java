package OfferSolution;

import java.util.LinkedList;
import java.util.Stack;

public class StringPermutation {
	static void permutation(char[] arr,int index,int size){
		
		
		if(index==size){
			for(int i=0;i<arr.length;i++){
				System.out.println(arr[i]+" ");
			}
			System.out.println();
		}else{
			for(int i=index;i<size;i++){
				if(i!=index&&arr[i]==arr[index])
					continue;
				
				swap(arr,i,index);
				permutation(arr,index+1,size);
				swap(arr,i,index);
			}
		}
	}

	private static void swap(char[] arr, int i, int index) {
		// TODO Auto-generated method stub
		char tmp=arr[i];
		arr[i]=arr[index];
		arr[index]=tmp;
	}
	
	
	
	public static LinkedList<String> permutation(String str){
		LinkedList<String> linkedstring=new LinkedList<String>();
		
		if(str.length()<=1){
			linkedstring.add(str);
			return linkedstring;
		}
		
		for(int i=0;i<str.length();i++){
			char ch=str.charAt(i);
			if(i>0&&ch==str.charAt(i-1)){
				continue;
			}
			String newStr=remove(str,i);
			LinkedList<String>newStrList=permutation(newStr);
			for(int j=0;j<newStrList.size();j++){
				linkedstring.add(ch+newStrList.get(j));
			}
		}
		return linkedstring;
	}

	private static String remove(String str, int i) {
		// TODO Auto-generated method stub
		if (i == 0) return str.substring(1, str.length());  
        if (i == str.length() - 1) return str.substring(0, i );  
        return str.substring(0, i) + str.substring(i + 1, str.length());  
	}	
}



//先从头扫描字符串的第一个字符。针对第一个字符，我们有两种选择：一是把这个字符放到组合中去，
//接下来我们需要在剩下的n-1个字符中选取m-1个字符；
//二是不把这个字符放到组合中去，接下来我们需要在剩下的n-1个字符中选择m个字符。
//这两种选择都很容易用递归实现。
class combiantion{
	public static void combiantion(char chs[]){
			if(chs.length==0) return;
			Stack<Character>stack=new Stack<Character>();
			for(int i=1;i<=chs.length;i++){
				combine(chs,0,i,stack);
			}
	}
	//从字符数组中第begin个字符开始挑选number个字符加入list中
	private static void combine(char[] chs, int begin, int number,
			Stack<Character> stack) {
		// TODO Auto-generated method stub
		if(number==0){
			System.out.println(stack.toString());
			return;
		}
		
		if(begin==chs.length){
			return;
		}
		
		stack.push(chs[begin]);
		combine(chs,begin+1,number-1,stack);
		stack.pop();
		combine(chs,begin+1,number,stack);
	}
}
