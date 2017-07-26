package org.trier;

public class MaxSub {
	public String maxSub(String s) {
		int length=s.length();
		int index=0;
		int max=0;
		int[][] map=new int[length+1][length+1];
		for(int i=0;i<=length;i++){
			map[0][i]=0;
			map[i][0]=0;
		}
		for(int i=0;i<length;i++){
			for(int j=0;j<length;j++){
				if(s.charAt(i)==s.charAt(length-1-j)){
					map[i+1][j+1]=map[i][j]+1;
				}else{
					map[i+1][j+1]=0;
				}
				if(map[i+1][j+1]>max){
					max=map[i+1][j+1];
					index=i+1;
				}
			}
		}
		return s.substring(index-max, index);
    }
}
