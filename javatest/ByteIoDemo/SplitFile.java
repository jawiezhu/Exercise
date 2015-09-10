package ByteIoDemo;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.RandomAccessFile;
import java.io.SequenceInputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Vector;

public class SplitFile {
	//文件路径
	private String filePath;
	//文件名
	private String fileName;
	//块数
	private int size;
	//每块大小
	private long blockSize;
	//每块的名称
	private List<String> blockPath;
	//文件大小
	private long length;
	//分割后的存放目录
	private String destBlockPath;
	
	
	public SplitFile(){
		blockPath=new ArrayList<String>();
	}
	
	public SplitFile(String filePath,String destBlockPath){
		this(filePath,destBlockPath,1024);
//		blockSize=1024;
//		this.filePath=filePath;
	}
	
	public SplitFile(String filePath,String destBlockPath,long blockSize){
		this();
		this.filePath=filePath;
		this.blockSize=blockSize;
		this.destBlockPath=destBlockPath;
		init();
	}
	
	/**
	 * 初始化操作 计算块数，确定文件名
	 */
	public void init(){
		File src=null;
		//健壮性
		if((filePath==null)||(!(((src=new File(filePath)).exists())))){
			return;
		}
		
		if(src.isDirectory()){
			return ;
		}
		//文件名
		this.fileName=src.getName();
		
		//计算块数 实际大小 与 每块大小
		this.length=src.length();
		//修正 每块大小
		if(this.blockSize>length){
			this.blockSize=length;
		}
		//确定块数
		size=(int)(Math.ceil(length*1.0/this.blockSize));
		initPathName();
		
	}
	
	private void initPathName(){
		for(int i=0;i<size;i++){
			this.blockPath.add(destBlockPath+"/"+this.fileName+".part"+i);
		}
	}
	
	/**
	 * 文件分割
	 * 
	 * 1 起始位置
	 * 2 实际大小
	 * @param destPath 分割文件的存放目录
	 * @throws IOException 
	 */
	public void split(String destPath) throws IOException{
		
		long beginPos=0;//起始点
		long actualBlockSize=blockSize;//实际大小
		
		//计算所有块的大小位置还有索引
		for(int i=0;i<size;i++){
			if(i==size-1){
				actualBlockSize=this.length-beginPos;
			}
			splitDetail(i,beginPos,actualBlockSize);
			beginPos+=actualBlockSize;
		}
	}
	
	/**
	 * 文件的分割 输入输出
	 * 文件的拷贝
	 * @param idx
	 * @param beginPos
	 * @param actualBolockSize
	 * @throws IOException 
	 */
	private void splitDetail(int idx,long beginPos,long actualBlockSize) throws IOException{
		//创建源
		File src=new File(this.filePath);//源文件
		File dest=new File(this.blockPath.get(idx));//目标文件
		//选择流
		RandomAccessFile raf=null; //输入流
		BufferedOutputStream bos=null;//输出流
		try {
			raf=new RandomAccessFile(src,"r");
			bos=new BufferedOutputStream(new FileOutputStream(dest));
		
			//读取文件
			raf.seek(beginPos);
			//缓冲区
			byte[] flush=new byte[1024];
			//接受长度
			int len=0;
			while(-1!=(len=raf.read())){
				if(actualBlockSize-len>=0){
					//写出
					bos.write(flush,0,len);
					actualBlockSize-=len;//剩余量
				}else{
					//直接写出剩余量
					bos.write(flush,0,(int)actualBlockSize);
					break;
				}
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally{
			bos.close();
			raf.close();
		}
	}
	
	public void mergeFile(String destPath) throws IOException{
		//创建源
		File dest=new File(destPath);
		//选择流
		BufferedOutputStream bos=null;
		try {
			bos=new BufferedOutputStream(new FileOutputStream(dest,true));
			BufferedInputStream bis=null;
			for(int i=0;i<this.blockPath.size();i++){
				bis=new BufferedInputStream(new FileInputStream(
						new File(this.blockPath.get(i))));
				
				
				byte[] flush=new byte[1024];
				int len=0;
				while(-1!=(len=bis.read(flush))){
					bos.write(flush,0,len);
				}
				bos.flush();
				bis.close();
			}
		}catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally{
				bos.close();
			}
		}

	/**
	 * 使用 SequenceInputStream
	 * @param destPath
	 * @throws IOException
	 */
	public void merge1(String destPath) throws IOException{
		//创建源
		File dest=new File(destPath);
		//选择流
		BufferedOutputStream bos=null;
		SequenceInputStream sis=null;
		//创建一个容器
		Vector<InputStream> vi=new Vector<InputStream>();
		
		
		try {
			
			for(int i=0;i<this.blockPath.size();i++){
				
				vi.add(new BufferedInputStream(new FileInputStream(
						new File(this.blockPath.get(i)))));
			}
				
			bos=new BufferedOutputStream(new FileOutputStream(dest,true));
			
			sis=new SequenceInputStream(vi.elements());
				
				
				byte[] flush=new byte[1024];
				int len=0;
				while(-1!=(len=sis.read(flush))){
					bos.write(flush,0,len);
				}
				bos.flush();
				sis.close();
			
		}catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally{
				bos.close();
			}
		}

	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		SplitFile split=new SplitFile("/Volumes/HDD/java/test/testfile/gougou.java","/Volumes/HDD/java/test/testfile/1",50);
		//System.out.println(split.size);
		split.split("/Volumes/HDD/java/test/testfile/1");
		split.mergeFile("/Volumes/HDD/java/test/azhu.java");
		
		
		
	}

}
