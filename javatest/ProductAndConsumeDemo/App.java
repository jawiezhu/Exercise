package ProductAndConsumeDemo;

public class App {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//��ͬ����Դ
		Movie m=new Movie();
		
		//���߳�
		Player p=new Player(m);
		Watcher w=new Watcher(m);
		
		new Thread(p).start();
		new Thread(w).start();
	}

}
