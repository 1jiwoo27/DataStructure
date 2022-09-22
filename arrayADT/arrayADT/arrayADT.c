#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM 30
#pragma warning(disable : 4996)


//함수
void traverse_front(char* arr);
void traverse_rear(char* arr);
void prev(char* arr);
void next(char* arr);
void delete(char* arr);
void get_data(char* arr);
void replace(char* arr);
void empty(char* arr);
void move(char* arr, int position);
void move_front(char* arr);
void move_end(char* arr);
void move_prev(char* arr);
void move_next(char* arr);
void find(char* arr, int position);
void odd(char* arr);
void even(char* arr);
void help();



//변수
int cur_pos = -1; //현재 위치
int position;
char new_data;
char arr[NUM]; //정보가 저장된 배열
char user[NUM]; //사용자로부터 입력받은 배열


//main 함수
int main(void) {
	char arr[NUM] = { '\0' };
	char user[NUM] = { '\0' };
	int j = 0;

	help();

	while (1) {
		printf("\n>> ");
		gets(user);



		if (strstr(user, "E") != NULL) {
			empty(arr);
			continue;
		}

		else if (strstr(user, "F") != NULL) {
			for (int i = 0; i < NUM; i++) {
				if (user[i] == 'F') {
					user[i] = user[i + 1];
					user[i + 1] = '\0';
				}
			}
			char c = user[0];
			int n = 0;
			n = c - '0';
			find(arr, n);
			continue;
		}

		else if (strstr(user, "O") != NULL) {
			odd(arr);
			continue;
		}

		else if (strstr(user, "V") != NULL) {
			even(arr);
			continue;
		}

		else if (strstr(user, "H") != NULL) {
			printf("\n");
			help();
			continue;
		}

		else if (strstr(user, "Q") != NULL) {
			printf("프로그램을 종료합니다.\n");
			break;
		}

		else {


			if (strstr(user, "+") != NULL) {
				if (arr[0] == NULL) {
					for (int i = 0; i < NUM; i++) {
						if (user[i] == '+') {
							arr[cur_pos + 1] = user[i + 1];
							cur_pos++;
						}
					}
				}
				else {
					for (int i = 0; i < NUM; i++) {
						if (user[i] == '+') {
							arr[cur_pos + 1] = user[i + 1];
							cur_pos++;
						}
						arr[cur_pos + 1] = arr[cur_pos];
					}
					arr[cur_pos + 1] = '\0';
					cur_pos -= 1;
				}
			}


			else if (strstr(user, "@") != NULL) {
				get_data(arr);
			}

			else if ((strstr(user, ">") != NULL) && (strstr(user, "-") != NULL)) {
				traverse_rear(arr);
				delete(arr);
				cur_pos = 0;
				for (int i = 3; i < NUM; i++) {
					if (user[i] == '-') {
						delete(arr);
					}
				}
			}

			else if (strstr(user, "-") != NULL) {
				delete(arr);
			}

			else if ((strstr(user, "<") != NULL) && (strstr(user, "N") != NULL)) {
				traverse_front(arr);
				for (int i = 0; i < NUM; i++) {
					if (user[i] == 'N') {
						next(arr);
						i++;
					}
				}
			}

			else if ((strstr(user, "<") != NULL) && (strstr(user, "M") != NULL)) {
				traverse_front(arr);
				for (int i = 0; i < NUM; i++) {
					if (user[i] == 'M') {
						user[i] = user[i + 1];
						user[i + 1] = '\0';
					}
				}
				char c = user[2];
				int n = 0;
				n = c - '0';
				move(arr, n);
			}

			else if (strstr(user, "<") != NULL) {
				traverse_front(arr);
			}

			else if ((strstr(user, ">") != NULL) && (strstr(user, "P") != NULL)) {
				traverse_rear(arr);
				for (int i = 0; i < NUM; i++) {
					if (user[i] == 'P') {
						prev(arr);
						i++;
					}
				}
			}

			else if (strstr(user, ">") != NULL) {
				traverse_rear(arr);
			}


			else if (strstr(user, "=") != NULL) {// user 문자열에 =이 포함되었는지 확인
				for (int i = 0; i < NUM; i++) {
					if (user[i] == '=') {
						arr[cur_pos] = user[i + 1];
					}
				}
			}

			else if (strstr(user, "M") != NULL) {// user 문자열에 =이 포함되었는지 확인

				if (strstr(user, "f") != NULL) {
					move_front(arr);
				}
				else if (strstr(user, "n") != NULL) {
					move_end(arr);
				}
				else if (strstr(user, "P") != NULL) {
					move_prev(arr);
				}
				else if (strstr(user, "N") != NULL) {
					move_next(arr);
				}

				else {
					for (int i = 0; i < NUM; i++) {
						if (user[i] == 'M') {
							user[i] = user[i + 1];
							user[i + 1] = '\0';
						}
					}
					char c = user[0];
					int n = 0;
					n = c - '0';
					move(arr, n);
				}

			}

			else if (strstr(user, "P") != NULL) {
				prev(arr);
			}

			else if (strstr(user, "N") != NULL) {
				next(arr);
			}

			else if (strstr(user, "L") != NULL) {
				for (int i = 0; i < strlen(arr); i++) {
					if (i == cur_pos) {
						printf("(%c) ", arr[i]);
					}
					else {
						printf("%c ", arr[i]);
					}
				}
				continue;
			}

		}

		for (int i = 0; i < strlen(arr); i++) {
			if (i == cur_pos) {
				printf("(%c) ", arr[i]);
			}
			else {
				printf("%c ", arr[i]);
			}
		}
	}

	return 0;

}


