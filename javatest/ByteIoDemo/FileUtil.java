package ByteIoDemo;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

public class FileUtil {
	
	
	/**
	 * �ļ��Ŀ���
	 * @param Դ�ļ�
	 * @param Ŀ���ļ�
	 * @throws IOException 
	 */
	public static void copyFile(String srcPath,String destPath) throws IOException{
			copyFile(new File(srcPath),new File(destPath));
	}
	
	/**
	 * �ļ��Ŀ���
	 * @param Դ�ļ�File����
	 * @param Ŀ���ļ�File����
	 * @throws IOException 
	 */
	public static void copyFile(File src,File dest) throws IOException{
		//destΪ�Ѿ����ڵ��ļ��У����ܽ������ļ���ͬ�����ļ�
		if(dest.isDirectory()){
			System.out.println("ֻ�ܿ����ļ�");
			throw new IOException("ֻ�ܿ����ļ�");
		}
		
		
		//2.ѡ����
		InputStream is=new BufferedInputStream(new FileInputStream(src));
		OutputStream os=new BufferedOutputStream(new FileOutputStream(dest));
		//3.�ļ����� ѭ��+��ȡ+д��
		
		byte[] pic=new byte[1024];
		int len=0;
		while(-1!=(len=is.read(pic))){
			os.write(pic, 0, len);
		}
		os.flush(); //ǿ��ˢ��
		
		os.close();
		is.close();
	}
	
	
	
	
	
	public static void copyDir(String srcPath,String destPath){
		File src=new File(srcPath);
		File dest=new File(destPath);
		
		copyDir(src,dest);
	}
	
	
	/**
	 * �����ļ���
	 * @param src
	 * @param dest
	 */
	public static void copyDir(File src,File dest) {
		if(src.isDirectory()){
			
			 dest=new File(dest,src.getName());
			 System.out.println(dest.getName());
			 
			 if(dest.getAbsolutePath().contains(src.getAbsolutePath())){
				 System.out.println("��Ŀ¼���ܿ�������Ŀ¼��");
			 }
		}
		copyDirDetail(src,dest);
		
	}
	
	public static void copyDirDetail(File src,File dest){
		if(src.isFile()){
			try {
				FileUtil.copyFile(src, dest);
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}else if(src.isDirectory()){
			//ȷ��Ŀ���ļ��д���
			dest.mkdirs();
			for(File sub:src.listFiles()){
				//System.out.println(sub.getName());
				copyDir(sub,new File(dest,sub.getName()));
			}
		}
		
	
	}
	
}
