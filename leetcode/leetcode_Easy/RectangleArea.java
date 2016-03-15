package leetcode_Easy;

public class RectangleArea {

	 public static int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		 int Sa=0;
		 int Sb=0;
		 int Sc=0;
		 Sa=Math.abs(H-F)*Math.abs(G-E);
		 Sb=Math.abs(A-C)*Math.abs(B-D);
		 
		 int Ac=Math.max(A,E);
		 int Bc=Math.max(B, F);
		 int Cc=Math.min(C,G);
		 int Dc=Math.min(D, H);
		 
		 Sc=(Dc-Bc)*(Cc-Ac);
		 
		 if(Dc<=Bc || Cc<=Ac) return Sa+Sb;
		 return Sa+Sb-Sc;
	 }
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		computeArea(-1500000001,0,-1500000000,1,1500000000,0,1500000001,1);
	}

}
