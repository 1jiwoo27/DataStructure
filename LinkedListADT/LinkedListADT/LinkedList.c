#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#define NUM 30
#pragma warning(disable:4996)

//ADD 함수를 사용할 때는 HELP에 적혀 있는 내용을 참조해 주세요!


//구조체
typedef struct ListNode {
	struct ListNode* next; 
	char data; 
}NODE;


typedef struct LinkedList {
	NODE* head; // head 노드
	NODE* current;
	int cur_pos; // 현재 위치
	int size; 
}LIST;


//함수
void __init__(LIST* self);
void addTail(LIST* self, char data);
void add(LIST* self, int count, char data); 
void printL(LIST* self);
void traverse_front(LIST* self, int count);
void traverse_rear(LIST* self, int count);
char get_data(LIST* self);
void delete(LIST* self);
void replace(LIST* self, char new_data);
int data_count(LIST* self);
int is_member(LIST* self, char data);
void is_empty(LIST* self);
void move_prev(LIST* self);
void move_next(LIST* self);
void clear(LIST* self);
void help(void);


//main 함수
int main() {

	char user[NUM];
	int result; 
	char pos;
	LIST my_list;

	__init__(&my_list); //LinkedList 초기화

	help();
	printf("\n");

	while (1) {

		printf(" >> ");
		gets(user);
		int userLen = strlen(user);

		int Ncnt = 0; //N 카운트변수
		int Pcnt = 0; //P 카운트변수

		for (int i = 0; i < userLen; i++) {
			if (user[i] == 'N') {
				if (user[i - 1] == '^') {
					continue;
				}
				else {
					Ncnt++;
				}
			}
			else if (user[i] == 'P') {
				Pcnt++;
			}
		}

		for (int i = 0; i < userLen; i++) {

			//0 <= user[0] <= 9 / user[0]이 한 자릿수 정수일 때
			if ((user[0] > 48) && (user[0] <= 57)) { 
				traverse_front(&my_list, user[0] - '0' - 1);

			}

			if (user[i] == '+') {
				addTail(&my_list, user[i + 1]);
			}

			else if (user[i] == 'L') {
				continue;
			}

			else if (user[i] == 'G') {
				printf(" %c ", get_data(&my_list));
				break;
			}

			else if (user[i] == '<') {
				traverse_front(&my_list, Ncnt);
			}

			else if (user[i] == '>') {
				traverse_rear(&my_list, Pcnt);
			}

			else if (user[i] == '^') {
				if (user[i + 1] == 'N') {
					add(&my_list, 1, user[i + 2]);
				}
				else {
					add(&my_list, 0, user[i + 1]);
				}
			}

			else if (user[i] == '-') {
				delete(&my_list);
			}

			else if (user[i] == '=') {
				replace(&my_list, user[i + 1]);
			}

			else if (user[i] == '#') {
				printf(" %d", data_count(&my_list));
			}

			else if (user[i] == 'C') {
				clear(&my_list);
			}

			else if (user[i] == 'E') {
				is_empty(&my_list);
			}

			else if (user[i] == 'M') {
				if (user[i + 1] == 'P') { //추가 기능1
					move_prev(&my_list);
				}
				else if (user[i + 1] == 'N') { //추가 기능2
					move_next(&my_list);
				}
			}

			else if (user[i] == '?') {
				result = is_member(&my_list, user[i + 1]);

				if (result > 0) {
					printf(" %d :", result);
				}
				else if (result == -1) {
					printf(" NOT FOUND");
				}
			}

			else if (user[i] == 'H') {
				help();
			}

			else if (user[i] == 'Q') { //추가 기능3
				printf(" QUIT");
				break;
			}
		} 


		if (user[0] == '#') {}
		else if (user[0] == 'C') {}
		else if (user[0] == 'H') {}
		else if ((user[0] == '?') && (result == -1)) {}
		else if ((user[0] > 48) && (user[0] <= 57) && (user[1] == 'G')) {}
		else if (user[0] == 'Q') {
			break;
		}
		else if (user[0] == 'G')
		{
			printf("(");
			printL(&my_list);
			printf(")");
		}
		else {
			printL(&my_list);
		}
		printf("\n");
	} 
	return 0;
}


void __init__(LIST* self) { 
	self->head = (NODE*)malloc(sizeof(NODE));
	self->head->next = NULL;
	self->current = self->head;
	self->cur_pos = 0;
	self->size = 0;
}


void addTail(LIST* self, char data) {
	NODE* NEW = (NODE*)malloc(sizeof(NODE));
	NEW->data = data;
	NEW->next = NULL; 

	NODE* NEXT = self->head->next;
	for (int i = 0; i < self->size - 1; i++) {
		NEXT = NEXT->next;
	}
	if (self->size == 0) {
		self->head->next = NEW;
		self->size++;
	}
	else {
		NEXT->next = NEW;
		self->size++;
		self->cur_pos = self->size - 1;
	}
	self->current = NEW;
}


void add(LIST* self, int count, char data) {
	NODE* NEW = (NODE*)malloc(sizeof(NODE));
	NEW->data = data;

	NODE* PREV = self->head;
	for (int i = 0; i < self->cur_pos; i++) {
		PREV = PREV->next;
	}

	if (count == 0) { //*(data)
		PREV->next = NEW;
		NEW->next = self->current;
	}
	else if (count == 1) { //*N(data)
		NEW->next = self->current->next;
		self->current->next = NEW;
		self->cur_pos++;
	}
	self->current = NEW;
	self->size++;

}


