package MyCalendar;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.Scanner;

/**
 * 
 * @author JawieZhu
 *
 */
public class VisualCalendar {
	public static void main(String[] args){
		
		
		Scanner scanner=new Scanner(System.in);
		String inputStr=scanner.nextLine();
		String temp=inputStr;
		DateFormat df=new SimpleDateFormat("yyyy-MM-dd");
		
		try {
			Date date=df.parse(temp);
			Calendar calendar=new GregorianCalendar();
			calendar.setTime(date);
			
			calendar.set(Calendar.DATE, 1);
			
			System.out.println(calendar.getTime());
			System.out.println(calendar.get(Calendar.DAY_OF_WEEK));
			System.out.println(calendar.getActualMaximum(Calendar.DATE));
			System.out.println("日\t一\t二\t三\t四\t五\t六");
			int cnt=calendar.get(Calendar.DAY_OF_WEEK);
			int j=0;
			for(int i=1;i<=calendar.getActualMaximum(Calendar.DATE);i++){
				while(cnt>1)
				{
					System.out.print(" "+"\t");
					cnt--;
					j++;
				}
					System.out.print(i+"\t");
				
				j++;
				if(j%7==0)
					System.out.println();
			}
		} catch (ParseException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	
		
		
	}
}
