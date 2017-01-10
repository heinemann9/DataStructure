#include <stdio.h>

int factorial(int n);
double power(double x, int n);
int fib(int n);
void hanoi_tower(int n, char from, char tmp, char to);
int bin_coefficient(int n, int k);
int Ackermann(int m, int n);

int main(int argc, char* argv[]){
	
	printf("factorial(5) = %d\n", factorial(5));
	printf("power(2,6) = %f\n", power(2, 6));
	printf("fib(5) = %d\n",fib(5));
	printf("hanoi start\n");
	hanoi_tower(4, 'a', 'b', 'c');
	printf("hanoi end\n");
	printf("bin_coefficient(5,3) = %d\n", bin_coefficient(5, 3));
	printf("Ackermann(3,2),(2,3) = %d, %d\n", Ackermann(3, 2), Ackermann(2, 3));
	return 0;
}

// 팩토리얼 > 5! = 5*4*3*2*1
int factorial(int n){
	
	if(n <= 1) 
		return 1;
	else
		return n * factorial(n-1);
}

// 거듭제곱 > (x^2)^(n/2)공식을 이용하여 거듭제곱승이 홀수인 경우 ^((n-1)/2), 짝수인 경우 ^(n/2)
double power(double x, int n){
	if(n == 0) 
		return 1;
	else if((n%2) == 0)
		return power(x*x, n/2);
	else
		return x * power(x*x, (n-1)/2);
}

// 피보나치 수열 계산 > n-2번째 수열과 n-1번째 수열의 합
int fib(int n){
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	return fib(n-1) + fib(n-2);
}

// 하노이 타워 > n-1개의 원판을 B로 옮긴 뒤, 제일 밑에 있는 원판을 C에 옮긴 뒤, n-1개의 원판을 C로 옮기는 원리 
void hanoi_tower(int n, char from, char tmp, char to){
	if(n == 1)
		printf("%d - from %c to %c\n", n, from, to);
	else{
		hanoi_tower(n-1, from, to, tmp);
		printf("%d - from %c to %c\n", n, from, to);
		hanoi_tower(n-1, tmp, from, to);
	}
}

// 이항계수 > n C k = n-1 C k-1 + n-1 C k (0 < k < n)
//		    = 1 		  (k = 0 or k = n )
int bin_coefficient(int n, int k){
	if(k == 0 || k == n)
		return 1;
	else
		return bin_coefficient(n-1,k-1) + bin_coefficient(n-1,k);
}

// Ackermann Func > 음수 x
int Ackermann(int m, int n){
	if(m == 0)
		return n+1;
	else if(n == 0)
		return Ackermann(m-1, 1);
	else
		return Ackermann(m-1, Ackermann(m,n-1));
}
