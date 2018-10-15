public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int max = 0;
		int current = 0;
		StringBuilder sb = new StringBuilder();
		for(int i=0;i<s.length();i++){
			int index = sb.indexOf(String.valueOf(s.charAt(i)));
			if(index==-1){
				sb.append(s.charAt(i));
				current++;
			}else{
				if(max < current){
					max=current;
				}
				sb.delete(0, index+1);
				sb.append(s.charAt(i));
				current=current-index;
			}
		}
		if(current>max)
			max=current;
		return max;
    }
}