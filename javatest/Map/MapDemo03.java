package Map;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;

/**
 * ����һ��Student�࣬���ԣ�name classNumber score
 * ���ڽ�����Student�������list����ͳ�Ƴ�ÿ���༶���ֺܷ�ƽ���֣��ֱ��ӡ����
 * @author JawieZhu
 *
 */
public class MapDemo03 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		List<Student> list=new ArrayList<Student>();
		exam(list);
		
		Map<String,ClassRoom>rooms=new HashMap<String,ClassRoom>();
		count(rooms,list);
		printScore(rooms);
	}
	
	//ͳ�Ʒ���
	public static void count(Map<String,ClassRoom> rooms,List<Student> list){
		for(Student stu:list){
			String number=stu.getNumber();
			double score=stu.getScore();
			//���ݰ༶��ţ��鿴map���Ƿ���ڸð༶���ּ�
			
			ClassRoom room=rooms.get(number);
			if(room==null){
				room=new ClassRoom();
				rooms.put(number, room);
			}
			
			//�洢
			room.setTotal(room.getTotal()+score);
			room.getStus().add(stu);//����ѧ��
			
		}
	}
	
	//��ӡ�ܷ���ƽ����
	//�������⣬room.getNumber()Ϊnull
	public static void printScore(Map<String,ClassRoom> rooms){
		Set<Map.Entry<String,ClassRoom>> entrySet=rooms.entrySet();
		
		Iterator<Map.Entry<String,ClassRoom>> it=entrySet.iterator();
		 
		while(it.hasNext()){
			Map.Entry<String, ClassRoom> entry=it.next();
			ClassRoom room=entry.getValue();
			double avg=room.getTotal()/room.getStus().size();
			System.out.println(room.getNumber()+":"+room.getTotal()+"-"+avg);
		}
	}
	
	
	public static void exam(List<Student> list){
		list.add(new Student("a","001",80));
		list.add(new Student("b","001",88));
		list.add(new Student("c","002",99));
		list.add(new Student("d","003",95));
		list.add(new Student("e","003",77));
		
	}

}
