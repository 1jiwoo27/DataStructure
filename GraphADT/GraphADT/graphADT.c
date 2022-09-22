#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#pragma warning(disable:4996)

#define NUM 30

//노드
typedef struct GraphNode {
	struct GraphNode* link;
	char vertex;
} Node;

//노드 저장 리스트
typedef struct GraphType {
	int vertex_num;
	int edge_num;
	Node* adj_list[NUM];
} Graph;

//함수
Graph* create(Graph* graph);
void __init__(Graph* graph);
void insert_vertex(Graph* graph, char vertex);
Node* find_vertex(Graph* graph, char vertex);
void add_edge(Graph* graph, char vertex1, char vertex2);
void print(Graph* graph);
void degree_of_vertex(Graph* graph, char vertex);
void is_connected(Graph* graph);
void is_empty(Graph* graph);
void adjacent(Graph* graph, char vertex);
void delete_vertex(Graph* graph, char vertex);
void path_exist(Graph* graph, char vertex1, char vertex2);
void num_of_vertex(Graph* graph);
void num_of_edge(Graph* graph);
void delete_edge(Graph* graph, char vertex1, char vertex2);
void rename_vertex(Graph* graph, char old_v, char new_v);
void clear(Graph* graph);
void help();

//void DFS(Graph* graph, char start_vertex);
//void init_visitied();
//int find_vertex_index(Graph* graph, char vertex);

//main 함수
int main() {

	char user[NUM];
	Graph* my_graph;

	//__init__(&my_list); //LinkedList 초기화

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

			if (user[i] == 'G') {
				my_graph = create(my_graph);
			}

			else if (user[i] == '+') {
				insert_vertex(my_graph, user[i + 1]);
			}

			else if (user[i] == 'E') {
				add_edge(my_graph, user[i + 2], user[i + 4]);
			}

			else if (user[i] == 'L') {
				continue;
			}

			else if (user[i] == 'V') {
				degree_of_vertex(my_graph, user[i+2]);
			}

			else if (user[i] == 'C') {
				is_connected(my_graph);
			}

			else if (user[i] == 'N') {
				is_empty(my_graph);
			}

			else if (user[i] == 'A') {
				adjacent(my_graph, user[i + 2]);
			}

			else if (user[i] == '-') {
				delete_vertex(my_graph, user[i + 1]);
			}

			else if (user[i] == 'P') {
				path_exist(my_graph, user[i+2], user[i+4]);
			}

			else if (user[i] == 'X') {
				num_of_vertex(my_graph);
			}

			else if (user[i] == 'H') {
				num_of_edge(my_graph);
			}

			else if (user[i] == 'D') {
				delete_edge(my_graph, user[i+2], user[i+4]);
			}

			else if (user[i] == 'R') {
				rename_vertex(my_graph, user[i + 2], user[i + 4]);
			}
			
			else if (user[i] == 'K') {
				clear(my_graph);
			}

			else if (user[i] == 'H') {
				help();
			}

			else if (user[i] == 'Q') {
				printf(" QUIT");
				break;
			}
		}


		if (user[0] == 'V') {}
		else if (user[0] == 'C') {}
		else if (user[0] == 'N') {}
		else if (user[0] == 'A') {}
		else if (user[0] == 'P') {}
		else if (user[0] == 'X') {}
		else if (user[0] == 'H') {}
		else if (user[0] == 'Q') {
			break;
		}
		else {
			printf("(");
			print(my_graph);
			printf(")");
		}
		printf("\n");
	}
	return 0;
}


Graph* create(Graph* graph) {

}

void __init__(Graph* graph) {

}

void insert_vertex(Graph* graph, char vertex) {

}

Node* find_vertex(Graph* graph, char vertex) {

}

void add_edge(Graph* graph, char vertex1, char vertex2) {

}

void print(Graph* graph) {

}

void degree_of_vertex(Graph* graph, char vertex) {

}

void is_connected(Graph* graph) {

}

void is_empty(Graph* graph) {

}

void adjacent(Graph* graph, char vertex) {

}

void delete_vertex(Graph* graph, char vertex) {

}

void path_exist(Graph* graph, char vertex1, char vertex2) {

}

void num_of_vertex(Graph* graph) {

}

void num_of_edge(Graph* graph) {

}

void delete_edge(Graph* graph, char vertex1, char vertex2) {

}

void rename_vertex(Graph* graph, char old_v, char new_v) {

}

void clear(Graph* graph) {

}

void help() {
	for (int i = 0; i < 15; i++) {
		printf("-");
	}
	printf("H E L P");
	for (int i = 0; i < 15; i++) {
		printf("-");
	}
	printf("\n%-22s %s\n", "CREATE", ": G");
	printf("%-22s %s\n", "INSERT_VERTEX", ": +(data)");
	printf("%-22s %s\n", "ADD_EDGE", ": E(data1, data2)");
	printf("%-22s %s\n", "DEGREE_OF_VERTEX", ": V(data)");
	printf("%-22s %s\n", "IS_CONNECTED", ": C");
	printf("%-22s %s\n", "IS_EMPTY", ": N");
	printf("%-22s %s\n", "ADJACENT", ": A(data)");
	printf("%-22s %s\n", "DELETE_VERTEX", ": -(data)");
	printf("%-22s %s\n", "PATH_EXIST", ": P(data1, data2)");
	printf("%-22s %s\n", "NUM_OF_VERTEX", ": X");
	printf("%-22s %s\n", "NUM_OF_EDGE", ": H");
	printf("%-22s %s\n", "DELETE_EDGE", ": D(data1, data2)");
	printf("%-22s %s\n", "RENAME_VERTEX", ": R(data1, data2)");
	printf("%-22s %s\n", "CLEAR", ": K");
	printf("%-22s %s\n", "PRINT", ": L");
	printf("%-22s %s\n", "HELP", ": H");
	printf("%-22s %s\n", "QUIT", ": Q");
	printf("\n");
	printf("%-22s\n", "**Spacing between commands");
	printf("%-22s\n", "**Only one character for one data");

	for (int i = 0; i < 35; i++) {
		printf("-");
	}
}