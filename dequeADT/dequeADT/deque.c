#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <malloc.h>
#pragma warning(disable:4996)

#define NUM 30
#define Max_Size 20


typedef struct DequeNode {
	struct DequeNode* llink;
	struct DequeNode* rlink;
	char data;
} Node;

typedef struct DequeList {
	Node* head;
	Node* tail;
} deque;


//함수
void __init__(deque* self);
void is_empty(deque* self);
void is_full(deque* self);
void add_front(deque* deque, char data);
void add_rear(deque* deque, char data);
void delete_front(deque* deque);
void delete_rear(deque* deque);
void get_front(deque* self);
void get_rear(deque* self);
void data_count(deque* self);
void printQ(deque* self);
void clear(deque* self);
void help(void);


//main 함수
int main() {

	char user[NUM];
	deque my_deque;

	__init__(&my_deque); //queue 초기화

	help();
	printf("\n");

	while (1) {

		printf(" >> ");
		gets(user);

		int userlen = strlen(user);

		for (int i = 0; i < userlen; i++) {

			if (user[i] == '+') {
				add_front(&my_deque, user[i + 1]);
			}

			else if (user[i] == '*') {
				add_rear(&my_deque, user[i + 1]);
			}

			else if (user[i] == '-') {
				if (user[i + 1] == 'F') {
					delete_front(&my_deque);
				}
				else if (user[i + 1] == 'R') {
					delete_rear(&my_deque);
				}
				break;
			}

			else if (user[i] == 'G') {
				if (user[i + 1] == 'F') {
					get_front(&my_deque);
				}
				else if (user[i + 1] == 'R') {
					get_rear(&my_deque);
				}
				break;
			}

			else if (user[i] == 'E') {
				is_empty(&my_deque);
			}

			else if (user[i] == 'F') {
				is_full(&my_deque);
			}

			else if (user[i] == '#') {
				data_count(&my_deque);
			}

			else if (user[i] == 'L') {
				continue;
			}

			else if (user[i] == 'C') {
				clear(&my_deque);
			}

			else if (user[i] == 'H') {
				help();
			}

			else if (user[i] == 'Q') {
				printf(" QUIT");
				break;
			}
		}


		if (user[0] == 'Q') {
			break;
		}
		else if (user[0] == 'G') {}
		else if (user[0] == 'C') {}
		else if (user[0] == 'F') {}
		else if (user[0] == 'E') {}
		else if (user[0] == '#') {}
		else if (user[0] == 'H') {}
		else if (user[0] == 'C') {}
		else {
			printQ(&my_deque);
		}
		printf("\n");
	}
	return 0;
}


void __init__(deque* self) {
	self->head = (Node*)malloc(sizeof(Node));
	self->head->rlink = NULL;
	self->head = 0;
	self->tail = 0;
}


void is_empty(deque* self) {
	if (self->head == NULL) {
		printf(" True");
	}
	else {
		printf(" False");
	}
}


void is_full(deque* self) {
	int cnt = 0; //노드 수 세기
	Node * temp = self->head;
	while (temp) {
		temp = temp->rlink;
		cnt++;
	}
	if (cnt >= Max_Size) {
		printf(" True");
	}
	else {
		printf(" False");
	}
}



void add_front(deque* self, char data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	int cnt = 0;
	Node* temp = self->head;
	while (temp) {
		temp = temp->rlink;
		cnt++;
	}

	if (cnt == Max_Size) {
		printf(" Deque overflow\n");
	}
	else {
		//덱이 공백인 경우 
		if (self->head == NULL) {
			self->head = newNode;
			self->tail = newNode;
			newNode->rlink = NULL;
			newNode->llink = NULL;
		}
		else {
			self->head->llink = newNode;
			newNode->rlink = self->head;
			newNode->llink = NULL;
			self->head = newNode;
		}
	}
}


void add_rear(deque* self, char data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	int cnt = 0;
	Node* temp = self->head;
	while (temp) {
		temp = temp->rlink;
		cnt++;
	}

	if (cnt == Max_Size) {
		printf(" Deque overflow\n");
	}
	else {
		//덱이 공백인 경우 
		if (self->tail == NULL) {
			self->head = newNode;
			self->tail = newNode;
			newNode->rlink = NULL;
			newNode->llink = NULL;
		}
		else {
			self->tail->rlink = newNode;
			newNode->rlink = NULL;
			newNode->llink = self->tail;
			self->tail = newNode;
		}
	}
}


void delete_front(deque* self) {
	Node* delNode = self->head;
	char save;
	if (self->head == NULL) {
		printf(" -");
	}
	else {
		save = delNode->data;
		if (self->head->rlink == NULL) {
			self->head = NULL;
			self->tail = NULL;
		}
		else {
			self->head = self->head->rlink;
			self->head->llink = NULL;
		}
		free(delNode);
		printf(" return %c\n", save);
	}
}


void delete_rear(deque* self) {
	Node* delNode = self->tail;
	char save;
	if (self->tail == NULL) {
		printf(" -");
	}
	else {
		save = delNode->data;
		if (self->tail->llink == NULL) {
			self->head = NULL;
			self->tail = NULL;
		}
		else {
			self->tail = self->tail->llink;
			self->tail->rlink = NULL;
		}
		free(delNode);
		printf(" return %c\n", save);
	}
}


void get_front(deque* self) {
	if (self->head == NULL) {
		printf(" -");
	}
	else {
		printf(" %c", self->head->data);
	}
}


void get_rear(deque* self) {
	if (self->tail == NULL) {
		printf(" -");
	}
	else {
		printf(" %c", self->tail->data);
	}
}


void data_count(deque* self) {
	int cnt = 0;
	Node* temp = self->head;
	while (temp) {
		temp = temp->rlink;
		cnt++;
	}
	printf(" %d", cnt);
}


void printQ(deque* self) {
	Node* temp = self->head;
	while (temp) {
		printf("%2c", temp->data);
		temp = temp->rlink;
	}
}


void clear(deque* self) {
	if (self->tail == NULL) {}
	else {
		Node* delNode;
		Node* NEXT = self->head->rlink;
		while (NEXT != NULL) {
			delNode = NEXT;
			NEXT = NEXT->rlink;
			free(delNode);
		}
		__init__(self);
	}
	printf(" -");
}


void help() {
	for (int i = 0; i < 15; i++) {
		printf("-");
	}
	printf("H E L P");
	for (int i = 0; i < 15; i++) {
		printf("-");
	}
	printf("\n%-22s %s\n", "ADD_FRONT", ": +(data)");
	printf("%-22s %s\n", "ADD_REAR", ": *(data)");
	printf("%-22s %s\n", "DELETE_FRONT", ": -F");
	printf("%-22s %s\n", "DELETE_REAR", ": -R");
	printf("%-22s %s\n", "GET_FRONT", ": GF");
	printf("%-22s %s\n", "GET_REAR", ": GR");
	printf("%-22s %s\n", "IS_EMPTY", ": E");
	printf("%-22s %s\n", "IS_FULL", ": F");
	printf("%-22s %s\n", "DATA_COUNT", ": #");
	printf("%-22s %s\n", "PRINT", ": L");
	printf("%-22s %s\n", "CLEAR", ": C");
	printf("%-22s %s\n", "HELP", ": H");
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