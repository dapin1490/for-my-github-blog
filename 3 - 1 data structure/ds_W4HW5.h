#include <stdio.h>
#define MAX_DEGREE	80

class Polynomial {
	int	degree;				// 다항식의 최고 차수
	float coef[MAX_DEGREE];	// 각 항에 대한 계수

public:
	void read() {
		int i;
		printf("다항식의 최고 차수를 입력하시오: ");
		scanf("%d", &degree);
		printf("각 항의 계수를 입력하시오 (총 %d개): ", degree + 1);
		for (i = degree; i >= 0; i--)
			scanf("%f", coef + i);
	}
	void print(char *str) {
		int i;
		printf("\t%s", str);
		for (i = degree; i > 0; i--)
			printf("%5.1f x^%d + ", coef[i], i);
		printf("%4.1f\n", coef[0]);
	}

	void add(Polynomial a, Polynomial b) {
		int i;
		if (a.degree > b.degree) {
			// *this = a;
			degree = a.degree;
			for (i = 0; i <= b.degree; i++)
				coef[i] = a.coef[i] + b.coef[i];
			for (i = b.degree + 1; i <= a.degree; i++)
				coef[i] = a.coef[i];
		}
		else {
			// *this = b;
			degree = a.degree;
			for (i = 0; i <= a.degree; i++)
				coef[i] = a.coef[i] + b.coef[i];
			for (i = a.degree + 1; i <= b.degree; i++)
				coef[i] = b.coef[i];
		}
	}
	int isZero() { return degree == 0; }
	void negate() {
		int i;
		for (i = 0; i <= degree; i++)
			coef[i] = -coef[i];
	}

	// (1)
	void sub(Polynomial a, Polynomial b) {
		b.negate();
		add(a, b);
	}

	// (2)
	void mult(Polynomial a, Polynomial b) {
		int i, j;
		degree = a.degree + b.degree;
		for (i = 0; i <= degree; i++) coef[i] = 0;
		for (i = 0; i <= a.degree; i++)
			for (j = 0; j <= b.degree; j++)
				coef[i + j] += a.coef[i] * b.coef[j];
	}

	// (3)
	void trim() {
		int i;
		for (i = degree; i > 0; i--) {
			if (coef[i] != 0) return;
			degree--;
		}
	}

	// (4)
	void display(const char *str = " Poly = ") {
		int i;
		printf("\t%s", str);
		for (i = degree; i > 0; i--) {
			if (coef[i] != 0) {
				if (i != degree)
					printf(" + ");
				if (coef[i] == 1)
					printf("x^%d", i);
				else
					printf("%5.1f x^%d", coef[i], i);
			}
		}
		if (coef[0] != 0)
			printf(" + %4.1f\n", coef[0]);
	}
};

