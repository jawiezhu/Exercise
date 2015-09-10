package UDPDemo;

import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetSocketAddress;
import java.net.SocketAddress;
import java.net.SocketException;

/**
 * �ͻ���
 * 1. �����ͻ��� DatagramSocket ��+�ƶ��˿�
 * 2. ׼������  double->�ֽ����� ���ֽ������������
 * 3. ��� DatagramPacket + ��������ַ �Լ� �˿�
 * 4. ����
 * 5. �ͷ���Դ
 * @author JawieZhu
 *
 */
public class Client {

	public static void main(String[] args) throws IOException {
		// �����ͻ���+�˿�
		DatagramSocket client=new DatagramSocket(6666);//�˿ڲ��ܳ�ͻ
		//׼������
		double num=88.88;
		
		byte[] data=convert(num);
		
		//��� ���͵ĵص��Լ��˿�
		DatagramPacket packet=new DatagramPacket(data,data.length,
				new InetSocketAddress("localhost",8888));
		
		//����
		client.send(packet);
		
		//�ͷ�
		client.close();

	}
	/**
	 * �ֽ����� ����Դ+ Data �����
	 * @param num
	 * @return
	 * @throws IOException 
	 */
	public static byte[] convert(double num) throws IOException{
		byte[] data=null;
		ByteArrayOutputStream bos=new ByteArrayOutputStream();
		DataOutputStream dos=new DataOutputStream(bos);
		dos.writeDouble(num);
		dos.flush();
		
		//��ȡ����
		data=bos.toByteArray();
		dos.close();
		
		return data;
	}

}
