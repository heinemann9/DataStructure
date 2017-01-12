#include <stdio.h>
#include <stdlib.h>
#define MAX_STUDENTS 200
#define MAX_NAME 100

struct person {
	char name[10];
	int age;
	float height;
};

typedef struct person2 {
	char name[10];
	int age;
	float height;
} person2;

// 자체 참조 구조체 - 자기 자신을 가리키는 포인터가 한 개 이상 존재하는 구조체
typedef struct ListNode {
	char data[10];
	struct ListNode *link;
} ListNode;

typedef struct {
	int month;
	int date;
} BirthdayType;

typedef struct {
	char name[MAX_NAME];
	BirthdayType birthday;
} StudentType;

int main(int argc, char* argv[]){

	struct person a;
	person2 b;
	
	StudentType students[MAX_STUDENTS];
	strcpy(students[0].name, "HGD");
	students[0].birthday.month = 10;
	students[0].birthday.date = 28;

	printf("%s %d %d\n",students[0].name,students[0].birthday.month,students[0].birthday.date);
	return 0;
}
