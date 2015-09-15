package leetcode_Easy;

public class AddBinary {
	
	
	public static String addBinary(String a, String b) {
        int[] ca=new int[a.length()];
        int[] cb=new int[b.length()];
        
        
        // 将字符数组中的值转换了数值的0或者1
        for(int i=0;i<a.length();i++){
        	ca[i]=a.charAt(i)-'0';
        }
        // 将字符数组中的值转换了数值的0或者1
        for(int i=0;i<b.length();i++){
        	cb[i]=b.charAt(i)-'0';
        }
        
     // 使用ca保存的长度长
        if(ca.length<cb.length){
        	int[] tmp=ca;
        	ca=cb;
        	cb=tmp;
        }
        
        int ai=ca.length-1;
        int bi=cb.length-1;
        int carry=0;
        int res=0;
        
        
        
        while(ai>=0&&bi>=0){
        	res=ca[ai]+cb[bi]+carry;
        	ca[ai]=res%2; //任何数 被2余  剩下0或者1
        	carry=res/2; //被2除 得到 进位数
        	
        	ai--;
        	bi--;
        }
        
        
        
        //处理剩下的数字
        while(ai>=0){
        	res=ca[ai]+carry;
        	ca[ai]=res%2;
        	carry=res/2;
        	
        	if(carry==0)
        		break;
        	
        	ai--;
        }
        
        
        // 将字符数组中的值转换了字符的0或者1
        //若没有这步，则会出现 '0'+'0'结果为''
        for(int i=0;i<ca.length;i++){
        	ca[i]=ca[i]+'0';
        }
        
        
        //不需要扩展1位
        if(carry==0){
        	char[] ch=new char[ca.length];
        	for(int i=0;i<ca.length;i++){
        		ch[i]=(char) ca[i];
        	}
        	return new String(ch);
        }else{
        	//需要扩展一位
        	char[] ch=new char[ca.length+1];
        	ch[0]='1';
        	for(int i=0;i<ca.length;i++){
        		ch[i+1]=(char) ca[i];
        	}
        	return new String(ch);
        }
    }
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
	}

}
