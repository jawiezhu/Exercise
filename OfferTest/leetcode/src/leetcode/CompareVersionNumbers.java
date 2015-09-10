package leetcode;



public class CompareVersionNumbers {
	
	
	public int compareVersion2(String version1,String version2){
		int indexA=0;
		int indexB=0;
		int countA=0;
		int countB=0;
		int max;
		int a;
		int b;
		
		while(indexA<version1.length()|| indexA<version2.length()){
			while(indexA<version1.length() && version1.charAt(indexA)!='.'){
				countA++;
				indexA++;
			}
			
			while(indexB<version2.length() &&version2.charAt(indexB)!='.'){
				countB++;
				indexB++;
			}
			
			max=countA>countB ? countA:countB;
			for(int i=max;i>=1;i--){
				if(countA-i>=0){
					a=version1.charAt(indexA-i)-'0';
				}else{
					a=0;
				}
				
				if(countB-i>=0){
					b=version2.charAt(indexB-i)-'0';
				}else{
					b=0;
				}
				
				if(a>b){
					return 1;
				}else if(a<b){
					return -1;
				}
			}
			
			countA=0;
			countB=0;
			indexA++;
			indexB++;
		}
		return 0;
	}


	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(compareVersion("1.1","1.10"));
	}
	
	/*
	 * 思路可能错误
	 */
	public static int compareVersion(String version1, String version2) {
        String[] v1=version1.split("\\.");
        String[] v2=version2.split("\\.");
        
     
        if(v1.length<v2.length){
        	String[] newv1=new String[2];
        	newv1[0]=v1[0];
        	newv1[1]="0";
        	v1=newv1;
        }else if(v1.length>v2.length){
        	String[] newv1=new String[2];
        	newv1[0]=v2[0];
        	newv1[1]="0";
        	v2=newv1;
        }else if(v1.length==1||v2.length==1){
        	String[] newv1=new String[2];
        	newv1[0]=v1[0];
        	newv1[1]="0";
        	v1=newv1;
        	
        	String[] newv2=new String[2];
        	newv2[0]=v2[0];
        	newv2[1]="0";
        	v2=newv2;
        }
        
        int flag=0;
        int vnum1=0;
        int vnum2=0;
        
        
        for(int i=0;i<v1[0].length();i++){
    		vnum1=vnum1*10+v1[0].charAt(i)-'0';
    	}
        
        for(int i=0;i<v2[0].length();i++){
    		vnum2=vnum2*10+v2[0].charAt(i)-'0';
    	}
      
    
        	
        if(vnum1==vnum2){
        	vnum1=0;
        	vnum2=0;
        		
        	if(v1[1].length()<v2[1].length()){
        		v1[1]=getSameLen(v1[1],v2[1]);
        	}else if(v1[1].length()>v2[1].length()){
        		v2[1]=getSameLen(v2[1],v1[1]);
        	}
        		
        	for(int i=0;i<v1[1].length();i++){
        		vnum1=vnum1*10+v1[1].charAt(i)-'0';
            	vnum2=vnum2*10+v2[1].charAt(i)-'0';
            	if(vnum1>vnum2) return 1;
            	if(vnum1<vnum2) return -1;
        	}
        		
        	if(vnum1==vnum2){
        		flag=0;
        	}else if(vnum1<vnum2){
        		flag=-1;
        	}else{
        		flag=1;
        	}
        }else if(vnum1>vnum2){
        	flag=1;
        }else{
        	flag=-1;
        }
  
        return flag;
        
    }
	
	
	private static String getSameLen(String s1, String s2) {
		// TODO Auto-generated method stub
		
		char[] ch=new char[s2.length()];
		for(int i=0;i<s1.length();i++){
			ch[i]=(char) s1.charAt(i);
		}
		for(int i=s1.length();i<s2.length();i++){
			ch[i]='0';
		}
		return new String(ch);
	
	}
	

}
