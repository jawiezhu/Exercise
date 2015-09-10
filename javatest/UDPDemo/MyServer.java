package UDPDemo;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;

/**
 * �����
 * 1 ���������+�˿� DatagramSocket��+�ƶ�����
 * 2 ׼���������� �ֽ����� ��װ DatagramPacket
 * 3 �� ��������
 * 4 ����
 * @author JawieZhu
 *
 */
public class MyServer {

	public static void main(String[] args) throws IOException {
		//���������+����
		DatagramSocket server=new DatagramSocket(8888);
		
		//׼���������� 
		byte[] container=new byte[1024];
		//��װ�ɰ�
		DatagramPacket packet=new DatagramPacket(container,container.length);
		
		//��������
		server.receive(packet);
		
		//��������
		byte[] data=packet.getData();
		int len=packet.getLength();
		System.out.println("server get!"+new String(data,0,len));
		
		//�ͷ�
		server.close();
		
	}

}
