package test;

import java.awt.Button;
import java.awt.FlowLayout;
import java.awt.Frame;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class GuiDemo {
	public static void main(String[] args){
		Frame f=new Frame("my awt");
		f.setSize(500, 400);
		f.setLocation(300,200);
		f.setLayout(new FlowLayout());
		
		Button b=new Button("i am a button");
		
		f.add(b);
		f.addWindowListener(new MyWin());
		
		f.setVisible(true);
		
	}
}


class MyWin extends WindowAdapter{
	
	@Override
	public void windowClosing(WindowEvent e){
		System.out.println("closed!");
		System.exit(0);
	}
	
	@Override
	public void windowActivated(WindowEvent e){
		System.out.println("activated!");
	}
	
	@Override
	public void windowOpened(WindowEvent e){
		System.out.println("opened!");
	}
}