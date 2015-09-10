package NewsDemo;

import java.text.SimpleDateFormat;
import java.util.Date;

import javax.xml.crypto.Data;

public class NewsItem implements Comparable<NewsItem>{
	private String title;
	private int hits;
	private Date pubTime;
	
	
	public NewsItem() {
		super();
		// TODO Auto-generated constructor stub
	}
	
	public NewsItem(String title, int hits, Date pubTime) {
		super();
		this.title = title;
		this.hits = hits;
		this.pubTime = pubTime;
	}
	
	public String getTitle() {
		return title;
	}
	public void setTitle(String title) {
		this.title = title;
	}
	public int getHits() {
		return hits;
	}
	public void setHits(int hits) {
		this.hits = hits;
	}
	public Date getPubTime() {
		return pubTime;
	}
	public void setPubTime(Date pubTime) {
		this.pubTime = pubTime;
	}
	
	
	//时间降序+点击量升序+标题降序
	@Override
	public int compareTo(NewsItem o) {
		// TODO Auto-generated method stub
		int result=0;
		//比较时间
		result=-this.pubTime.compareTo(o.pubTime);//加- 升序变降序
		if(0==result){//时间相同
			//点击量
			result=this.hits-o.hits;
			if(0==result){//点击量相同
				//标题
				result=-this.title.compareTo(o.title);
			}
		}
		
		return result;
	}

	@Override
	public String toString() {
		StringBuilder sb=new StringBuilder();
		sb.append("Title:").append(this.title);
		sb.append("Time:").append(new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(this.pubTime));
		sb.append("Hits:").append(this.hits).append("\n");
		return sb.toString();
	}
	
	
	
	
}
