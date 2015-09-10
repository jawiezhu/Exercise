package convertDemo;

import java.io.UnsupportedEncodingException;

public class ConvertDemo01 {

	public static void main(String[] args) throws UnsupportedEncodingException {
		// TODO Auto-generated method stub
		//字节数不完整
		String str="中国";
		byte[] data=str.getBytes();
		
		System.out.println(new String(data,0,3));
	}
	
	//编码与解码 必须相同
	public static void test() throws UnsupportedEncodingException{
				//解码byte->char
				String str="中国";//gbk
				
				//编码 char->byte
				byte[] data=str.getBytes();
				//编码与解码的字符集相同
				System.out.println(new String(data));
				
				data=str.getBytes("utf-8");//设定编码字符集
				//字符不统一 出现乱码
				System.out.println(new String(data));
					
				//编码
				byte[] data2="中国".getBytes("utf-8");
				//解码
				str=new String(data2,"utf-8");
				System.out.println(str);
	}

}
