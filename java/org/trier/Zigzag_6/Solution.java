package org.trier.Zigzag_6;

/**
 * Created by trier on 2017/5/6.
 */
public class Solution {
    public String convert(String s, int numRows) {
        int length=s.length();
        StringBuffer[] stb=new StringBuffer[numRows];
        for(int i=0;i<numRows;i++)
            stb[i]=new StringBuffer();
        int count=0;
        while(count<length){
            for(int row=0;row<numRows&&count<length;row++)
                stb[row].append(s.charAt(count++));
            for(int row=numRows-2;row>0&&count<length;row--)
                stb[row].append(s.charAt(count++));
        }
        for (int i=1;i<numRows;i++)
            stb[0].append(stb[i]);
        return stb[0].toString();
    }
}
