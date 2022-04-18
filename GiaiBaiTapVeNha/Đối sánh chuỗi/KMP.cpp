#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <conio.h>
using namespace std;


void FailureFunction(char P[], int F[], int m) {
	int i, j;
	F[0] = 0; // Nho gan cai nay
	j = 0;
	i = 1;
	while (i < m) { //khi i dang nho hon do dai cua mau
		if (P[i] == P[j]) {
			F[i] = j + 1;
			i++;
			j++;
		}
		else if (j > 0) {
			j = F[j - 1];
		}
		else {
			F[i] = 0;
			i++;
		}
	}
}
int KMP(char T[], char P[]) {
	int i, j, F[100]; // mau P khong qua 100 ky tu
	int m = strlen(P);
	int n = strlen(T);
	FailureFunction(P, F, m);
	i = 0;
	j = 0;
	while (i < n) {
		if (T[i] == P[j]) {
			if (j == m - 1)
				return i - j; // vi tri duoc tim thay la i-j
			else {
				i++;
				j++;
			}
		}
		else if (j > 0) {
			j = F[j - 1];
		}
		else {
			i++;
		}
	}
	return -1; // Tra ve -1 neu khong khop
}
int main()
{
	char T[1000], P[100];
	gets_s(T);
	gets_s(P);
	int pos = KMP(T, P);
	if (pos != -1)
		cout << "Mau khop voi doan van tai vi tri : " << pos;
	else
		cout << "Mau khong khop voi doan van\n\n";

	return 0;
}