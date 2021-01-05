/*
* Return the index of the first occurrence of needle in haystack,or -1 if needle is not part
of haystack.Clarification:
What should we return when needle is an empty string?This is a great question to ast during
an interview.
For the purpose of this problem,we will return 0 when needle is an empty string.This is consistent
to C'S strStr() and Java's indexOf().

* Example 1:

Input:haystack="hello",needle="ll"
Output:2
*
Example 2:
Input:haystack ="aaaaa",needle="bba"
Output: -1

* 题目解释:
* 其实这道题很容易理解,但需要注意模式串为0时,应该返回0;模式串长度大于主串长度时,应该返回-1.
* 方法1:
* 暴力破解
* 方法2:
* KMP算法
* */

public class ImplementstrStr {
    /*暴力破解*/
    public int strStr(String haystack,String needle){
        int haylen=haystack.length();
        int needlen=needle.length();
        if(haylen<needlen)
            return -1;
        if(needlen==0)
            return 0;
        /*主串*/
        for(int i=0;i<haylen-needlen+1;i++){
            int j;
            /*模式串*/
            for(j=0;j<needlen;j++){
                if(haystack.charAt(i+j)!=needle.charAt(j))
                    break;/*不符合的情况,直接跳出,主串指针后移一位*/
            }
            /*匹配成功*/
            if(j==needlen){
                return i;
            }
        }
        return -1;
    }
    /*KMP算法*/
    public  int strStr1(String haystack,String needle){
        /*两种特殊情况*/
        if(needle.length()==0)
            return 0;
        if(haystack.length()==0)
            return -1;
        /*字符char数组*/
        char[] hasyarr=haystack.toCharArray();
        char[] nearr=needle.toCharArray();

        int halen=hasyarr.length,nelen=nearr.length;
        /*返回下标*/
        return kmp(hasyarr,halen,nearr,nelen);
    }
    private int kmp(char[] hasyarr,int halen,char[] nearr,int nelen){
        /*获取next数组*/
        int[] next=next(nearr,nelen);
        int j=0;
        for(int i=0;i<halen;i++){
            /*发现不匹配的字符,然后根据next数组移动指针,移动到最大公共前后缀*/
            while(j>0&&hasyarr[i]!=nearr[j]){
                j=next[j-1]+1;
                /*超出长度时,可以直接返回不存在*/
                if(nelen-j+i>halen){
                    return -1;
                }
            }
            /*如果相同就将指针同时后移动一位*/
            if(hasyarr[i]==nearr[j]){
                j++;
            }
            /*遍历完整个模式串*/
            if(j==nelen){
                return i-nelen+1;
            }
        }
        return -1;
    }
    private int[] next(char[] needle,int len){
        /*定义next数组*/
        int[] next=new int[len];
        next[0]=-1;
        int k=-1;
        /*遍历求最长前后缀,next[k]记录子串最长公共前后缀的尾坐标,即长度*/
        for(int i=1;i<len;i++){
            /*找k+1前一个元素在next数组里的值,即next[k+1]*/
            while(k!=-1&&needle[k+1]!=needle[i]){
                k=next[k];
            }
            /*相同情况下,就是k的下一位,和i相同时,此时已经知道[0,i-1]的最长前后缀,
            * 然后k-1和i相同,最长前后缀加1*/
            if(needle[k+1]==needle[i]){
                k++;
            }
            next[i]=k;
        }
        return next;
    }

    /*BM算法*/
    public int strStr2(String haystack,String needle){
        char[] hay=haystack.toCharArray();
        char[] need=needle.toCharArray();
        int haylen=haystack.length();
        int needlen=need.length;
        return bm(hay,haylen,need,needlen);
    }
    /*用来企业坏字符串情况下移动位置*/
    private static void babChar(char[] b,int m,int[] bc){
        /*初始化*/
        for(int i=0;i<256;i++){
            bc[i]=i;
        }
        /*m代表模式串的长度,如果有两个a,则后面那个会覆盖前面那个*/
        for(int i=0;i<m;i++){
            int ascii=(int)b[i];
            bc[ascii]=i;
        }
    }
    /*用来求好后缀条件下的移动位数*/
    private  static void goodSuffix(char[] b,int m,int[] suffix,boolean[] prefix){
        for(int i=0;i<m;i++){
            suffix[i]=-1;
            prefix[i]=false;
        }
        for(int i=0;i<m-1;i++){
            int j=i;
            int k=0;
            while(j>=0&&b[j]==b[m-1-k]){
                j--;
                k++;
                suffix[k]=j+1;
            }
            if(j==-1) prefix[k]=true;
        }
    }

    public static int bm(char[] a,int n,char[] b,int m){
        int[] bc=new int[256];/*保存最右边字符的下标*/
        babChar(b,m,bc);
        int[] suffix_index=new int[m];/*用来保存各种长度好后缀的最右位置的数组*/
        boolean[] ispre=new boolean[m];/*判断是否是头部,如果是头部则true*/
        goodSuffix(b,m,suffix_index,ispre);

        int i=0;/*第一个匹配字符*/
        while(i<=n-m){
            int j;
            /*从后往前匹配,匹配失败,找出坏字符*/
            for(j=m-1;j>=0;j--){
                if(a[i+j]!=b[j])
                    break;
            }
            /*模式串遍历完毕,匹配成功*/
            if(j<0){
                return i;
            }
            /*匹配失败时*/
            /*求出坏字符规则下移动的位数,就是我们坏字符下标减最右边的下标*/
            int x=j-bc[(int)a[i+j]];
            int y=0;
            /*好后缀情况,求出好后缀情况下的移动位数,如果不含有好后缀则按照坏字符来移动*/
            if(y<m-1&&m-i-j>0){
                y=move(j,m,suffix_index,ispre);
            }
            /*移动*/
            i=i+Math.max(x,y);
        }
        return -1;
    }
    /*j代表坏字符的下标*/
    private  static int move(int j,int m,int[] suffix_index,boolean[] ispre){
        /*好后缀长度*/
        int k=m-1-j;
        /*如果含有长度为k的好后缀,返回移动位数*/
        if(suffix_index[k]!=-1)
            return j-suffix_index[k]+1;
        /*找头部为好后缀子串的最大长度,从长度最大的子串开始*/
        for(int r=j+2;r<=m-1;r++){
            /*如果是头部*/
            if(ispre[m-r]==true){
                return r;
            }
        }
        /*如果没有发现好后缀匹配的串,或者头部为好后缀子串,则移动到m位,也就是匹配串的长度*/
        return m;
    }

    public static void main(String[] args){
        String haystack="hello",needle="ll";
        ImplementstrStr str=new ImplementstrStr();
        System.out.println(str.strStr2(haystack,needle));
    }
}
