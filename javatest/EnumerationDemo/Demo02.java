package EnumerationDemo;

import java.util.StringTokenizer;

/**
 * StringTokenizer
 * @author JawieZhu
 *
 */
public class Demo02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String emailStr="zhua@aa.com;azhu@qq.com;huihui@gou.com";
		StringTokenizer token=new StringTokenizer(emailStr,";");
		while(token.hasMoreElements()){
			System.out.println(token.nextElement());
		}
		
		
	}

}
