package ChatDemo02;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * ����������
 * @author JawieZhu
 *
 */
public class Server {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		ServerSocket server=new ServerSocket(9999);
		
		
		
		Socket client=server.accept();
		
		
		//�ȶ�ȡ�������
		//д������
		//������		
		DataOutputStream dos=new DataOutputStream(client.getOutputStream());
		DataInputStream dis=new DataInputStream(client.getInputStream());
		
		while(true){ //���ܿͻ��˶�� ����
			String msg=dis.readUTF();
			//System.out.println(msg);
			
			//�������  �����
			dos.writeUTF("Server-->"+msg);
			dos.flush();
		}
	
		
		
	}

}
