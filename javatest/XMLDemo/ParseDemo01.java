package XMLDemo;

import java.io.IOException;
import java.util.List;

import javax.swing.text.html.parser.Parser;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;

import org.xml.sax.SAXException;

public class ParseDemo01 {

	public static void main(String[] args) throws ParserConfigurationException, SAXException, IOException {
		// TODO Auto-generated method stub
		//获取解析工厂
		SAXParserFactory factory=SAXParserFactory.newInstance();
		//从解析工厂获取解析器
		SAXParser parse=factory.newSAXParser();
		//利用解析器 加载文档 注册处理器
		//编写处理器
		PersonHandler handler=new PersonHandler();
		parse.parse(Thread.currentThread().
				getContextClassLoader().
				getResourceAsStream("XMLDemo/person.xml"), 
				handler);
		List<Person> persons=handler.getPersons();
		
		for(Person p:persons){
			System.out.println(p.getName()+"----"+p.getAge());
		}
	}

}
