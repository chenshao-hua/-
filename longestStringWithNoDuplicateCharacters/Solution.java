/**
 * 给定一个字符串,请你找出其中不含有重复字符的最长子串的长度.
 *
 * 输入:"abcabcbb"
 * 输出:3
 * 解释:因为无重复字符的最长子串是"abc",所以
 * 其长度为3.
 *
 * 输入:"bbbbb"
 * 输出:1
 * 解释:因为无重复字符的最长子串是"b",所以
 * 其长度为1.
 *
 * 输入:"pwwkew"
 * 输出:3
 * 解释:因为无重复字符的最长子串是"wke",所以
 * 其长度为3.请注意,你的答案必须是子串的长度,"pwk"是一个子序列,不是子串.
 *
 * 解题思路:
 *方法1:
 * 暴力破解法.
 * 利用双层进行枚举,并且记录当前最长的字符串.这样时间复杂度为O(n^2).
 *
 * 方法2:
 * 滑动窗口法.时间复杂度为O(n).什么是滑动窗口呢?其实就是一个队列,比如上面的例子中"abcabcbb",进入队列这
 * 个窗口为"abc"满足题目条件,当再进入a,队列变成了"abca",这个时候不再满足条件.因此,需要移动这个队列.这时
 * 候只需要把队列左边的元素移除出去,直到满足题目的要求.以此类推,一直维持这样的队列,找出队列中出现最长的字符
 * 串的时候,求出解!
 *
 * 此问题的最优方案.
 */
package longestStringWithNoDuplicateCharacters;

import java.util.HashMap;
import java.util.Map;

public class Solution {
    public static void main(String[] args) {
        String s = "abcabcebbfetsyastretetyui";
        long startTimeOne=System.currentTimeMillis();
        System.out.println(new Solution().lengthOfLongestSubStringOne(s));
        long endTimeOne=System.currentTimeMillis();
        System.out.println("执行时间: "+(double)(endTimeOne-startTimeOne)/1000+"s");

        long startTimeTwo=System.currentTimeMillis();
        System.out.println(new Solution().lengthOfLongestSubStringTwo(s));
        long endTimeTwo=System.currentTimeMillis();
        System.out.println("执行时间: "+(double)(endTimeTwo-startTimeTwo)/1000+"s");
    }

    /**
     * 暴力破解法
     *
     * @param s
     * @return
     */
    public int lengthOfLongestSubStringOne(String s) {
        int ans = 0;
        StringBuilder str = new StringBuilder();
        for (int i = 0; i < s.length(); ++i) {
            str.append(s.charAt(i));
            for (int j = i + 1; j < s.length(); ++j) {
                if (str.indexOf(String.valueOf(s.charAt(j))) == -1) {//判断是否含有该字符,此时不含有
                    str.append(s.charAt(j));
                }else{
                    break;
                }
            }
            ans = Math.max(ans, str.length());//这步可以放到if条件语句,直接用j-i进行统计最大长度即可.
            str.delete(0, str.length());
        }
        return ans;
    }

    /**
     * 滑动窗口法
     * @param s
     * @return
     */
    public int lengthOfLongestSubStringTwo(String s) {
        if(s.isEmpty()) return 0;
        Map<Character,Integer> map=new HashMap<Character,Integer>();
        int res=0,left=0;
        for(int i=0;i<s.length();++i){
            if(map.containsKey(s.charAt(i))){//判断是否包含该字符,若存在,则从该字符向左进行移除.
                left=Math.max(left,map.get(s.charAt(i))+1);//滑动窗口向左移除字符串.
            }
            map.put(s.charAt(i),i);
            res=Math.max(res,i-left+1);
        }
        return res;
    }
}