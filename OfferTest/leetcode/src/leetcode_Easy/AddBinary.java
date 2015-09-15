package leetcode_Easy;

public class AddBinary {
	
	
	public static String addBinary(String a, String b) {
        int[] ca=new int[a.length()];
        int[] cb=new int[b.length()];
        
        
        // ���ַ������е�ֵת������ֵ��0����1
        for(int i=0;i<a.length();i++){
        	ca[i]=a.charAt(i)-'0';
        }
        // ���ַ������е�ֵת������ֵ��0����1
        for(int i=0;i<b.length();i++){
        	cb[i]=b.charAt(i)-'0';
        }
        
     // ʹ��ca����ĳ��ȳ�
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
        	ca[ai]=res%2; //�κ��� ��2��  ʣ��0����1
        	carry=res/2; //��2�� �õ� ��λ��
        	
        	ai--;
        	bi--;
        }
        
        
        
        //����ʣ�µ�����
        while(ai>=0){
        	res=ca[ai]+carry;
        	ca[ai]=res%2;
        	carry=res/2;
        	
        	if(carry==0)
        		break;
        	
        	ai--;
        }
        
        
        // ���ַ������е�ֵת�����ַ���0����1
        //��û���ⲽ�������� '0'+'0'���Ϊ''
        for(int i=0;i<ca.length;i++){
        	ca[i]=ca[i]+'0';
        }
        
        
        //����Ҫ��չ1λ
        if(carry==0){
        	char[] ch=new char[ca.length];
        	for(int i=0;i<ca.length;i++){
        		ch[i]=(char) ca[i];
        	}
        	return new String(ch);
        }else{
        	//��Ҫ��չһλ
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
