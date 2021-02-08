/**
 * 给你一个整数数组nums,请你找出数组中乘积最大的连续子数组.
 *
 * Example 1:
 * Input:[-2,0,-1]
 * Output:0
 *
 * Example 2:
 * Input:[2,4,-2,4]
 * Output:8
 *
 * 解题思路:
 * 方法1:
 * 暴力破解法,双重遍历;
 * 方法2:
 * 动态规划,只需要遍历一次数组.每次枚举记录最大值和最小值(有可能反转成最大值).这样每次比较当前值、当前值与上一次
 * 的最大值乘积、当前值与上一次的最小值乘积,得到最大值;比较当前值、当前值与上一次的最大值乘积、当前值与上一次的最
 * 小值乘积,得到最小值.最后比较当前最大值和上次记录的最大值.
 */

package maximumproductofcontiguousSubarrays;

public class Solution {
    public int maximumProduct(int[] nums){
        int ans=nums[0],max=nums[0],min=nums[0];
        for(int i=1;i<nums.length;i++){
            int tmp1=max,tmp2=min;
            max=Math.max(nums[i],Math.max(tmp1*nums[i],tmp2*nums[i]));
            min=Math.min(nums[i],Math.min(tmp1*nums[i],tmp2*nums[i]));
            ans=Math.max(ans,max);
        }
        return ans;
    }
    public int maximumProduct1(int[] nums){
        int ans=nums[0];
        for(int i=0;i<nums.length;i++){
            int board=1,dp=Integer.MIN_VALUE;
            for(int j=i;j<nums.length;j++){
                board*=nums[j];
                dp=Math.max(dp,board);
            }
            ans=Math.max(dp,ans);
        }
        return ans;
    }
    public int maximumProduct2(int[] nums){
        int ans=Integer.MIN_VALUE,dpMax=1,dpMin=1;
        for(int i=0;i<nums.length;i++){
            if(nums[i]<0){
                int tmp=dpMax;
                dpMax=dpMin;
                dpMin=tmp;
                System.out.printf("%d,%d,%d\n",nums[i],dpMax,dpMin);
            }
            dpMax=Math.max(dpMax*nums[i],nums[i]);
            dpMin=Math.min(dpMin*nums[i],nums[i]);
            System.out.printf("%d,%d,%d\n",nums[i],dpMax,dpMin);

            ans=Math.max(ans,dpMax);
        }
        return ans;
    }
    public static void main(String[] args) {
        int[] nums={2,4,-2,4};
        System.out.println(new Solution().maximumProduct2(nums));
    }
}
