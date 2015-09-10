package OfferSolution;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class FirstNotRepeatingChar {
	public static void FirstNotRepeatingChar(String s){
		Map<Character,Com> map=new HashMap<Character,Com>();
		for(int i=0;i<s.length();i++){
			if(map.containsKey(s.charAt(i))){
				map.get(s.charAt(i)).setB();
			}else{
				map.put(s.charAt(i), new Com(i+1,1));
			}
		}
		
		Iterator<Character> it=map.keySet().iterator();
		int flag=s.length();
		while(it.hasNext()){
			char c=it.next();
			if(map.get(c).b==1){
				flag=map.get(c).a<flag?map.get(c).a:flag;
			}
		}
		
		System.out.println(s.charAt(flag-1));
	}
	
	
	public static void  Solution2(String s){
		if(s==null) return ;
		
		int [] hash=new int[256];
		
		for(int i=0;i<s.length();i++){
			hash[s.charAt(i)]++;
		}
		
		for(int i=0;i<s.length();i++){
			if(hash[s.charAt(i)]==1){
				System.out.println(s.charAt(i));
				break;
			}
				
		}
		
		return ;
	}
	
	
	
	
	public static void main(String[] args){
		Solution2("aedabaccff");
	}
}

class Com{
	int a;
	int b;
	Com(int a,int b){
		this.a=a;
		this.b=b;
	}
	void setB(){
		this.b++;
	}
}
