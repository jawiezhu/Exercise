package leetcode;

public class PowerofTwo {

	public static boolean isPowerOfTwo(int n) {
        if(n==0) return false;
        while(n>0){
        	if(n%2==0)
        		n=n/2;
        	if(n%2!=0)
        		break;
        }
        
        if(n==1) return true;
        return false;
    }
	
	//2��N���ݵ��ص㣺������λΪ1�������λ��Ϊ0.
	public static boolean isPowerOfTwo2(int n){
		int cnt=0;
		while(n>0){
			cnt+=(n&0x01);
			n>>=1;
		}
		return cnt==1;
	}
	
	public static boolean isPowerOfTwo3(int n){
		int cnt=0;
		while(n>0){
			cnt++;
			n=(n-1)&n;
		}
		return cnt==1;
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(isPowerOfTwo(16));
	}

}
