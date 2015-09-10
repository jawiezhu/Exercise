package ChatDemo04;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.net.UnknownHostException;

/**
 * �����ͻ��ˣ���������+��������
 * @author JawieZhu
 *
 *д������  �����
 *��ȡ����  ������
 *
 *������ �� ����� Ŀǰ��ͬһ���߳��ڣ�Ӧ�����ζ��� ���ö��߳�
 *
 */
public class Client {

	public static void main(String[] args) throws UnknownHostException, IOException {
		// TODO Auto-generated method stub
		System.out.println("����������:");
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String name =br.readLine();
		if(name.equals("")){
			return;
		}
		
		
		Socket client=new Socket("localhost",9999);
		
		//����̨������
		new Thread(new Send(client,name)).start();//һ��·��
		
		new Thread(new Receive(client)).start();
	}

}
