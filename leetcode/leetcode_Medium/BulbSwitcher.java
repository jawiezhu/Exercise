package leetcode_Medium;

public class BulbSwitcher {
	public int bulbSwitch(int n){
		int cnt=0;
		for(int i=1;i*i<=n;i++)
			cnt++;
		
		return cnt;
	}
	
	//N������ȫƽ�����ĸ�������1<=k<=n�У�ֻ�е�1^2��2^2��3^2��4^2����m^2<=n������Ϊon��mҲ����Ҫ���Ϊon�ĵ���������
	//m<=n��ƽ����������N��������ȡ����java��double������intת������������ȡ����
	
	public int bulbSwitch2(int n){
		return (int)Math.sqrt(n);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
