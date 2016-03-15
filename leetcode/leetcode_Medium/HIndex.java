package leetcode_Medium;

import java.util.Arrays;

public class HIndex {
	
	//���䰴���������Ӹߵ������У����º˶ԣ�ֱ��ĳƪ���ĵ���Ŵ��ڸ����ı����������Ǹ���ż�ȥ1����hָ��
	public static int hIndex(int[] citations) {
		if(citations==null) return 0;
		Arrays.sort(citations);
		int index=0;
		for(int i=citations.length-1;i>=0;i--){
			index=citations.length-i;
			if(index>citations[i])	return index-1;
		}
		return citations.length;
	}
	
	
	public int hIndex2(int[] citations) {
        int size = citations.length;
        if(size<=0)
            return 0;
        Arrays.sort(citations);
        int count = 0;

        for(int i = size-1;i>=0;i--){
            if(count>=citations[i])
                return Math.max(count,citations[i]);
            count++;
        }
        return count;
    }
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int arr[]={0,0,0,1,5,99};
		System.out.println(hIndex(arr));
	}

}
