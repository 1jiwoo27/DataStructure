#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#pragma warning(disable:4996)

#define NUM 30
#define Max_Size 20
#define True 1
#define False 0


typedef struct queue {
	char data[Max_Size];
	int head;
	int tail;
}queue;


//함수
void __init__(queue* self);
void enqueue(queue* self, char data);
void printQ(queue* self);
void printR(queue* self);
void peek(queue* self);
void peekT(queue* self);
void dequeue(queue* self);
int is_full(queue* self);
int is_empty(queue* self);
void data_count(queue* self);
void headL(queue* self);
void tailL(queue* self);
void is_member(queue* self, char data);
void replace(queue* self, char new_data);
void clear(queue* self);
void help(void);


//main 함수
int main() {

	char user[NUM];
	int result;
	queue my_queue;

	__init__(&my_queue); //queue 초기화
	
	help();
	printf("\n");

	while (1) {

		printf(" >> ");
		gets(user);

		int userlen = strlen(user);

		for (int i = 0; i < userlen; i++) {

			//0 <= user[0] <= 9 / user[0]이 한 자릿수 정수일 때
			if ((user[0] > 48) && (user[0] <= 57)) {
				if (user[1] == '-') {
					for (i = 0; i<user[0]-'0'; i++) {
						dequeue(&my_queue);
					}
				}

			}

			if (user[i] == '+') {
				enqueue(&my_queue, user[i + 1]);
			}

			else if (user[i] == 'L') {
				continue;
			}

			else if (user[i] == 'R') { //추가 기능1 (tail부터 head까지 역순으로 출력)
				printR(&my_queue);
			}

			else if (user[i] == 'P') {
				peek(&my_queue);
			}

			else if (user[i] == '>') { //추가 기능2 (tail값 peek)
				peekT(&my_queue);
			}

			else if (user[i] == '-') {
				dequeue(&my_queue);
			}

			else if (user[i] == 'F') {
				result = is_full(&my_queue);
				if (result == True) {
					printf(" True");
				}
				else {
					printf(" False");
				}
			}

			else if (user[i] == 'E') {
				result = is_empty(&my_queue);
				if (result == True) {
					printf(" True");
				}
				else {
					printf(" False");
				}
			}

			else if (user[i] == '#') {
				data_count(&my_queue);
			}

			else if (user[i] == 'H') {
				headL(&my_queue);
			}

			else if (user[i] == 'T') {
				tailL(&my_queue);
			}

			else if (user[i] == '?') {
				is_member(&my_queue, user[i + 1]);
			}

			else if (user[i] == '=') {
				replace(&my_queue, user[i + 1]);
			}

			else if (user[i] == 'C') {
				clear(&my_queue);
			}

			else if (user[i] == '!') {
				help();
			}

			else if (user[i] == 'Q') { //추가 기능3 (프로그램 종료)
				printf(" QUIT");
				break;
			}
		}


		if (is_empty(&my_queue)==True) {
			if (user[0] == '-') {}
			else if (user[0] == 'Q') {}
			else if (user[0] == 'E') {}
			else if (user[0] == 'H') {}
			else if (user[0] == 'F') {}
			else if (user[0] == '#') {}
			else if (user[0] == '?') {}
			else {
				printf(" -");
			}
		}

		if (user[0] == 'Q') {
			break;
		}
		else if (user[0] == 'P') {}
		else if (user[0] == '>') {}
		else if (user[0] == 'R') {}
		else if (user[0] == 'F') {}
		else if (user[0] == '#') {}
		else if (user[0] == 'T') {}
		else if (user[0] == 'H') {}
		else if (user[0] == 'C') {}
		else if (user[0] == '?') {}
		else if (user[0] == 'Q') {
			break;
		}
		else {
			printQ(&my_queue);
		}
		printf("\n");
	}
	return 0;
}


void __init__(queue* self) {
	self->head = -1;
	self->tail = -1;
}


void enqueue(queue* self, char data) {
	if (is_full(&self) == False) {
		self->data[self->tail+1] = data;
		self->tail++;
	}
	else {
		if (self->head == self->tail) {
			__init__(&self);
			self->data[self->tail] = data;
			self->tail++;
		}
		else {
			printf(" Queue overflow");
		}
	}
}


void printQ(queue* self) {
	for (int i = self->head+1; i < self->tail+1; i++) {
		printf(" %c ", self->data[i]);
	}
}


void printR(queue* self) {
	for (int i = self->tail; i > self->head; i--) {
		printf(" %c ", self->data[i]);
	}
}



void peek(queue* self) {
	printf(" %c ", self->data[self->head+1]);
}


void peekT(queue* self) {
	printf(" %c ", self->data[self->tail]);
}


void dequeue(queue* self) {
	if (self->head != self->tail) {
		char a = self->data[self->head + 1];
		self->data[self->head + 1] = '\0';
		printf(" return %c", a);
		self->head++;
		printf("\n");
	}
	else {
		printf(" Error (nothing to dequeue)");
	}
	
}


int is_full(queue* self) {
	if (self->tail == Max_Size-1) {
		return True;
	}
	else {
		return False;
	}

}


int is_empty(queue* self) {
	if (self->head == self->tail) {
		return True;
	}
	else {
		return False;
	}
}


void data_count(queue* self) {
	printf(" %d", self->tail - self->head);
}


void headL(queue* self) {
	printf(" %d", self->head+2);
}

void tailL(queue* self) {
	printf(" %d", self->tail+1);
}


void is_member(queue* self, char data) {
	int member = -1;
	for (int i = self->head + 1; i <= self->tail; i++) {
		if (self->data[i] == data) {
			member = i;
		}
	}
	if (member == -1) {
		printf(" False");
	}
	else {
		printf(" True");
	}
}


void replace(queue* self, char new_data) {
	self->data[self->tail] = new_data;
}


void clear(queue* self) {
	__init__(self);
}


void help() {
	for (int i = 0; i < 15; i++) {
		printf("-");
	}
	printf("H E L P");
	for (int i = 0; i < 15; i++) {
		printf("-");
	}
	printf("\n%-22s %s\n", "ENQUEUE", ": +(data)");
	printf("%-22s %s\n", "PRINT", ": L");
	printf("%-22s %s\n", "PRINT_REVERSE", ": R");
	printf("%-22s %s\n", "PEEK", ": P");
	printf("%-22s %s\n", "PEEK_TAIL", ": >");
	printf("%-22s %s\n", "DEQUEUE", ": -");
	printf("%-22s %s\n", "IS_FULL", ": F");
	printf("%-22s %s\n", "IS_EMPTY", ": E");
	printf("%-22s %s\n", "DATA_COUNT", ": #");
	printf("%-22s %s\n", "HEAD", ": H"); 
	printf("%-22s %s\n", "TAIL", ": T");
	printf("%-22s %s\n", "IS_MEMBER", ": ?(data)");
	printf("%-22s %s\n", "REPLACE", ": =(data)");
	printf("%-22s %s\n", "CLEAR", ": C");
	printf("%-22s %s\n", "HELP", ": !");
	printf("%-22s %s\n", "QUIT", ": Q");
	printf("\n");
	printf("%-22s %s\n", "**Max Size of Queue", ": 20");
	printf("\n");
	printf("%-22s\n", "**Spacing between commands");
	printf("%-22s\n", "**Only one character for one data");

	for (int i = 0; i < 35; i++) {
		printf("-");
	}

}