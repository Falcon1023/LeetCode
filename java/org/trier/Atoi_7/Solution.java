package org.trier.Atoi_7;

/**
 * Created by trier on 2017/5/6.
 */
public class Solution {
    public int myAtoi(String str) {
        int index=0;
        int length=str.length();
        int sign=1;
        int sum=0;
        if(length==0)
            return sum;
        while (str.charAt(index)==' '&&index<length)
            index++;
        if (str.charAt(index)=='-'||str.charAt(index)=='+'){
            sign=str.charAt(index)=='-'?-1:1;
            index++;
        }
        while (index<length){
            int tmp=str.charAt(index)-'0';
            if(tmp<0||tmp>9)
                break;
            if(Integer.MAX_VALUE/10<sum||Integer.MAX_VALUE/10==sum&&Integer.MAX_VALUE%10<tmp)
                return sign==1?Integer.MAX_VALUE:Integer.MIN_VALUE;
            sum=sum*10+tmp;
            index++;
        }
        return sum*sign;
    }
}
