package QueueDemo;

public class Demo02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		StackDemo<String> his=new StackDemo<String>(3);
		his.push("baidu");
		his.push("cl");
		his.push("sina");
		
		System.out.println(his.size());
		
		String item=null;
		while(null!=(item=his.pop()))
		{
			System.out.println(item);
		}
	}

}
