#include<iostream>
#include<fstream>
using namespace std;

int minDist = 9999;//Ԥ����С·��

void swap(int & a, int & b) {//����������
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void cal(int A[], int size, int start, int step, int ** Graph, int * Path) {//ȫ�����㷨
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



void main() {//������
	int N = 4;
	cout << "�ص����:" << endl << N << endl;

	int * Path = new int[N + 1];   //��������·��  
	int ** Graph = new int *[N]; //������̬�ľ������;  

	for (int i = 0; i < N; i++)
		Graph[i] = new int[N];

	ifstream input;
	input.open("1.txt"); //��txt�ĵ����������Ϣ  

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			input >> Graph[i][j]; //��txt�ĵ��������  

	cout << "�������:" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << Graph[i][j] << " ";

		cout << endl;
	}
	cout << "��������������£�" << endl;
	int array[4] = { 0,1,2,3 };

	cal(array, N, 0, 0, Graph, Path);

	cout << "���·������Ϊ��" << minDist << endl;
	cout << "���·��Ϊ" << endl;

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