void traverse_front(char* arr) {
	cur_pos = 0;
}


void traverse_rear(char* arr) {
	cur_pos = strlen(arr) - 1;
}


void prev(char* arr) {
	cur_pos -= 1;
}


void next(char* arr) {
	cur_pos += 1;
}


void delete(char* arr) {
	for (int i = cur_pos; i < strlen(arr); i++) {
		arr[i] = arr[i + 1];
	}
	if (strlen(arr) - 1 < cur_pos)
		cur_pos -= 1;
}


void get_data(char* arr) {
	printf("Return : %c\n", arr[cur_pos]);
}


void replace(char* arr) {
	char user[NUM] = { '\0' };
	for (int i = 0; i < NUM; i++) {
		if (user[i] == '=') {
			arr[cur_pos] = user[i + 1];
		}
	}
}


void empty(char* arr) {
	for (int i = 0; i < strlen(arr); i++)
		arr[i] = '\0';
	printf("empty array");
	cur_pos = -1;
}


void move(char* arr, int position) {
	if (position < cur_pos) {
		char a;
		a = arr[cur_pos];
		for (int i = cur_pos; i > position; i--) {
			arr[i] = arr[i - 1];
		}
		arr[position] = a;
		cur_pos = position;
	}
	else if (position > cur_pos) {
		char a;
		a = arr[cur_pos];
		for (int i = cur_pos; i < position + 1; i++) {
			arr[i] = arr[i + 1];
		}
		arr[position] = a;
		cur_pos = position;
	}
	else
		printf("현재 위치입니다.");
}


void move_front(char* arr) {
	char a;
	a = arr[cur_pos];
	for (int i = cur_pos; i > 0; i--) {
		arr[i] = arr[i - 1];
	}
	arr[0] = a;
	cur_pos = 0;
}


void move_end(char* arr) {
	char a;
	a = arr[cur_pos];
	for (int i = cur_pos; i < strlen(arr) + 1; i++) {
		arr[i] = arr[i + 1];
	}
	arr[strlen(arr)] = a;
	cur_pos = strlen(arr) - 1;
}


void move_prev(char* arr) {
	char a;
	a = arr[cur_pos];
	arr[cur_pos] = arr[cur_pos - 1];
	arr[cur_pos - 1] = a;
	cur_pos -= 1;
}


void move_next(char* arr) {
	char a;
	a = arr[cur_pos];
	arr[cur_pos] = arr[cur_pos + 1];
	arr[cur_pos + 1] = a;
	cur_pos += 1;
}

void find(char* arr, int position) {
	printf("검색한 인덱스의 값: %c ", arr[position]);

}


void odd(char* arr) {
	printf("홀수 인덱스: ");
	for (int i = 0; i < strlen(arr); i++) {
		if (i % 2 == 1) {
			printf("%c ", arr[i]);
		}
	}
}

void even(char* arr) {
	printf("짝수 인덱스(+0): ");
	for (int i = 0; i < strlen(arr); i++) {
		if ((i + 2) % 2 == 0) {
			printf("%c ", arr[i]);
		}
	}
}


void help() {
	for (int i = 0; i < 15; i++) {
		printf("-");
	}
	printf("H E L P");
	for (int i = 0; i < 15; i++) {
		printf("-");
	}
	printf("\n%-22s %s\n", "INSERT", ": +(data)");
	printf("%-22s %s\n", "DELETE", ": -");
	printf("%-22s %s\n", "DELETE LAST", ": > -");
	printf("%-22s %s\n", "TRAVERSE_FRONT", ": <");
	printf("%-22s %s\n", "TRAVERSE_REAR", ": >");
	printf("%-22s %s\n", "GET_DATA", ": @");
	printf("%-22s %s\n", "REPLACE", ": =(data)");
	printf("%-22s %s\n", "EMPTY", ": E");
	printf("%-22s %s\n", "MOVE", ": M(position)");
	printf("%-22s %s\n", "MOVE FRONT", ": Mf");
	printf("%-22s %s\n", "MOVE END", ": Mn");
	printf("%-22s %s\n", "MOVE PREV", ": MP");
	printf("%-22s %s\n", "MOVE NEXT", ": MN");
	printf("%-22s %s\n", "PRINT", ": L");
	printf("%-22s %s\n", "PREV", ": P");
	printf("%-22s %s\n", "NEXT", ": N");
	printf("%-22s %s\n", "FIND", ": F(position)");
	printf("%-22s %s\n", "ODD", ": O");
	printf("%-22s %s\n", "EVEN", ": V");
	printf("%-22s %s\n", "HELP", ": H");
	printf("%-22s %s\n", "QUIT", ": Q");
	printf("\n");
	printf("%-22s\n", "**Spacing between commands");
	printf("%-22s\n", "**Only one character for one data");
	for (int i = 0; i < 35; i++) {
		printf("-");
	}


}