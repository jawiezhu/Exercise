package UDPDemo;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetSocketAddress;
import java.net.SocketAddress;
import java.net.SocketException;

/**
 * �ͻ���
 * 1. �����ͻ��� DatagramSocket ��+�ƶ��˿�
 * 2. ׼������ �ֽ�����
 * 3. ��� DatagramPacket + ��������ַ �Լ� �˿�
 * 4. ����
 * 5. �ͷ���Դ
 * @author JawieZhu
 *
 */
public class MyClient {

	public static void main(String[] args) throws IOException {
		// �����ͻ���+�˿�
		DatagramSocket client=new DatagramSocket(6666);//�˿ڲ��ܳ�ͻ
		//׼������
		String msg="UDP test~!";
		byte[] data=msg.getBytes();
		
		//��� ���͵ĵص��Լ��˿�
		DatagramPacket packet=new DatagramPacket(data,data.length,
				new InetSocketAddress("localhost",8888));
		
		//����
		client.send(packet);
		
		//�ͷ�
		client.close();

	}

}
