/**
 * 圈地运动,就是用很多木棍摆在地上组成一个面积大于0的多边形~小明喜欢圈地运动,于是他需要去小红店里面买一些木棍,
 * 期望圈出一地来.小红想挑战一下小明,所以给小明设置了一些障碍.障碍分别是:
 * 1.如果小明要买第i块木棍的话,他就必须把前I块木棍都买下来.
 * 2.买了的木棍都必须用在圈地运行中.
 * 那么请问小明最少买多少根木棍,才能使得木棍围成的图形是个面积大于0多边形呢？
 *
 * 输入描述:第一行一个数n,表示木棍个数.
 * 第二行n个数,第i个数表示第i个木棍的长度ai.
 * 1<=n<=10000
 * 1<=ai<=10000
 * 输出描述:输出一个数,表示最少需要的木棍个数,如果无解则输出为-1.
 *
 * 解题思路:
 * 至少需要3根木棍才能构成封闭的图形.而且从三角形的思路出发,任意两边之和必须大于第三边.
 * 则多边形前n个之和不包含最大值大于其最大值.
 */

package movementOfEnclosure;

import java.util.Scanner;

public class Solution {
    public int enclosureMovement(){
        Scanner in=new Scanner(System.in);
        int n=in.nextInt();
        int[] nums=new int[n];
        for(int i=0;i<n;i++){
            nums[i]=in.nextInt();
        }
        if(nums.length<3) return -1;

        //条件:n-1边的和必须大于最长边,就能组成封闭图形
        int sum=0,max=Integer.MIN_VALUE;//sum表示前n个数之和,max前n个数中的最大值
        int ans=-1;//标记是否能构成最小面积
        for(int i=0;i<nums.length;i++){
            sum+=nums[i];
            max=max>nums[i]?max:nums[i];
            //如果i大于1(如果不大于1,说明只有两条边,无论如何也构不成),并且sum-max>max,即
            //前n个数中不含max值之和大于max,sum-max>max,则存在,下标从0开始,则需要进行i+1
            if(i>1&&sum>2*max){
                ans=i+1;//存在,则跳出
                break;
            }
        }
        return ans;
    }

    public static void main(String[] args){
        Solution so=new Solution();
        System.out.println(so.enclosureMovement());
    }
}
