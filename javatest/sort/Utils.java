package sort;

import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
/**
 * 相当于 Collections
 * @author JawieZhu
 *
 */
public class Utils {
	/**
	 * List的排序+比较器
	 * @param list
	 * @param com
	 */
	public static <T> void sort(List<T>list,Comparator<T> com){
		//1.转成数组
				Object [] arr=list.toArray();
				sort(arr,com);
				//2.改变容器中对应的值
				for(int i=0;i<arr.length;i++){
					list.set(i, (T)(arr[i]));
				}
	}
	
	/**
	 *数组的排序+Comparator接口
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
	 * 容器排序（泛型）
	 */
	public static <T extends Comparable<T>> void sort(List<T> list){
		//1.转成数组
		Object [] arr=list.toArray();
		sort(arr);
		//2.改变容器中对应的值
		for(int i=0;i<arr.length;i++){
			list.set(i, (T)(arr[i]));
		}
	}
	
	
	/**
	 * 数组排序，使用泛型方法
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
	 * 数组的排序 工具类
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

