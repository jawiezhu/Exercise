package convertDemo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * 转换流：字节转字符
 * 1. 输出流 OutputStreamWriter 编码
 * 2. 输入流 InputStreamReader 解码
 * @author JawieZhu
 *
 */
public class ConvertDemo02 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		//指定解码字符集
		BufferedReader br=new BufferedReader(
				new InputStreamReader(
				new FileInputStream(new File("/Volumes/HDD/java/test/testfile/newazhu","utf-8"))));
		//写出文件
		BufferedWriter bw=new BufferedWriter(
				new FileWriter("/Volumes/HDD/java/test/testfile/newazhu"));
		
		
		String info=null;
		while(null!=(info=br.readLine())){
			System.out.println(info);
		}
		
		br.close();
	}

}
