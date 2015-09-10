package FileUtil;

import java.io.Closeable;
import java.io.IOException;

public class FileUtil {

	/**
	 * 工具类关闭流
	 * 可变参数 ...只能放形参最后一个位子，处理方式与数组一致
	 */
	public static void close(Closeable ... io){
		for(Closeable temp:io){
			if(null!=temp){
				try {
					temp.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
	}
	
	/**
	 * 使用泛型方法
	 */
	public static <T extends Closeable>void closeAll(T ... io){
		for(Closeable temp:io){
			if(null!=temp){
				try {
					temp.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
	}

}
