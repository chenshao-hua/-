package countBits;/*
* 动态规划+设置最后位
* 从右到左设置第一个为1的位置,即状态方程为:p(x)=P(x&(x-1))+1,其中x&(x-1)是将最低位第一个为1的清零.
* */

public class countBits {
    public int[] countBit(int num){
        int[] res=new int[num+1];
        res[0]=0;
        for(int i=1;i<=num;++i){
            res[i]=res[i&(i-1)]+1;
        }
        return res;
    }

    public static void main(String[] args){
        int[] ans=new countBits().countBit(5);
        for(int i:ans){
            System.out.printf("%d ",i);
        }
    }
}
