/**
 * 假设你是一位顺风车司机,车上最初由capacity个空座位可以用来载客.由于道路的限制,车只能向一个方向行驶(0-1000).
 * 行程计划表用trips[][],其中trips[i]=[passengers,start_location,end_location].包含了你的第i此行
 * 程信息:
 *分别表示
 * (1)必须接送的乘客数量;
 * (2)乘客的上车地点;
 * (3)以及乘客的下车地点;
 * 请你根据给出的行程计划表和车子的座位数,来判断你的车是否可以顺利完成接送所有乘客的任务(当且仅但你可以在所有给
 * 定的行程中接送完所有乘客时,返回true,否则返回false).
 * (注意:乘客都是好乘客,先下后上)
 * 举例:
 * trips=[[2,1,5],[3,3,7]],capacity=4
 * 输出:false
 * trips=[[3,2,7],[3,7,9],[8,3,9]],capacity=11
 * 输出:true
 *
 * 解题思路:
 * 方法1:
 * 统计法
 * 这道题比较容量理解,只要保证重叠路段上区间内乘客的数量小于给定的数量即可.而且给出的数组个数不大于1000.
 * 可以设置一个数组temp[2][1000],分别存储上车地点和下车地点对于区间内的乘客人数.当上车时候,进行
 * 加上此地点对于乘客人数操作.当下车时候,进行减去此地点对于乘客人数.
 *
 * 方法2:
 * 哈希算法.利用两个hashmap分别存储上车点和下车点,以及对于的乘客人数.
 */
package carPooling;

import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;

public class Solution {
    /**
     * 判断司机能否完成任务,trips[][0]为上车人数,trips[][1]为上车地点,trips[][2]为下车地点
     * @param trips
     * @param capacity
     * @return
     */
    public boolean carPooling(int[][] trips,int capacity){
        boolean flag=true;
//        Arrays.sort(trips, new Comparator<int[]>() {
//            @Override
//            public int compare(int[] o1, int[] o2) {
//                if(o1[1]==o2[1]){
//                    return o1[2]-o2[2];
//                }else{
//                    return o1[1]-o2[1];
//                }
//            }
//        });
//        Arrays.sort(trips,(int[] x,int[] y)->{
//            if(x[1]==y[1])
//                return x[2]-y[2];
//            return x[1]-y[1];
//        });
        int[][] temp=new int[2][1000];
        for(int[] t:trips){
            temp[0][t[1]]=t[0];//上车地点
            temp[1][t[2]]=t[0];//下车地点
        }

        int sum=0;
        for(int i=0;i<temp[0].length;++i){
            sum=sum-temp[1][i];//此地点下车乘客
            sum=sum+temp[0][i];//此地点上车乘客
            if(sum>capacity){
                flag=false;
                break;
            }
        }
        return flag;
    }

    public boolean carPoolingOne(int[][] trips,int capacity){
        //统计每个点车上人数,数学统计法.
        int[] current=new int[1001];
        for(int[] trip:trips){
            current[trip[1]]+=trip[0];//上车
            current[trip[2]]-=trip[0];//下车
        }
        if(current[0]>capacity) return false;
        for(int i=1;i<1001;i++){
            current[i]+=current[i-1];
            if(current[i]>capacity){
                return false;
            }
        }
        return true;//遍历完所有的不存在大于capacity的值
    }
    public boolean carPoolTwo(int[][] trips,int capacity){
        //上车点,上车人数
        Map<Integer,Integer> upPerson=new HashMap<>();
        Map<Integer,Integer> downPerson=new HashMap<>();
        //left-right:整个区间
        int left=trips[0][1],right=trips[0][2];
        for(int[] t:trips){
            //遇到上车点或下车点相同,把它们的人数相加即可
            upPerson.put(t[1],upPerson.getOrDefault(t[1],0)+t[0]);//getOrDefault若存在,则在原来的数上进行相加.
            downPerson.put(t[2],downPerson.getOrDefault(t[2],0)+t[0]);
            left=Math.min(left,t[1]);
            right=Math.min(right,t[2]);
        }
        int cur=0;//目前上车人数
        for(int i=left;i<=right;++i){
            if(upPerson.containsKey(i))
                cur+=upPerson.get(i);
            if(downPerson.containsKey(i))
                cur-=downPerson.get(i);
            if(cur>capacity)
                return false;
        }
        return true;
    }
    public static void main(String[] args) {
        int[][] trips={{3,2,7},{3,7,9},{8,3,9}};
        int capacity=11;
        System.out.println(new Solution().carPooling(trips,capacity));
    }
}
