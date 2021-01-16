/**
 * 有一段长度为n的绳子,你可以剪多次,每次剪下来的绳子正好是整数,求剪下来的绳子长度的最大乘积.
 * 注意:最大乘积包括最后的一段绳子.
 *
 * Example 1:
 * Input:N=5
 * Output:6(2x3)
 *
 * 解题思路:
 * 分成两段的时候可以达到最优解
 * 方法1:
 * 动态规划,
 * 状态方程:max(dp[n-i]*i,(n-i)*i
 * 状态转移方程:max(max(dp[n-i]*i,(n-i)*i),dp[i])
 */

package cutropes;

public class cuttingropes {
    public static void main(String[] args){
        int n=14;
        System.out.println(cutRopes(n));
    }

    public static int cutRopes(int n){
        if(n<2) return 0;
        int[] dp=new int[n+1];
        dp[2]=1;
        for(int i=3;i<=n;i++){
            for(int j=1;j<i;j++){
                dp[i]=Math.max(Math.max(j*dp[i-j],j*(i-j)),dp[i]);
            }
        }
        return dp[n];
    }

}
