/**
 * 输入一个字符串,打印出该字符串中字符的所有排序的字符串数组.(排序不允许重复)
 * Example 1:
 * Input:str="ab"
 * Output:["ab","ba"]
 *
 * Example 2:
 * Input:str="abb"
 * Output:["abb","bab","bba"]
 *
 * Example 3:
 * Input:str="abc"
 * Output:["abc","acb","bac","bca","cab","cba"]
 *
 * 解题思路:
 *
 * 回溯思想+DFS
 */
package arrayOfStrings;

import java.util.*;

public class Solution {
    public String[] probabilityOfStringsOne(String str){
        Set<String> ans=new HashSet<>();
        StringBuilder temp=new StringBuilder(str);//String不能改变
        DFS(temp,0,str.length(),ans);
        String[] res=new String[ans.size()];
        return ans.toArray(res);
    }

    private void DFS(StringBuilder temp,int start,int end,Set ans){
        if(start==end){
            ans.add(temp.toString());
            return;
        }
        for(int i=start;i<end;i++){
            char x=temp.charAt(i),y=temp.charAt(start);//交换两个字符
            temp.setCharAt(i,y);
            temp.setCharAt(start,x);
            DFS(temp,start+1,end,ans);
            temp.setCharAt(i,x);
            temp.setCharAt(start,y);//恢复
        }
    }
    //方法二
    //存放返回排序字符串
    private static List<String> list=new ArrayList<>();
    public String[] probabilityOfStringsTwo(String str){
        char[] chars=str.toCharArray();
        helper(chars,0);
        return list.toArray(new String[0]);//new String[0]转换成String[]类型的
    }
    private void helper(char[] chars,int index){
        if(index==chars.length){
            String str=new String(chars);
            list.add(str);
        }
        for(int i=index;i<chars.length;++i){
            //进行减枝
            if(i==index){//同一个下标,无需进行交换
                helper(chars,index+1);
                continue;
            }
            //这个k是用来标记
            int k;
            for(k=i-1;k>=index;--k){//剔除重复,数组比set更快
                if(chars[k]==chars[i]) break;
            }
            if(k!=index-1) continue;
            swap(chars,i,index);
            helper(chars,index+1);
            swap(chars,i,index);
        }
    }
    private void swap(char[] chars,int left,int right){
        char tmp=chars[left];
        chars[left]=chars[right];
        chars[right]=tmp;
    }
    /**
     * 字符串数组
     * @param args
     */
    public static void main(String[] args){
        String str="abc";
        String[] ans=new Solution().probabilityOfStringsTwo(str);
        //打印字符串数组
//        for(String a:ans) {
//            System.out.print(a+" ");
//        }
        Arrays.asList(ans).stream().forEach((x)->{
            System.out.print(x+" ");
        });
    }
}
