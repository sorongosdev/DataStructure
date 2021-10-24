/*
후위 표기 식 계산
- 스택, 전역변수(Array)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define FALSE 0
#define TRUE 1
typedef char element;

typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
} StackType;

//초기화
void init(StackType* s) {
	s->top = -1;
}

//비었는가
int is_empty(StackType* s) {
	return (s->top == -1);
}

//차있는가
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE)-1);
}

//스택에 값추가
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "Stack is full\n");
		return;
	}
	else s->stack[++(s->top)]=item;
}

//스택 값 제거
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}

//스택 가장 윗부분 출력
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else return s->stack[(s->top)];
}

//후위 표기 계산 함수
element eval(char exp[]) {
	int op1, op2, value, i = 0;
	int len = strlen(exp);
	char ch;

	StackType s;
	init(&s);

	for (i = 0; i < len; i++) {
		ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') { //피연산자
			value = ch - '0'; //문자를 정수화
			push(&s, value);
		}
		else {
			op2 = pop(&s); //피연산자2
			op1 = pop(&s); //피연산자1
			switch (ch) {
			case '+': push(&s, op1 + op2); break;
			case '-': push(&s, op1 - op2); break;
			case '*': push(&s, op1 * op2); break;
			case '/': push(&s, op1 / op2); break;
			}
		}
	}
	return pop(&s); //피연산자를 빼서 연산자와 연산하는 과정을 반복.
}

//메인

void main() {
	int result;
	char postfix[100];

	printf("postfix input: ");
	scanf("%s", postfix);

	result = eval(postfix);
	printf("result is %d\n", result);
}