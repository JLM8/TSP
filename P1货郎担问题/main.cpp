#include<iostream>
#include<fstream>
using namespace std;

int minDist = 9999;//预设最小路径

void swap(int & a, int & b) {//交换两参数
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void cal(int A[], int size, int start, int step, int ** Graph, int * Path) {//全排列算法
	if (step == size-1) {
		int len = 0;
		for (int i = 0; i < size; i++) {
			cout << A[i] << " ";
			if (i < size-1) {
				len += Graph[A[i]][A[i + 1]];
			}
			else {
				len += Graph[A[i]][A[0]];
			}
			
		}
		cout << endl;

		if (len < minDist) {
			minDist = len;
			for (int i = 0; i < size; i++) {
				Path[i] = A[i];
			}
			Path[size] = A[0];
		}
	}
	for (int i = step; i < size; i++) {
		swap(A[start], A[i]);
		cal(A, size, start + 1, step + 1, Graph, Path);
		swap(A[i], A[start]);
	}
}



void main() {//主函数
	int N = 4;
	cout << "地点个数:" << endl << N << endl;

	int * Path = new int[N + 1];   //存贮最优路径  
	int ** Graph = new int *[N]; //建立动态的距离矩阵;  

	for (int i = 0; i < N; i++)
		Graph[i] = new int[N];

	ifstream input;
	input.open("1.txt"); //从txt文档读入矩阵信息  

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			input >> Graph[i][j]; //从txt文档输入矩阵  

	cout << "距离矩阵:" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << Graph[i][j] << " ";

		cout << endl;
	}
	cout << "求得所有排列如下：" << endl;
	int array[4] = { 0,1,2,3 };

	cal(array, N, 0, 0, Graph, Path);

	cout << "最短路径长度为：" << minDist << endl;
	cout << "最短路线为" << endl;

	char name[4] = { 'a','b','c','d' };
	for (int i = 0; i < N; i++) {
		if (i < N - 1) {
			cout << name[i] << " -- " << Graph[Path[i]][Path[i + 1]] << " -- > ";
		}
		else {
			cout << name[i] << " -- " << Graph[Path[i]][Path[i + 1]] <<" -- > "<< name[0] << endl;
		}
	}
	system("pause");
}