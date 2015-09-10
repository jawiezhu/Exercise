package sort;

import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
/**
 * �൱�� Collections
 * @author JawieZhu
 *
 */
public class Utils {
	/**
	 * List������+�Ƚ���
	 * @param list
	 * @param com
	 */
	public static <T> void sort(List<T>list,Comparator<T> com){
		//1.ת������
				Object [] arr=list.toArray();
				sort(arr,com);
				//2.�ı������ж�Ӧ��ֵ
				for(int i=0;i<arr.length;i++){
					list.set(i, (T)(arr[i]));
				}
	}
	
	/**
	 *���������+Comparator�ӿ�
	 */
	public static<T> void sort(Object[] str,Comparator<T> com){
		boolean sorted=true;
		int len=str.length;
		for(int j=0;j<len-1;j++){
			sorted=true;
			for(int i=0;i<len-1-j;i++){
				if(com.compare((T)str[i], (T)str[i+1])<0){
					Object temp=str[i];
					str[i]=str[i+1];
					str[i+1]=temp;
					sorted=false;
				}
				//System.out.println(Arrays.toString(str));
			}
			if(sorted)
				break;
		}
		}
	
	
	
	/**
	 * �������򣨷��ͣ�
	 */
	public static <T extends Comparable<T>> void sort(List<T> list){
		//1.ת������
		Object [] arr=list.toArray();
		sort(arr);
		//2.�ı������ж�Ӧ��ֵ
		for(int i=0;i<arr.length;i++){
			list.set(i, (T)(arr[i]));
		}
	}
	
	
	/**
	 * ��������ʹ�÷��ͷ���
	 */
	public static <T extends Comparable<T>> void sort(T[] str){
		boolean sorted=true;
		int len=str.length;
		for(int j=0;j<len-1;j++){
			sorted=true;
			for(int i=0;i<len-1-j;i++){
				if(((Comparable)str[i]).compareTo(str[i+1])>0){
					T temp=str[i];
					str[i]=str[i+1];
					str[i+1]=temp;
					sorted=false;
				}
				//System.out.println(Arrays.toString(str));
			}
			if(sorted)
				break;
		}
		}
	
	
	
	/**
	 * ��������� ������
	 */
	public static void sort(Object[] str){
		boolean sorted=true;
		int len=str.length;
		for(int j=0;j<len-1;j++){
			sorted=true;
			for(int i=0;i<len-1-j;i++){
				if(((Comparable)str[i]).compareTo(str[i+1])>0){
					Object temp=str[i];
					str[i]=str[i+1];
					str[i+1]=temp;
					sorted=false;
				}
				//System.out.println(Arrays.toString(str));
			}
			if(sorted)
				break;
		}
		}
}

