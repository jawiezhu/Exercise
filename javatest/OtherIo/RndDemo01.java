package OtherIo;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;


/**
 * 文件分割思路
 * 1 分割的块数 size n
 * 2 每一块的大小 blocksize
 * 总的文件的大小 [n-1]*blocksize
 * @author JawieZhu
 *
 */
public class RndDemo01 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		RandomAccessFile rnd=new RandomAccessFile(new File("/Volumes/HDD/java/test/testfile/azhu"),"r");
		rnd.seek(5);
		//定义缓冲大小
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
