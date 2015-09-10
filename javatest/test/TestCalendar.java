package test;

import java.util.Calendar;
import java.util.GregorianCalendar;

public class TestCalendar {
	public static void main(String[] args){
		Calendar c=new GregorianCalendar();
		c.set(2001, Calendar.FEBRUARY, 10, 8, 8, 8);
		System.out.println(c.get(Calendar.YEAR));
		
		
		c.add(Calendar.MONTH, -1);
		System.out.println(c.getTime());
	}
}
