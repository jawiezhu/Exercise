package sort;

import java.util.Comparator;

public class StrComparator implements Comparator<String> {

	/**
	 * 按照长度比较
	 * 正数>
	 * 负数<
	 * 0 --
	 */
	@Override
	public int compare(String o1, String o2) {
		// TODO Auto-generated method stub
		int len1=o1.length();
		int len2=o2.length();
		
		return len1-len2;
	}

}
