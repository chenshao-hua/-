public class longestcommonsubsequence{
    public static int longestsubsequence(String text1,String text2){
        int m=text1.length(),n=text2.length();
        if(text1==null||m<=0||text2==null||n<=0){
            return 0;
        }
        int [][]dp=new int[m+1][n+1];
        /*若当前的字符相同,则前一个状态+1;若当前字符不同,则前一个状态的最大值*/
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1.charAt(i-1)==text2.charAt(j-1)){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=Math.max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }

    public static void main(String[] args){
        String text1="abc";
        String text2="ace";
        System.out.println(longestsubsequence(text1,text2));
    }
}
