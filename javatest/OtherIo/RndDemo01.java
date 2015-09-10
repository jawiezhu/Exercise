package OtherIo;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;


/**
 * �ļ��ָ�˼·
 * 1 �ָ�Ŀ��� size n
 * 2 ÿһ��Ĵ�С blocksize
 * �ܵ��ļ��Ĵ�С [n-1]*blocksize
 * @author JawieZhu
 *
 */
public class RndDemo01 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		RandomAccessFile rnd=new RandomAccessFile(new File("/Volumes/HDD/java/test/testfile/azhu"),"r");
		rnd.seek(5);
		//���建���С
		byte[] flush=new byte[1024];
		int len=0;
		
		while(-1!=(len=rnd.read(flush))){
			if(len>=10){
			System.out.println(new String(flush,0,10));
			break;}
			else{
				System.out.println(new String(flush,0,len));
			}
		}
		
		rnd.close();
	}

}
