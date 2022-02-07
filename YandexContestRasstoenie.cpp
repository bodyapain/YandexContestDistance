Рассмотрим целочисленный массив a длины n. Назовём расстоянием от индекса i до множества индексов S величину dist(i,S)=∑j∈S∣∣ai−aj∣∣.
Зафиксируем целое число k. Рассмотрим функцию f(i)=mindist(i,S), где минимум берётся по множествам S размера k, 
не содержащим индекс i.Определите значение f(i) для всех i от 1 до n.
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;
/**/


int main()
{
	int n, k, c, sum = 0, maxin = 0,tmp=0,number,tmp1;
	cin >> n >> k;
	int* A = NULL;
	
	A = new int[n];
	
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < n; i++) {
		c = 0;
		sum = 0;
		vector <int> ivector;
		for (int j = 0; j < n; j++) {
			if (j == i) {
				continue;
			}
			number = abs(A[i] - A[j]);
			ivector.push_back(number);
			if (ivector.size() >= k) {
				maxin = 0;
				for (int b = 0; b <= k - 1; b++) {
					if (ivector[b] > maxin) {
						maxin = ivector[b];
						tmp = b;
					}
				}
				if (number <= maxin) {
					swap(ivector[ivector.size() - 1], ivector[tmp]);
				}
			}			
		}		
		for (int j = 0; j <= k-1; j++) {
			sum += ivector[j];
		}
		cout << sum<< " ";
		
	}
}



