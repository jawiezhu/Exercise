package TCPDemo;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.net.UnknownHostException;

/**
 * �����ͻ��� �����ƶ�������+�˿� ��ʱ��������
 * ��������+��������
 * 
 * @author JawieZhu
 *
 */

public class Client {

	public static void main(String[] args) throws UnknownHostException, IOException {
		//�����ͻ��� ����ָ��������+�˿� ��ʱ��������
		Socket client=new Socket("localhost",8888);//���Ͷ˿� ��ϵͳ�ڲ��Զ�����
		//��������
//		BufferedReader br=new BufferedReader(new InputStreamReader(
//				client.getInputStream())); //������ InputStream
//		String echo=br.readLine(); 
//		System.out.println(echo);
		
		DataInputStream dis=new DataInputStream(client.getInputStream());
		String echo=dis.readUTF();
		System.out.println(echo);
	}

}
