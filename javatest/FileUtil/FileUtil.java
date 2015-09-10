package FileUtil;

import java.io.Closeable;
import java.io.IOException;

public class FileUtil {

	/**
	 * ������ر���
	 * �ɱ���� ...ֻ�ܷ��β����һ��λ�ӣ�����ʽ������һ��
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
	 * ʹ�÷��ͷ���
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
