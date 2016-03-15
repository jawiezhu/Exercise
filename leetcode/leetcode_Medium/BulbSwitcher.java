package leetcode_Medium;

public class BulbSwitcher {
	public int bulbSwitch(int n){
		int cnt=0;
		for(int i=1;i*i<=n;i++)
			cnt++;
		
		return cnt;
	}
	
	//N以内完全平方数的个数。在1<=k<=n中，只有第1^2、2^2、3^2、4^2……m^2<=n个灯泡为on，m也就是要求的为on的灯泡总数，
	//m<=n的平方根，即对N开方向下取整。java对double类型向int转化正好是向下取整。
	
	public int bulbSwitch2(int n){
		return (int)Math.sqrt(n);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
