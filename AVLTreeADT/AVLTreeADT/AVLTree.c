#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#pragma warning(disable:4996)

#define NUM 30

typedef struct AVLNode {
	struct AVLNode* parent;
	struct AVLNode* left;
	struct AVLNode* right;
	int data;
	int height;
} Node;


//회전 함수
Node* left_rotate(Node* self, int new_node);
Node* right_rotate(Node* self, int new_node);
Node* LR_rotate(Node* self, int new_node);
Node* RL_rotate(Node* self, int new_node);
Node* rightchild;
Node* leftchild;

Node* n_find;
void find_preorder(Node* self, int f_data);
Node* find_n(Node* self, int data);
Node* find(Node* self, int data);

//함수
Node* new_node(int node);
int num_change(char data);
int getMax(int a, int b);
void setHeight(Node* self);
int getDifference(Node* self);
void insert_node(Node* self, int new_node);
void print(Node* self);
int balance_factor(Node* self, int node_value);
void inorder_traversal(Node* self);
void right_root_left_traversal(Node* self);
void get_min(Node* self);
void get_max(Node* self);
void find_node(Node* self, int node_value);
int height_tree(Node* self);
int height_node(Node* self, int node);
void get_right_child(Node* self, int node);
void get_left_child(Node* self, int node);
int count_node(Node* self);
void delete_node(Node* self, int node);
Node* clear(Node* self);
void help();


//메인 함수
int main(void) {

	help();

	char user[NUM];
	int result, height;
	Node* my_AVL = NULL;

	while (1) {

		printf(" >> ");
		gets(user);

		int userlen = strlen(user);

		for (int i = 0; i < userlen; i++) {

			if (user[i] == '+') {
				if (my_AVL == NULL) {
					result = num_change(user[i + 1]);
					my_AVL = new_node(result);
				}
				else
				{
					result = num_change(user[i + 1]);
					insert_node(my_AVL, result);
				}
				break;
			}

			else if (user[i] == 'P') {
				break;
			}

			else if (user[i] == 'B') {
				result = num_change(user[i + 1]);
				balance_factor(my_AVL, result);
				break;
			}

			else if (user[i] == 'I') {
				inorder_traversal(my_AVL);
				break;
			}

			else if (user[i] == 'R') {
				right_root_left_traversal(my_AVL);
				break;
			}

			else if (user[i] == 'N') {
				get_min(my_AVL);
				break;
			}

			else if (user[i] == 'X') {
				get_max(my_AVL);
				break;
			}

			else if (user[i] == 'F') {
				result = num_change(user[i + 1]);
				find_node(my_AVL, result);
				break;
			}

			else if (user[i] == 'T') {
				height = height_tree(my_AVL);
				printf(" %d", height);
				break;
			}

			else if (user[i] == 'H') {
				result = num_change(user[i+1]);
				height = height_node(my_AVL, result);
				printf(" %d", height - 2);
				break;
			}

			else if (user[i] == 'G') {
				result = num_change(user[i + 1]);
				get_right_child(my_AVL, result);
				break;
			}

			else if (user[i] == 'L') {
				result = num_change(user[i + 1]);
				get_left_child(my_AVL, result);
				break;
			}

			else if (user[i] == '#') {
				result = count_node(my_AVL);
				printf(" %d", result);
				break;
			}

			else if (user[i] == '-') {
				result = num_change(user[i + 1]);
				delete_node(my_AVL, result);
				break;
			}

			else if (user[i] == 'C') {
				my_AVL = clear(my_AVL);
				break;
			}

			else if (user[i] == 'Q') {
				break;
			}

			else if (user[i] == '?') {
				help();
				break;
			}

		}
		if (user[0] == 'I') {}
		else if (user[0] == 'R') {}
		else if (user[0] == 'N') {}
		else if (user[0] == 'X') {}
		else if (user[0] == 'F') {}
		else if (user[0] == 'B') {}
		else if (user[0] == 'T') {}
		else if (user[0] == 'H') {}
		else if (user[0] == 'L') {}
		else if (user[0] == '#') {}
		else if (user[0] == '?') {}
		else if (user[0] == 'Q') {
			break;
		}
		else {
			printf(" ");
			print(my_AVL);
		}
		printf("\n");
	}
	return 0;
}


//회전 함수
Node* left_rotate(Node* self, int new_node) {
	Node* find = find_n(self, new_node);
	Node* rightchild = find->right;
	self->right = rightchild->left;
	rightchild->left = find;
	return rightchild;
}

Node* right_rotate(Node* self, int new_node) {
	Node* find = find_n(self, new_node);
	Node* leftchild = find->left;
	find->left = leftchild->right;
	leftchild->right = find;
	return leftchild;
}

