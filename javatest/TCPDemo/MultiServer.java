package TCPDemo;

import java.io.BufferedWriter;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * ���������� �ƶ��˿�
 * ���ܿͻ�������
 * ��������+��������
 * @author JawieZhu
 *
 *���ܶ���ͻ���
 */
public class MultiServer {

	public static void main(String[] args) throws IOException {
		//���������� �ƶ��˿�
		ServerSocket server=new ServerSocket(8888);//���������������localhost:8888 �Է�������������
		//���ܿͻ�������  ����ʽ
		while(true){ //��ѭ�� һ��accpet һ���ͻ���
			Socket socket=server.accept();
			System.out.println("һ���ͻ��˽�������");
			//��������
			String msg="welcome!";
			//�����
	
			
			DataOutputStream dos=new DataOutputStream(socket.getOutputStream());
			dos.writeUTF(msg);
			dos.flush();
		}
	}

}
