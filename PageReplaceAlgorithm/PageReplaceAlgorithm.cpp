/*
1.最佳(Optimal)置换算法
1.1算法原理
   其选择淘汰的页面将是以后永不使用的,或许是在最长时间内不再被访问的页面.采用最佳置换算法
通常可以保证获得最低的缺页率.但由于人们目前还无法预知,一个进程在内存的若干个界面中,哪一个
页面是未来最长时间内不再被访问的,因而该算法是无法实现的,但可以利用它来评价其他算法.例如:
   假定系统为某进程分配了三个物理块,并考虑有以下页面号引用串:
   7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1
   进程在运行时,先将7,0,1三个页面依次装入内存.进程要访问页面2时,产生缺页中断,根据最佳置换算法,
选择第18次访问才需调入的页面7予以淘汰.然后,访问页面0时,因为已在内存中所以不必产生缺页中断.访
问页面3时,又根据最佳置换算法将页面1淘汰....依次类推.

2.先进先出(FIFO)置换算法
2.1算法原理
   是最简单的页面置换算法.这种算法的基本思想是:当需要淘汰一个页面时候,总是选择驻留主存时间最
长的页面进行淘汰,即先进入主存的页面先淘汰.其理由是:最早调入主存的页面不再被使用的可能性最大.
   根据上面的例子,采用FIFO算法进行页面置换.进程访问页面2时,把最早进入内存的页面7换出.然后访问
页面3时,再把2,0,1中最新页进入内存的页换出.

3.最近最久未使用(LRU)算法
3.1算法原理
   这种算法的基本思想是:利用局部性原理,根据一个作业在执行过程中过去的页面访问历史来推测未来的
行为.它认为过去一段时间里不曾被访问的页面,在最近的将来可能也不会再被访问.因此,这种算法的实质
是:当需要淘汰一个页面时,总是选择在最近的一段时间内最久不用的页面予以淘汰.
   根据上面的例子采用LRU算法进行页面置换.进程第一次对页面2访问时,将最近最久未被访问的页面7置
换出去.然后访问页面3时,将最近最久未使用的页面1换出.

*/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class PageReplaceAlgorithm{
public:
	void Optimal(vector<int> PageOrder,vector<vector<int>>& Simulate,int& PageNum,int& LackNum,int m,int n){
		vector<bool> found(n,false);/*记录页面中是否存在*/
		vector<int> lump; //物理块
        for(auto i=0;i<n;found[PageOrder[i]]=true,i++){
            /*物理块中不存在*/
			if(!found[PageOrder[i]]){
				if(lump.size()<m){		
					/*物理块未满*/
					lump.push_back(PageOrder[i]);
				}else{
					/*物理块满需要置换*/
					int temp,max=0;
					for(auto j=0;j<lump.size();j++){
						int count=i;
						for(;count<n+1;count++){
							if(PageOrder[count]==lump[j])
							   break;
						}
						if(count>max){
							max=count;
							temp=j;/*记录当前最远页面序号*/
						}
					}					
					found[lump[temp]]=false;
					lump[temp]=PageOrder[i];
				}
				for(auto j=0;j<lump.size();j++)
				   Simulate[i].push_back(lump[j]);
				LackNum++;/*访问页面失败*/
            }else{
				PageNum++;/*访问页面成功*/
			}
		} 
	}

	void  FIFO(vector<int> PageOredr,vector<vector<int>>& Simulate,int& PageNum,int& LackNum,int m,int n){
		vector<bool> found(n,false);
		vector<int> lump;
		queue<int> buffer;/*用来记录先后顺序*/
		for(auto i=0;i<n;found[PageOredr[i]]=true,i++){
			if(!found[PageOredr[i]]){
				if(lump.size()<m){
					lump.push_back(PageOredr[i]);
					buffer.push(PageOredr[i]);
				}else{
					for(auto j=0;j<lump.size();j++){
						if(lump[j]==buffer.front()){
							found[lump[j]]=false;
							lump[j]=PageOredr[i];/*置换页面*/
							buffer.push(PageOredr[i]);
							buffer.pop();
							break;
						}
					}
				}
				for(auto k=0;k<lump.size();k++)
				    Simulate[i].push_back(lump[k]);
				LackNum++;
			}else{
				PageNum++;
			}
		}
	}

	void LRU(vector<int> PageOrder,vector<vector<int>>& Simulate,int& PageNum,int& LackNum,int m,int n){
		vector<int> count(n,0);/*记录页面存在时间*/
		vector<bool> found(n,false);
		vector<int> lump;

		for(auto i=0;i<PageOrder.size();count[PageOrder[i]]=i,found[PageOrder[i]]=true,i++){
			/*判断是否访问过*/
			if(!found[PageOrder[i]]){
				if(lump.size()<m){
					/*缓冲区未满*/
					lump.push_back(PageOrder[i]);
				}else{
					int temp,max=0;
					/*记录当前物理块中存在最长时间的元素*/
					for(auto j=0;j<lump.size();j++){
						if(i-count[lump[j]]>max){
							max=i-count[lump[j]];
							temp=j;
						}
					}
					found[lump[temp]]=false;
					lump[temp]=PageOrder[i];
				}
				for(auto k=0;k<lump.size();k++)
				    Simulate[i].push_back(lump[k]);
				LackNum++;
			}else{
				PageNum++;
			}
		}
	}
};

int main(int argc,char* argv[]){
	vector<int> PageOrder{7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
	vector<vector<int>> ans(20);
	int PageNum=0,LackNum=0;

	PageReplaceAlgorithm().Optimal(PageOrder,ans,PageNum,LackNum,3,20);
	
	for(auto& res:ans){
		cout<<"[ ";
		for(auto& i:res)
		   cout<<i<<" ";
		cout<<"]"<<endl;
	}
	cout<<PageNum<<" "<<LackNum<<endl;
	return 0;
}