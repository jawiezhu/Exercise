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
 */
public class Server {

	public static void main(String[] args) throws IOException {
		//���������� �ƶ��˿�
		ServerSocket server=new ServerSocket(8888);//���������������localhost:8888 �Է�������������
		//���ܿͻ�������  ����ʽ
		Socket socket=server.accept();
		System.out.println("һ���ͻ��˽�������");
		//��������
		String msg="welcome!";
		//�����
//		BufferedWriter bw=new BufferedWriter(
//				new OutputStreamWriter(
//						socket.getOutputStream())); //������ OutputStream
//		
//		bw.write(msg);
//		bw.newLine();
//		bw.flush(); //���ùرգ���Ȼ��·��ص�
		
		DataOutputStream dos=new DataOutputStream(socket.getOutputStream());
		dos.writeUTF(msg);
		dos.flush();
	}

}
