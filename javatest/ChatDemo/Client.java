package ChatDemo;

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
		Socket client=new Socket("localhost",9999);
		
		//����̨������
		BufferedReader console=new BufferedReader(new InputStreamReader(System.in));
		DataOutputStream dos=new DataOutputStream(client.getOutputStream());
		DataInputStream dis=new DataInputStream(client.getInputStream());

		while(true){
			String info=console.readLine();
				
	
			//��������ٶ�ȡ
			//�������  �����
			dos.writeUTF(info);
			dos.flush();
			
			//��ȡ���� ������
			String msg=dis.readUTF();
			System.out.println(msg);
		}
	}

}