void printL(LIST* self) {
	NODE* NEXT = self->head->next;
	for (int i = 0; i < self->size; i++) {
		if (i == self->cur_pos) {
			printf(" (%c) ", NEXT->data);
		}
		else {
			printf(" %c ", NEXT->data);
		}
		NEXT = NEXT->next;
	}
}


void traverse_front(LIST* self, int count) {
	self->cur_pos = count;
	NODE* NEXT = self->head->next;
	for (int i = 0; i < self->cur_pos; i++) {
		NEXT = NEXT->next;
	}
	self->current = NEXT;
}


void traverse_rear(LIST* self, int count) {
	self->cur_pos = self->size - count - 1;
	NODE* LAST = self->head;
	for (int i = 0; i <= self->cur_pos; i++) {
		LAST = LAST->next;
	}
	self->current = LAST;
}


char get_data(LIST* self) {
	return self->current->data;
}


void delete(LIST* self) {
	NODE* PREV = self->head->next;
	for (int i = 0; i < self->cur_pos - 1; i++) {
		PREV = PREV->next;
	}

	if (self->current->next == NULL) { 
		PREV->next = NULL;
		if (self->size == 1) { 
			self->current = self->head;
			self->cur_pos = 0;
		}
		else { 
			self->current = self->head->next;
			self->cur_pos = 0;
		}
	}
	else {
		NODE* DEL = self->current;
		PREV->next = self->current->next;
		self->current = self->current->next;
		free(DEL);
	}
	self->size--;
}


void replace(LIST* self, char new_data) {
	self->current->data = new_data;
}

int data_count(LIST* self) {
	return self->size;
}

int is_member(LIST* self, char data) {
	int mpos = 0;
	int savepos = self->cur_pos;
	NODE* savecur = self->current;
	NODE* NEXT = self->head->next;
	while (NEXT != NULL) {
		self->cur_pos = mpos;
		self->current = NEXT;
		if (NEXT->data == data) {
			return mpos + 1;
		}
		NEXT = NEXT->next;
		mpos++;
	}
	self->cur_pos = savepos;
	self->current = savecur;
	return -1;

}


void is_empty(LIST* self) {
	if (self->size == 0) {
		printf(" TRUE");
	}
	else {
		printf(" FASLE");
	}

}


void move_prev(LIST* self) {
	NODE* PREV = self->head->next;
	for (int i = 0; i < self->cur_pos - 1; i++) {
		PREV = PREV->next;
	}

	char savedata = self->current->data;
	self->current->data = PREV->data;
	PREV->data = savedata;

	self->cur_pos--;
	self->current = PREV;
}


void move_next(LIST* self) {
	NODE* NEXT = self->head->next;
	for (int i = 0; i < self->cur_pos + 1; i++) {
		NEXT = NEXT->next;
	}

	char savedata = self->current->data;
	self->current->data = NEXT->data;
	NEXT->data = savedata;

	self->cur_pos++;
	self->current = NEXT;
}


void clear(LIST* self) {
	NODE* DEL;
	NODE* NEXT = self->head->next;
	while (NEXT != NULL) {
		DEL = NEXT;
		NEXT = NEXT->next;
		free(DEL);
	}
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
	printf("\n%-22s %s\n", "ADDTAIL", ": +(data)");
	printf("%-22s %s\n", "ADD", ": ^(data)");
	printf("%-22s %s\n", "DELETE", ": -");
	printf("%-22s %s\n", "DELETE LAST", ": > -");
	printf("%-22s %s\n", "TRAVERSE_FRONT", ": <");
	printf("%-22s %s\n", "TRAVERSE_REAR", ": >");
	printf("%-22s %s\n", "GET_DATA", ": G");
	printf("%-22s %s\n", "REPLACE", ": =(data)");
	printf("%-22s %s\n", "CLEAR", ": C");
	printf("%-22s %s\n", "DATA_COUNT", ": #");
	printf("%-22s %s\n", "IS_MEMBER", ": ?(data)");
	printf("%-22s %s\n", "IS_EMPTY", ": E");
	printf("%-22s %s\n", "MOVE_PREV", ": MP");
	printf("%-22s %s\n", "MOVE_NEXT", ": MN");
	printf("%-22s %s\n", "PRINT", ": L");
	printf("%-22s %s\n", "PREV", ": P");
	printf("%-22s %s\n", "NEXT", ": N");
	printf("%-22s %s\n", "HELP", ": H");
	printf("%-22s %s\n", "QUIT", ": Q");
	printf("\n");
	printf("%-22s\n", "**Use ADD(0) like this:");
	printf("%-22s\n", ">> ^(data) ^N(data) ^N(data)");
	printf("%-22s\n", "**Use ADD(N) like this:");
	printf("%-22s\n", ">> ^N(data) ^N(data) ^N(data)");
	printf("\n");
	printf("%-22s\n", "**Spacing between commands");
	printf("%-22s\n", "**Only one character for one data");
	
	for (int i = 0; i < 35; i++) {
		printf("-");
	}
}