package leetcode_Easy;

public class CountPrimes {
	//������ɫ��ɸ��
	public int countPrimes(int n) {
        if(n<=1) return 0;
        
        boolean[] notPrime=new boolean[n];
        notPrime[0]=true;
        notPrime[1]=true;
        
        for(int i=2;i*i<n;i++){
        	// ���i��һ��������i��i�ı�������Ϊ������
            // ����i��һ�������������ض��Ѿ�����Ϊtrue�ˣ���Ϊ�Ǵ�2��ʼ�����
        	if(!notPrime[i]){
        		for(int j=2*i;j<n;j+=i){
        			notPrime[j]=true;
        		}
        	}
        }
        
        int res=0;
        for(boolean b:notPrime){
        	if(!b)
        		res++;
        }
        
        return res;
    }
}
