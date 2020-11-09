/*
题目描述：
某公司中有N名员工。给定所有员工工资的清单，财务人员要按照特定的顺序排列员工的工资。
他按照工资的频次降序排列。即给定清单中所有频次较高的工资将在频次较低的工资之前出现。
如果相同数量的员工都有相同的工资，则将按照给定清单中该工资第一次出现的顺序排列。
写一个算法来帮助财务人员排列员工工资的顺序。

输入：
该函数/方法的输入包括两个参数--num，一个整数，表示员工的人数salaries，一个正整
数列表，表示N名员工的工资

输出：
返回一个正整数列表，该列表按照员工工资的频次排序

约束条件：
1<num<100000
1<salaries<1000000000
0<i<num

 
示例：
输入：
num=19
salaries=[10000,20000,40000,30000,30000,30000,40000,20000,50000,
50000,50000,50000,60000,60000,60000,70000,80000,90000,100000]

输出：
[50000,50000,50000,50000,30000,30000,30000,60000,60000,
60000,20000,20000,40000,40000,10000,70000,80000,90000,100000]
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	void coutFrequency(vector<int>& salary){
		int temp_frequency,temp_salary;
		vector<int> frequency(salary.size(),0);//频次

		//对salary进行统计
		for(int i=0;i<salary.size();i++){
			for(int j=0;j<salary.size();j++){
				if(salary[i]==salary[j])
				   frequency[i]++;
			}
		}

		//对频次进行插入排序，并且保持第一次出现的顺序
		for(int i=1;i<salary.size();i++){
			temp_frequency=frequency[i];
			temp_salary=salary[i];
			int j=i-1;
			while(j>=0&&temp_frequency>frequency[j]){
				frequency[j+1]=frequency[j];
				salary[j+1]=salary[j];   //交换数据
				j--;
			}
			frequency[j+1]=temp_frequency;
			salary[j+1]=temp_salary;
		}

		//再次进行排序，搜索相同的元素是否紧挨着
		for(int i=1;i<salary.size();i++){
			temp_salary=salary[i];
			int j=i-1,k=i-1;
			while(k>=0){
				//判断前半部分序列是否存在相同的数据
				if(temp_salary==salary[k]){
					while(j>=0&&temp_salary!=salary[j]){
						salary[j+1]=salary[j];//插入到相同数据的后面
						j--;
					}
					salary[j+1]=temp_salary;
					break; 
				}
				k--;
			}
		}
	}
};

int main(int argc,char* argv[]){
    vector<int> salaries={1,2,4,3,3,3,4,2,5,5,5,5,6,6,6,7,8,9,10};
	Solution solu;
	solu.coutFrequency(salaries);
	for(auto& salary:salaries)
	     cout<<salary<<" ";
	cout<<endl;
	return 0;
}