package leetcode_Medium;

import java.util.Arrays;

public class HIndex {
	
	//让其按被引次数从高到低排列，往下核对，直到某篇论文的序号大于该论文被引次数，那个序号减去1就是h指数
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
