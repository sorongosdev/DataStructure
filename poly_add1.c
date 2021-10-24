/*
���׽� ����1
: �ְ������� �̿�(0)
*/

#include <stdio.h>
#define MAX(a,b) ( ((a)>(b)) ? (a) : (b)) // �� �� ū �� ����
#define MAX_DEGREE 101

typedef struct {
	int degree; //�ְ�����
	float coef[MAX_DEGREE]; //���
}polynomial;

polynomial poly_add1(polynomial A, polynomial B) {
	polynomial C;
	int Apos = 0, Bpos = 0, Cpos = 0;
	int degree_a = A.degree;
	int degree_b = B.degree;

	C.degree = MAX(A.degree, B.degree); //�� �� ū ������ C�� ������ ����, ��� ����

	while (Apos <= A.degree && Bpos <= B.degree) { // A �ε����� A �ְ��������� �۰�, B �ε����� B �ְ��������� ���� �� �ݺ�
		if (degree_a > degree_b) { //A�� ������ B�� �������� ũ�ٸ�
			C.coef[Cpos++] = A.coef[Apos++]; //A�� ����� C�� ����� ����
			degree_a--;
		}
		else if (degree_a == degree_b) { //A������ B������ ���ٸ�
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--; degree_b--;
		}
		else {
			C.coef[Cpos++] == B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}

void main() {
	polynomial a = { 5,{3,6,0,0,0,10} };
	polynomial b = { 4,{7,0,5,0,1} };
	polynomial c;
	c = poly_add1(a, b);
	
	printf("polynomial c= ");
	for (int i = 0; i <= c.degree; i++) {
		printf("%.2fx^%d", c.coef[i], c.degree - i);
		if (i < c.degree)
			printf("+ ");
	}
	printf("\n");
}