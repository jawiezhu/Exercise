package secondarySort;

import java.io.DataInput;
import java.io.DataOutput;
import java.io.IOException;
import java.util.StringTokenizer;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.io.WritableComparable;
import org.apache.hadoop.io.WritableComparator;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.Partitioner;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.input.TextInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.mapreduce.lib.output.TextOutputFormat;
import org.apache.hadoop.util.GenericOptionsParser;

public class secondarySort {
	public static class MyPairWritable implements WritableComparable<MyPairWritable>
	{
		IntWritable first;
		IntWritable second;
		IntWritable third;
		
		public void set(IntWritable first,IntWritable second,IntWritable third)
		{
			this.first=first;
			this.second=second;
			this.third=third;
		}
		
		public IntWritable getFirst()
		{
			return first;
		}
		
		public IntWritable getSecond()
		{
			return second;
		}
		
		public IntWritable getThird()
		{
			return third;
		}
		
		public void readFields(DataInput in) throws IOException
		{
			first=new IntWritable(in.readInt());
			second=new IntWritable(in.readInt());
			third=new IntWritable(in.readInt());
		}
		
		public void write(DataOutput out)throws IOException
		{
			out.writeInt(first.get());
			out.writeInt(second.get());
			out.writeInt(third.get());
		}
		@Override
		public int compareTo(MyPairWritable o)
		{
			if(this.first!=o.getFirst())
			{
				return this.first.get()-o.getFirst().get();
			}else if(this.second!=o.getSecond()){
				return this.second.get()-o.getSecond().get();
			}else if(this.third!=o.getThird()){
				return this.third.get()-o.getThird().get();
			}else{
				return 0;
			}
		}
		@Override
		public int hashCode()
		{
			return first.hashCode()*157+second.hashCode()*2+third.hashCode();
			
		}
		
		@Override
		public boolean equals(Object obj)
		{
			MyPairWritable temp=(MyPairWritable) obj;
			return first.equals(temp.first) && second.equals(temp.second) && third.equals(temp.third);
		}
		
		@Override
		public String toString()
		{
			return first.get()+" "+second.get()+" "+third.get();
		}
		
	}
	
	public static class FirstPartitioner extends Partitioner<MyPairWritable,IntWritable>
	{
		public int getPartition(MyPairWritable key,IntWritable value,int numPartitions)
		{
			return Math.abs(key.getFirst().get()*127)%numPartitions;
		}
	}
	
	
	public static class GroupingComparator extends WritableComparator
	{
		protected GroupingComparator()
		{
			super(MyPairWritable.class,true);
		}
		
		@Override
		public int compare(WritableComparable w1,WritableComparable w2)
		{
			MyPairWritable p1=(MyPairWritable) w1;
			MyPairWritable p2=(MyPairWritable) w2;
			int l=p1.getFirst().get();
			int r=p2.getFirst().get();
			return 1==r ? 0:(l<r ? -1:1);
		}
	}
	
	public static class KeyComparator extends WritableComparator
	{
		protected KeyComparator()
		{
			super(MyPairWritable.class,true);
		}
		
		@Override
		public int compare(WritableComparable a,WritableComparable b)
		{
			MyPairWritable p1=(MyPairWritable) a;
			MyPairWritable p2=(MyPairWritable) b;
			if(!p1.getFirst().equals(p2.getFirst()))
			{
				return p1.getFirst().get()-p2.getFirst().get();
			}else if(!p1.getSecond().equals(p2.getSecond())){
				return p1.getSecond().get()-p2.getSecond().get();
			}else{
				return p1.getThird().get()-p2.getThird().get();
			}
		}
	}
	

	public static class Map extends Mapper<LongWritable,Text,MyPairWritable,NullWritable>
	{
		MyPairWritable intkey=new MyPairWritable();
		
		protected void map(LongWritable key,Text value,Context context)throws IOException,InterruptedException
		{
			String line=value.toString();
			//String[] num=line.split(" ");
			int intone=0;
			int inttwo=0;
			int intthree=0;
			StringTokenizer tokenizer=new StringTokenizer(line);
			if(tokenizer.hasMoreTokens())
			{
				intone=Integer.parseInt(tokenizer.nextToken());
				if(tokenizer.hasMoreTokens())
				{
					inttwo=Integer.parseInt(tokenizer.nextToken());
					if(tokenizer.hasMoreTokens())
						intthree=Integer.parseInt(tokenizer.nextToken());
					IntWritable one=new IntWritable(intone);
					IntWritable two=new IntWritable(inttwo);
					IntWritable three=new IntWritable(intthree);
					
					intkey.set(one,two,three);
					context.write(intkey, NullWritable.get());
				}
			}
			
		}
	}
	
	public static class Reduce extends Reducer<MyPairWritable,NullWritable,MyPairWritable,NullWritable>
	{
		//Text left=new Text();
		//Text SEPARATOR=new Text("===================================");
		@Override
		protected void reduce(MyPairWritable key,Iterable<NullWritable> values,Context context)throws IOException,InterruptedException
		{
			context.write(key, NullWritable.get());
		}
	}
	
	public static void main(String[] args)throws IOException,InterruptedException,ClassNotFoundException
	{
		Configuration conf=new Configuration();
		String[] otherArgs=new GenericOptionsParser(conf,args).getRemainingArgs();
		if(otherArgs.length<2)
		{
			System.err.println("Usage:secondarySort <in> [<in>...]<out>");
			System.exit(2);
		}
		Job job=new Job(conf,"secondarySort");
		job.setJarByClass(secondarySort.class);
		
		job.setMapperClass(Map.class);
		job.setReducerClass(Reduce.class);
		
		job.setPartitionerClass(FirstPartitioner.class);
		job.setSortComparatorClass(KeyComparator.class);
		job.setGroupingComparatorClass(GroupingComparator.class);
		//GroupingComparatorClass  this line will affect the 1 is in or not in.
		//job.setMapOutputKeyClass(MyPairWritable.class);
		//job.setMapOutputValueClass(NullWritable.class);
		
		
		
		job.setOutputKeyClass(MyPairWritable.class);
		job.setOutputValueClass(NullWritable.class);
		
		//job.setInputFormatClass(TextInputFormat.class);
		//job.setOutputFormatClass(TextOutputFormat.class);
		
		FileInputFormat.addInputPath(job, new Path(otherArgs[0]));
		FileOutputFormat.setOutputPath(job, new Path(otherArgs[1]));
		
		System.exit(job.waitForCompletion(true)?0:1);
	}
}
