package NewsDemo;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Date;
import java.util.List;

import sort.Utils;

public class NewsItemApp {
	public static void main(String[] args){
		 List<NewsItem> news=new ArrayList<NewsItem>();
		 news.add(new NewsItem("aaaa",100,new Date()));
		 news.add(new NewsItem("abbaa",19,new Date(System.currentTimeMillis()-1000*60*60)));
		 news.add(new NewsItem("abbaa",1000,new Date(System.currentTimeMillis()-1000*60*60)));
		 
		 System.out.println(news);
		 Utils.sort(news);
		 
		 Collections.sort(news);
		 System.out.println(news);
	}
}
