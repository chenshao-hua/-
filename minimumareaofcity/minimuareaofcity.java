/*
* 有一个城市需要修建,给你n个民居的坐标X,Y,把这么多居民全部都包进城市,城市所需的最小面积.
* 注意:城市为平行于坐标轴的正方形面积.
* 输入描述:第一行为n,表示居民数目(2<=n<=1000)
* 输出描述:城市所需最小面积
*
* Example 1:
* Input:N=2,(0,0),(2,2)
* Output:4
*
* Example 2:
* Input:N=2,(0,0),(0,3)
* Output:9
*/
package minimumareaofcity;

import java.util.Arrays;
import java.util.Scanner;

public class minimuareaofcity {
    public static void main(String[] args){
        buildCity();
    }

    private static void buildCity(){
        Scanner scanner=new Scanner(System.in);
        int n=scanner.nextInt();
        long[] arrx=new long[n];
        long[] arry=new long[n];
        for (int i=0;i<n;i++){
            long x=scanner.nextLong();
            long y=scanner.nextLong();
            arrx[i]=x;
            arry[i]=y;
        }
        Arrays.sort(arrx);
        long x=arrx[n-1]-arrx[0];
        Arrays.sort(arry);
        long y=arry[n-1]-arrx[0];
        long square;
        if(x>y){
            square=x*x;
        }else{
            square=y*y;
        }
        System.out.println(square);
    }
}
