package Map;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;

/**
 * 定义一个Student类，属性：name classNumber score
 * 现在将若干Student对象放入list，请统计出每个班级的总分和平均分，分别打印出来
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
	
	//统计分数
	public static void count(Map<String,ClassRoom> rooms,List<Student> list){
		for(Student stu:list){
			String number=stu.getNumber();
			double score=stu.getScore();
			//根据班级编号，查看map中是否存在该班级，分拣
			
			ClassRoom room=rooms.get(number);
			if(room==null){
				room=new ClassRoom();
				rooms.put(number, room);
			}
			
			//存储
			room.setTotal(room.getTotal()+score);
			room.getStus().add(stu);//加入学生
			
		}
	}
	
	//打印总分与平均分
	//存在问题，room.getNumber()为null
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
