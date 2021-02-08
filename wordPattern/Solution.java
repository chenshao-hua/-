package wordPattern;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solution {
    public static void main(String[] args){
//        String pattern="abba",str="dog cat cat fish";
        String pattern="abc",str="b c a";
        System.out.println(new Solution().wordPatternOne(pattern,str));
    }
    public boolean wordPatternOne(String pattern,String str){
        List<String> s=new ArrayList<>();
        int pos=0;
        for(int i=0;i<str.length();++i){
            if(str.charAt(i)==' '){
                s.add(str.substring(pos,i));
                pos=i+1;
            }
        }
        s.add(str.substring(pos,str.length()));
//        String[] temp=str.split(" ");//或者直接利用自带的函数进行分割
        if(s.size()!=pattern.length()) return false;
        HashMap<String,String> map=new HashMap<>();
        for(int i=0;i<s.size();++i){
            String s1=new String(String.valueOf(pattern.charAt(i)));
            String s2=new String(s.get(i).toString());
            if(!map.containsKey(s1)){
                if(map.containsValue(s2))
                    return false;
                map.put(s1,s2);
            }else{
                String e=new String(map.get(s1));
                if(!e.equals(s2))
                    return false;
            }
        }
        return true;
    }
    public boolean wordPatternTwo(String pattern,String str){
        String[] s=str.split(" ");
        if(pattern.length()!=s.length)
            return false;
        Map map=new HashMap<>();
        for(Integer i=0;i<pattern.length();++i){
            if(map.put(pattern.charAt(i),i)!=map.put(s[i],i)){
                return false;
            }
        }
        return true;
    }
}
