package org.trier;

public class LongestPalindrome {
	public String longestPalindrome(String s) {
		int length=s.length();
		int start=0;
		int end=1;
		Boolean[][] map=new Boolean[length][length];
		for(int i=0;i<length;i++)
			for(int j=0;j<=i;j++)
				map[i][j]=true;
		for(int j=1;j<length;j++){
			for(int i=0;i<j;i++){
				if(s.charAt(i)==s.charAt(j)){
					map[i][j]=map[i+1][j-1];
					if((map[i][j]==true)&&(j-i+1>end-start)){
						start=i;
						end=j+1;
					}
				}
				else
					map[i][j]=false;
			}
		}
		return s.substring(start, end);
    }
}
