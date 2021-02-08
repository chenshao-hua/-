package PancakeSorting;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
    public static void main(String[] args){
        int[] arr={3,4,2,1};
        System.out.println(new Solution().pancakeSort(arr));
    }

    /**
     * 数学方法
     * @param arr
     * @return
     */
    public List<Integer> pancakeSort(int[] arr){
        List<Integer> ans=new ArrayList<>();
        int n=arr.length;
        Integer[] board=new Integer[n];
        for(int i=0;i<n;++i){
            board[i]=i+1;
        }
        Arrays.sort(board,(i,j)->arr[j-1]-arr[i-1]);
        for(int i:board){
            for(int a:ans){
                if(i<=a){
                    i=a-i+1;
                }
            }
            ans.add(i);
            ans.add(n--);
        }
        return ans;
    }
}
