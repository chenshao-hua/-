/**
 * 题目描述:
 * 在字符串str中找出第一个只出现一次的字符.如果不存在,则返回单空格.
 *
 * Example 1:
 * Input:str="aacde",
 * Output:c
 *
 * Example 2:
 * Input:str="~@#aa$@#"
 * Output:$
 *
 * Example 3:
 * Input:str="~@#aa~@#"
 * Output:''
 *
 * 解题思路:
 * ASCII一般是128个字符,若算上符号则有256个字符.
 * 方法1:
 * 利用数组+hashmap(无序)进行存储,key值为字符元素,value值Boolean(其实也也可以利用integer进行计数).如果出
 * 现一次则为true,多次则为false.
 * 方法2:
 * 直接使用有序hashmap.
 * 方法3:
 * 直接利用数组.相对来说,效率比hash算法快,因为hash存在扩容等问题.
 */

package firstindependentcharacter;

import javax.security.auth.callback.CallbackHandler;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;

public class Solution {
    public static void main(String[] args){
        String str="#@#aa$@#";
        System.out.println(new Solution().firstCharOne(str));
        System.out.println(new Solution().firstCharTwo(str));
    }

    /**
     * hashmap无序
     * @param str
     * @return
     */
    public char firstCharOne(String str){
        //定义无序hashMap,不能保障默认顺序
        Map<Character,Boolean> map=new HashMap<>();
        char[] chars=str.toCharArray();
        for(char c:chars) {
            if (map.containsKey(c)) {
                map.put(c, false);//多次
            } else {
                map.put(c, true);//一次
            }
        }
        //此if条件可以直接使用
        //map.put(c,!map.containsKey(c));
        for(char c:chars){
            if(map.get(c))
                return c;
        }
        //不存在这样的字符
        return ' ';
    }

    /**
     * 有序hashmap
     * @param str
     * @return
     */
    public char firstCharTwo(String str){
        //定义有序hashmap,默认为插入顺序
        Map<Character,Boolean> map=new LinkedHashMap<>();
        for(int i=0;i<str.length();++i){
            map.put(str.charAt(i),!map.containsKey(str.charAt(i)));
        }
        for(Map.Entry<Character,Boolean> entry:map.entrySet()){
            if(entry.getValue())
                return entry.getKey();
        }
        return ' ';
    }

    /**
     * 数组字典
     * @param str
     * @return
     */
    public char firstCharThree(String str){
        //定义数组字典,一般Ascii有7位,则128个字符,最大256个字符
        int[] dict=new int[256];
        char[] chars=str.toCharArray();
        for(char c:chars){
            dict[c]++;
        }
        for(char c:chars){
            if(dict[c]==1)
                return c;
        }
        return ' ';
    }
}