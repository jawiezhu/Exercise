package ChatDemo02;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * 创建服务器
 * @author JawieZhu
 *
 */
public class Server {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		ServerSocket server=new ServerSocket(9999);
		
		
		
		Socket client=server.accept();
		
		
		//先读取，再输出
		//写出数据
		//输入流		
		DataOutputStream dos=new DataOutputStream(client.getOutputStream());
		DataInputStream dis=new DataInputStream(client.getInputStream());
		
		while(true){ //接受客户端多次 访问
			String msg=dis.readUTF();
			//System.out.println(msg);
			
			//输出数据  输出流
			dos.writeUTF("Server-->"+msg);
			dos.flush();
		}
	
		
		
	}

}
