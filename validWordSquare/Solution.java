package validWordSquare;

import java.util.*;

public class Solution {
    public boolean validWordSquare(List<String> words){
        if(words.isEmpty()) return false;
        if(words.size()!=words.get(0).length()) return false;
        for(int i=0;i<words.size();++i){
            for(int j=0;j<words.get(i).length();++j){
                if(j>words.size()||i>=words.get(j).length()||words.get(i).charAt(j)!=
                words.get(j).charAt(i))
                    return false;
            }
        }
        return true;
    }

    public static void main(String[] args){
        String[] w={"abcd","bnrt","crmy","dtye"};
        List<String> words=new ArrayList<>();
        for(String s:w){
            words.add(s);
        }
        //List<String> words=Arrays.asList(w);
        System.out.println(new Solution().validWordSquare(words));
    }
}
