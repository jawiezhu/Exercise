package IpDemo;

import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.UnknownHostException;

/**
 * �����˿� �� InetAddress�����ϼ���˿�
 * @author JawieZhu
 *
 */
public class InetSocketDemo01 {
	
	public static void main(String[] args) throws UnknownHostException {
		//��װ
		InetSocketAddress addr=new InetSocketAddress("127.0.0.1",9999);
		//�ֶ���ӣ���һ�� �� ����ַ��� Դ���� ִ�� �������е� getByName
		addr=new InetSocketAddress(InetAddress.getByName("127.0.0.1"),9999);
		System.out.println(addr.getHostName());
		System.out.println(addr.getPort());
		//����
		InetAddress add=addr.getAddress();
		System.out.println(add.getHostAddress()); //����ip��ַ
		System.out.println(add.getHostName()); 
		
		
		
		
	}

}
