package UDPDemo;

import java.io.ByteArrayInputStream;
import java.io.DataInput;
import java.io.DataInputStream;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;

/**
 * �����
 * 1 ���������+�˿� DatagramSocket��+�ƶ�����
 * 2 ׼���������� �ֽ����� ��װ DatagramPacket
 * 3 �� ��������
 * 4 ���� �ֽ�����->double
 * @author JawieZhu
 *
 */
public class Server {

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
		double data=convert(packet.getData());
		
		System.out.println(data);
		
		//�ͷ�
		server.close();
		
	}
	/**
	 * �ֽ�����+ data ������
	 * @param data
	 * @return
	 * @throws IOException 
	 */
	public static double convert(byte[] data) throws IOException{
		DataInputStream dis=new DataInputStream(new ByteArrayInputStream(data));
		double num=dis.readDouble();
		
		dis.close();
		return num;
		
	}

}
