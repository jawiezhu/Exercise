package convertDemo;

import java.io.UnsupportedEncodingException;

public class ConvertDemo01 {

	public static void main(String[] args) throws UnsupportedEncodingException {
		// TODO Auto-generated method stub
		//�ֽ���������
		String str="�й�";
		byte[] data=str.getBytes();
		
		System.out.println(new String(data,0,3));
	}
	
	//��������� ������ͬ
	public static void test() throws UnsupportedEncodingException{
				//����byte->char
				String str="�й�";//gbk
				
				//���� char->byte
				byte[] data=str.getBytes();
				//�����������ַ�����ͬ
				System.out.println(new String(data));
				
				data=str.getBytes("utf-8");//�趨�����ַ���
				//�ַ���ͳһ ��������
				System.out.println(new String(data));
					
				//����
				byte[] data2="�й�".getBytes("utf-8");
				//����
				str=new String(data2,"utf-8");
				System.out.println(str);
	}

}