Node* LR_rotate(Node* self, int new_node) {
	Node* find = find_n(self, new_node);
	Node* leftchild = find->left;
	leftchild = left_rotate(self, leftchild);
	return right_rotate(self, find);
}

Node* RL_rotate(Node* self, int new_node) {
	Node* find = find_n(self, new_node);
	Node* rightchild = find->right;
	rightchild = right_rotate(self, rightchild);
	return left_rotate(self, find);
}

void find_preorder(Node* self, char f_data) {
	if (self == NULL) {
		return;
	}
	if (self->data == f_data) {
		n_find = self;
	}
	find_preorder(self->left, f_data);
	find_preorder(self->right, f_data);
}

Node* find(Node* self, char data) {
	find_preorder(self, data);
	return n_find;
}

Node* find_n(Node* self, int data) {
	n_find = NULL;
	return find(self, data);
}

//함수
Node* new_node(int node) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = node;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

int num_change(char data) {
	int num = data - '0';
	return num;
}

int getMax(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

void setHeight(Node* self) {
	self->height = getMax(height_node(self->left), height_node(self->right)) + 1;
}

int getDifference(Node* self) {
	if (self == NULL) {
		return 0;
	}
	Node* leftchild = self->left;
	Node* rightchild = self->right;
	return height_node(leftchild) - height_node(rightchild);
}

void insert_node(Node* self, int node) { //회전 수정
	if (node < self->data) {
		if (self->left == NULL) {
			Node* new = (Node*)malloc(sizeof(Node));
			self->left = new;
			new->data = node;
			new->parent = self;
			new->left = NULL;
			new->right = NULL;
		}
		else {
			insert_node(self->left, node);
		}

	}
	else if (node > self->data) {
		if (self->right == NULL) {
			Node* new = (Node*)malloc(sizeof(Node));
			self->right = new;
			new->data = node;
			new->parent = self;
			new->left = NULL;
			new->right = NULL;
		}
		else {
			insert_node(self->right, node);
		}
	}
	else {
		printf("중복된 값입니다.\n");
	}
}

void print(Node* self) {
	if (self != NULL) {
		printf("%d", self->data);
		if ((self->left != NULL) || (self->right != NULL)) {
			printf("(");
		}
		print(self->left);
		if ((self->left != NULL) || (self->right != NULL)) {
			printf(",");
		}
		print(self->right);
		if ((self->left != NULL) || (self->right != NULL)) {
			printf(")");
		}
	}
}

int balance_factor(Node* self, int node_value) {

}

void inorder_traversal(Node* self) {
	if (self == NULL) {}
	else {
		inorder_traversal(self->left);
		printf(" %d", self->data);
		inorder_traversal(self->right);
	}
}

void right_root_left_traversal(Node* self) {
	if (self == NULL) {}
	else {
		right_root_left_traversal(self->right);
		printf(" %d", self->data);
		right_root_left_traversal(self->left);
	}
}

void get_min(Node* self) {
	if (self == NULL) {}
	else {
		Node* min = self;
		while (min->left != NULL) {
			min = min->left;
		}
		printf(" %d", min->data);
	}
}

void get_max(Node* self) {
	if (self == NULL) {}
	else {
		Node* max = self;
		while (max->right != NULL) {
			max = max->right;
		}
		printf(" %d", max->data);
	}
}

void find_node(Node* self, int node_value) {
	Node* find = self;
	while ((find != NULL) && (find->data != node_value)) {
		if (node_value < find->data) {
			find = find->left;
		}
		else { // node_value > find->data
			find = find->right;
		}
	}
	if (find == NULL) {
		printf(" Error");
	}
	else {
		Node* find = self;
		printf(" Root");
		while (find != NULL) {
			if (node_value == find->data) {
				break;
			}
			else if (node_value < find->data) {
				printf(" > Left");
				find = find->left;
			}
			else { // node_value > find->data
				printf(" > Right");
				find = find->right;
			}
		}
	}
}

int height_tree(Node* self) {
	int left, right;
	if (self == NULL) {}
	else {
		left = height(self->left);
		right = height(self->right);

		return 1 + (left >= right ? left : right);
	}
}

int height_node(Node* self, int node) {
	Node* find = self;
	while ((find != NULL) && (find->data != node)) {
		if (node < find->data) {
			find = find->left;
		}
		else { // node > find->data
			find = find->right;
		}
	}
	if (find == NULL) {
		printf(" Error");
		return;
	}
	else {
		int height = 0;
		if (find->left != NULL) {
			find = find->left;
			height++;
			while (find->right != NULL) {
				find = find->right;
				height++;
			}
		}
		return height;
	}
}

void get_right_child(Node* self, int node) {
	Node* find = self;
	while ((find != NULL) && (find->data != node)) {
		if (node < find->data) {
			find = find->left;
		}
		else { // node > find->data
			find = find->right;
		}
	}
	if (find == NULL) {
		printf(" Error");
	}
	else {
		if (find->right != NULL) {
			printf(" %d", find->right->data);
		}
		else {
			printf(" NULL");
		}
	}
}

void get_left_child(Node* self, int node) {
	Node* find = self;
	while ((find != NULL) && (find->data != node)) {
		if (node < find->data) {
			find = find->left;
		}
		else { // node > find->data
			find = find->right;
		}
	}
	if (find == NULL) {
		printf(" Error");
	}
	else {
		if (find->left != NULL) {
			printf(" %d", find->left->data);
		}
		else {
			printf(" NULL");
		}
	}
}

int count_node(Node* self) {
	int cnt = 0;
	if (self == NULL) {
		cnt = 0;
	}
	else {
		cnt = count_node(self->left) + count_node(self->right) + 1;
	}
	return cnt;
}

void delete_node(Node* self, int node) {
	Node* delete = self;
	Node* child = NULL;
	Node* parent = NULL;
	Node* succ = NULL;
	Node* succ_parent = NULL;
	while ((delete != NULL) && (delete->data != node)) {
		parent = delete;
		if (node < delete->data) {
			delete = delete->left;
		}
		else {
			delete = delete->right;
		}
	}
	if (delete == NULL) {
		printf("Error");
	}
	if ((delete->left == NULL) && (delete->right == NULL)) { //delete가 단말노드
		if (parent != NULL) {
			if (parent->left == delete) {
				parent->left = NULL;
			}
			else { //parent->right == delete
				parent->right = NULL;
			}
		}
	}
	else if ((delete->left == NULL) || (delete->right == NULL)) { //delete 차수 1
		if (delete->right == NULL) {
			Node* child = delete->left;
		}
		else { //delete->left == NULL
			Node* child = delete->right;
		}
		if (parent != NULL) {
			if (parent->left == delete) {
				parent->left = child;
			}
			else { //parent->right == delete
				parent->right = child;
			}
		}
	}
	else { //delete 차수 2
		Node* succ_parent = delete;
		Node* succ = delete->left;
		while (succ->right != NULL) {
			succ_parent = succ;
			succ = succ->right;
		}
		if (succ_parent->left == succ) {
			succ_parent->left = succ->left;
		}
		else {
			succ_parent->right = succ->left;
		}
		delete->data = succ->data;
		delete = succ;
	}
	free(delete);
}

Node* clear(Node* self) {
	if (self == NULL) {}
	else {
		if (self->left != NULL) {
			clear(self->left);
		}
		if (self->right != NULL) {
			clear(self->right);
		}
		self->left = NULL;
		self->right = NULL;
		free(self);
	}
	return self;
}

void help() {
	for (int i = 0; i < 15; i++) {
		printf("-");
	}
	printf("H E L P");
	for (int i = 0; i < 15; i++) {
		printf("-");
	}
	printf("\n%-25s %s\n", "INSERT_NODE", ": +(data)");
	printf("%-25s %s\n", "INORDER_TRAVERSAL", ": I");
	printf("%-25s %s\n", "RIGHT_ROOT_LEFT_TRAVERSAL", ": R");
	printf("%-25s %s\n", "GET_MIN", ": N");
	printf("%-25s %s\n", "GET_MAX", ": X");
	printf("%-25s %s\n", "FIND_NODE", ": F(data)");
	printf("%-25s %s\n", "DELETE_NODE", ": -(data)");
	printf("%-25s %s\n", "HEIGHT", ": H");
	printf("%-25s %s\n", "GET_RIGHT_CHILD", ": G((data))");
	printf("%-25s %s\n", "GET_LEFT_CHILD", ": L((data))");
	printf("%-25s %s\n", "COUNT_NODE", ": #");
	printf("%-25s %s\n", "PRINT", ": P");
	printf("%-25s %s\n", "IS_FULL", ": F");
	printf("%-25s %s\n", "IS_EMPTY", ": E");
	printf("%-25s %s\n", "CLEAR", ": C");
	printf("%-25s %s\n", "HELP", ": ?");
	printf("%-25s %s\n", "QUIT", ": Q");
	printf("\n");
	printf("%-25s\n", "**Spacing between commands");
	printf("%-25s\n", "**Only one character for one data");
	for (int i = 0; i < 35; i++) {
		printf("-");
	}
	printf("\n");
}