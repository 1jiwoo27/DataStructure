#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#pragma warning(disable:4996)

#define NUM 30

typedef struct TreeNode {
	struct TreeNode* parent;
	struct TreeNode* left;
	struct TreeNode* right;
	char data;
} Node;

void General_Tree();
void Binary_Tree();


//일반 트리 함수
Node* new_node(char data);
Node* n_find;
void find_preorder(Node* self, char f_data);
Node* find_node(Node* self, char data);
Node* find(Node* self, char data);
void insert_node(Node* self, char p_data, char c_data);
void get_sibling(Node* self, char data);
void print(Node* self);
void get_parent(Node* self, char data);
void get_child(Node* self, char data);
void level_of_node(Node* self, char data);
void level_of_tree(Node* self);
void delete_node(Node* self, char data);
void get_ancestors(Node* self, char data);
void get_descendants(Node* self, char data);
int degree(Node* self);
void degree_of_node(Node* self, char data);
void degree_of_tree(Node* self);
int count_node(Node* self);
void insert_sibling(Node* self, char data, char s_data);
Node* join_trees(char n_data, Node* tree1, Node* tree2);
void clear(Node* self);



//이진 트리 추가 함수
void insert_node2(Node* self, char p_data, char c_data);
void insert_sibling2(Node* self, char data, char s_data);
void get_child2(Node* self, char data);
void level_of_tree2(Node* self);
void get_sibling2(Node* self, char data);
void delete_node2(Node* self, char data);
void get_descendants2(Node* self, char data);
int degree2(Node* self);
void degree_of_node2(Node* self, char data);
void degree_of_tree2(Node* self);



//메인 함수
int main(void) {

	int choice;

	for (int i = 0; i < 5; i++) {
		printf("-");
	}
	printf("Type of Tree");
	for (int i = 0; i < 5; i++) {
		printf("-");
	}
	printf("\n%-22s\n", "1. General Tree");
	printf("%-22s\n", "2. Binary Tree");
	printf("\nTree Type: ");
	scanf("%d", &choice);
	getchar();
	for (int i = 0; i < 22; i++) {
		printf("-");
	}
	printf("\n");
	
	if (choice == 1) {
		General_Tree();
	}
	else if (choice == 2) {
		Binary_Tree();
	}
	/*else {
		printf("Choose Again");
	}*/

	return 0;
}

void General_Tree() {

	char user[NUM];
	int index, p_data, cnt, sib;
	Node* my_tree=NULL;
	Node* t=new_node('-');

	while (1) {

		printf(" >> ");
		gets(user);

		int userlen = strlen(user);

		for (int i = 0; i < userlen; i++) {

			if (user[i] == '+') {
				if (user[i + 2] == NULL) {
					my_tree = new_node(user[i + 1]);
				}
				else if (user[i + 2] == '(')
				{
					p_data = i + 1;
					index = i + 3;
					if (user[i + 4] != ',') {
						insert_node(my_tree, user[i + 1], user[i + 3]);
					}
					else {
						while (1) {
							if (user[index] == ')') {
								break;
							}
							else if (user[index] != ',') {
								insert_node(my_tree, user[p_data], user[index]);
							}
							index++;
						}
					}
				}
				break;
			}

			else if (user[i] == 'S') {
				get_sibling(my_tree, user[i + 2]);
				break;
			}

			else if (user[i] == 'T') {
				print(my_tree);
				break;
			}

			else if (user[i] == 'P') {
				get_parent(my_tree, user[i + 2]);
				break;
			}

			else if (user[i] == 'C') {
				get_child(my_tree, user[i + 2]);
				break;
			}

			else if (user[i] == 'L') {
				if (user[i + 2] != NULL) {
					level_of_node(my_tree, user[i + 2]);
				}
				else {
					level_of_tree(my_tree);
				}
				break;
			}

			else if (user[i] == '-') {
				delete_node(my_tree, user[i + 1]);
				break;
			}

			else if (user[i] == 'A') {
				get_ancestors(my_tree, user[i + 2]);
				break;
			}

			else if (user[i] == 'D') {
				get_descendants(my_tree, user[i + 2]);
				break;
			}

			else if (user[i] == 'G') {
				if (user[i + 2] != NULL) {
					degree_of_node(my_tree, user[i + 2]);
				}
				else {
					degree_of_tree(my_tree);
				}
				break;
			}

			else if (user[i] == '#') {
				cnt=count_node(my_tree);
				printf("%d", cnt);
				break;
			}

			else if (user[i] == '=') {
				if (user[i + 1] == '+') {
					sib = i + 2;
					index = i + 4;
					if (user[i + 5] != ',') {
						insert_sibling(my_tree, user[i + 2], user[i + 4]);
					}
					else {
						while (1) {
							if (user[index] == ')') {
								break;
							}
							else if (user[index] != ',') {
								insert_sibling(my_tree, user[sib], user[index]);
							}
							index++;
						}
					}
				}
				break;
			}

			else if (user[i] == 'J') {
				my_tree=join_trees(user[i+2], my_tree, t);
				break;
			}

			else if (user[i] == 'K') {
				clear(my_tree);
				printf("Clear");
				break;
			}

			else if (user[i] == 'Q') {
				printf("Quit");
				break;
			}


		}
		if (user[0] == 'S') {}
		else if (user[0] == 'T') {}
		else if (user[0] == 'P') {}
		else if (user[0] == 'C') {}
		else if (user[0] == 'L') {}
		else if (user[0] == 'A') {}
		else if (user[0] == 'D') {}
		else if (user[0] == 'G') {}
		else if (user[0] == '#') {}
		else if (user[0] == 'K') {}
		else if (user[0] == 'Q') {
			break;
		}
		else {
			print(my_tree);
		}
		printf("\n");
	}
	return 0;
}


void Binary_Tree() {

	char user[NUM];
	int index, p_data, cnt, sib;
	Node* my_tree=NULL;
	Node* t = new_node('-');

	while (1) {

		printf(" >> ");
		gets(user);

		int userlen = strlen(user);

		for (int i = 0; i < userlen; i++) {

			if (user[i] == '+') {
				if (user[i + 2] == NULL) {
					my_tree = new_node(user[i + 1]);
				}
				else if (user[i + 2] == '(')
				{
					p_data = i + 1;
					index = i + 3;
					if (user[i + 4] != ',') {
						insert_node2(my_tree, user[i + 1], user[i + 3]);
					}
					else {
						while (1) {
							if (user[index] == ')') {
								break;
							}
							else if (user[index] != ',') {
								insert_node2(my_tree, user[p_data], user[index]);
							}
							index++;
						}
					}
				}
				break;
			}

			else if (user[i] == 'S') {
				get_sibling2(my_tree, user[i + 2]);
				break;
			}

			else if (user[i] == 'T') {
				print(my_tree);
				break;
			}

			else if (user[i] == 'P') {
				get_parent(my_tree, user[i + 2]);
				break;
			}

			else if (user[i] == 'C') {
				get_child2(my_tree, user[i + 2]);
				break;
			}

			else if (user[i] == 'L') {
				if (user[i + 2] != NULL) {
					level_of_node(my_tree, user[i + 2]);
				}
				else {
					level_of_tree2(my_tree);
				}
				break;
			}

			else if (user[i] == '-') {
				delete_node2(my_tree, user[i + 1]);
				break;
			}

			else if (user[i] == 'A') {
				get_ancestors(my_tree, user[i + 2]);
				break;
			}

			else if (user[i] == 'D') {
				get_descendants2(my_tree, user[i + 2]);
				break;
			}


			else if (user[i] == 'G') {
				if (user[i + 2] != NULL) {
					degree_of_node2(my_tree, user[i + 2]);
				}
				else {
					degree_of_tree2(my_tree);
				}
				break;
			}

			else if (user[i] == '#') {
				cnt = count_node(my_tree);
				printf("%d", cnt);
				break;
			}

			else if (user[i] == '=') {
				if (user[i + 1] == '+') {
					sib = i + 2;
					index = i + 4;
					if (user[i + 5] != ',') {
						insert_sibling2(my_tree, user[i + 2], user[i + 4]);
					}
					else {
						while (1) {
							if (user[index] == ')') {
								break;
							}
							else if (user[index] != ',') {
								insert_sibling2(my_tree, user[sib], user[index]);
							}
							index++;
						}
					}
				}
				break;
			}

			else if (user[i] == 'J') {
				my_tree = join_trees(user[i + 2], my_tree, t);
				break;
			}

			else if (user[i] == 'K') {
				clear(my_tree);
				printf("Clear");
				break;
			}

			else if (user[i] == 'Q') {
				printf("Quit");
				break;
			}
		}

		if (user[0] == 'S') {}
		else if (user[0] == 'T') {}
		else if (user[0] == 'P') {}
		else if (user[0] == 'C') {}
		else if (user[0] == 'L') {}
		else if (user[0] == 'A') {}
		else if (user[0] == 'D') {}
		else if (user[0] == 'G') {}
		else if (user[0] == '#') {}
		else if (user[0] == 'K') {}
		else if (user[0] == 'Q') {
			break;
		}
		else {
			print(my_tree);
		}
		printf("\n");
	}
	return 0;
}



Node* new_node(char data) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
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

Node* find_node(Node* self, char data) {
	n_find = NULL;
	return find(self, data);
}

void insert_node(Node* self, char p_data, char c_data) {
	Node* parent = find_node(self, p_data);
	if (parent == NULL) {
		printf("Error\n");
	}
	else {
		if (parent->left == NULL) { //첫 번째
			parent->left = new_node(c_data);
			parent->left->parent = parent;
		}
		else { //!첫 번째
			Node* child = parent->left;
			while (child->right != NULL) {
				child = child->right;
			}
			child->right = new_node(c_data);
			child->right->parent = parent;
		}
	}
}

void insert_node2(Node* self, char p_data, char c_data) {
	Node* parent = find_node(self, p_data);
	if (parent == NULL) {
		printf("Error\n");
	}
	else {
		if (parent->left == NULL) {
				parent->left = new_node(c_data);
				parent->left->parent = parent;
		}
		else {
			Node* child = parent->left;
			if (child->right == NULL) {
				child->right = new_node(c_data);
				child->right->parent = parent;
			}
			else {
				printf("Full\n");
			}
		}
	}
}

void get_sibling(Node* self, char data) {
	Node* find= find_node(self, data);
	Node* parent = find->parent;
	Node* child = parent->left;
	printf("{");
	while (1) {
		if (child->data != data) {
			if (child->right == NULL) {
				printf("%c", child->data);
			}
			else {
				printf("%c,", child->data);
			}
		}
		if (child->right == NULL) {
			break;
		}
		child = child->right;
	}
	printf("}");
}

void get_sibling2(Node* self, char data) {
	Node* find = find_node(self, data);
	Node* parent = find->parent;
	Node* child = parent->left;
	if (child == NULL) {
		printf("Error");
	}
	else {
		printf("{");
		if (child != find) {
			printf("%c", child->data);
		}

		if (child->right==NULL) {}
		else {
			if (child->right != find) {
				printf("%c", child->right->data);
			}
		}
		printf("}");
	}
}

void print(Node* self) {
	if (self == NULL) {}
	else {
		printf("%c", self->data);
		if (self->left != NULL) {
			printf("(");
		}
		print(self->left);
		if (self->left != NULL) {
			printf(")");
		}
		if (self->right != NULL) {
			printf(",");
		}
		print(self->right);
	}
	
}

void get_parent(Node* self, char data) {
	Node* child = find_node(self, data);
	Node* parent = child->parent;
	printf("%c", parent->data);
}

void get_child(Node* self, char data) {
	Node* parent = find_node(self, data);
	Node* child = parent->left;
	printf("{");
	while (1) {
		printf("%c", child->data);
		if (child->right == NULL) {
			break;
		}
		child = child->right;
		printf(",");
	}
	printf("}");
}

void get_child2(Node* self, char data) {
	Node* parent = find_node(self, data);
	Node* child = parent->left;
	printf("{");
	if (child == NULL) {}
	else {
		printf("%c,", child->data);
		if (child->right!=NULL) {
			printf("%c", child->right->data);
		}
		else{}
	}
	printf("}");
}

void level_of_node(Node* self, char data) {
	int level = 0;
	Node* child= find_node(self, data);
	if (child->parent == NULL) {
		level = 0;
	}
	else {
		while (child->parent != NULL) {
			level++;
			child = child->parent;
		}
	}
	printf("%d", level);
}

void level_of_tree(Node* self) {
	int level = 0;
	while (self->left != NULL) {
		level++;
		self = self->left;
	}
	printf("%d", level);
}

void level_of_tree2(Node* self) {
	int level = 0;
	while (self->left != NULL) {
		level++;
		self = self->left;
	}
	printf("%d", level);
}

void delete_node(Node* self, char data) {
	Node* delete= find_node(self, data);
	if (delete->left != NULL) {
		printf("Erorr\n");
	}
	else {
		Node* before = delete->parent->left;
		Node* after = delete->right;
		Node* parent = delete->parent;
		if (before == delete) { //맨 앞-하나만 있을 때
			if (after == NULL) {
				before = NULL;
			}
			else { //맨 앞-여러개 있을 때
				before = after;
			}
		}
		else if (after==NULL) { //맨 뒤
			before->right = NULL;
		}
		else { //가운데
			while (before->right != delete) {
				before = before->right;
			}
			printf("%c\n", before->data);
			before->right = after;
		}
		free(delete);
	}
}

void delete_node2(Node* self, char data) {
	Node* delete = find_node(self, data);
	if (delete->left != NULL) {
		printf("Erorr\n");
	}
	else {
		Node* before = delete->parent->left;
		Node* after = delete->right;
		Node* parent = delete->parent;
		if (before == delete) {
			if (delete->right != NULL) { //2개 중 앞
				before = after;
				after->right = NULL;
			}
			else { //1개만 있을 때
				before = NULL;
			}
		}
		else { //뒤
			before->right = NULL;
		}
		free(delete);
	}
}

void get_ancestors(Node* self, char data) {
	Node* child = find_node(self, data);
	while (1) {
		if (child->parent == NULL) {
			break;
		}
		printf("%c ", child->parent->data);
		child = child->parent;
	}
}

void get_descendants(Node* self, char data) { //수정
	Node* find = find_node(self, data);
	while (1) {
		if (find->left == NULL) {
			break;
		}
		else {
			find = find->left;
			printf("%c ", find->data);
			while (find->right != NULL) {
				find = find->right;
				printf("%c ", find->data);
			}
		}
	}	
}

/*void get_descendants(Node * self, char data) { //수정
	Node* parent = find_node(self, data);
	if (self == NULL) {}
	else {
		printf("%c ", self->left->data);
		get_descendants(self, self->left);
		get_descendants(self, self->right);
	}
}*/

void get_descendants2(Node* self, char data) {
	Node* find = find_node(self, data);
	while (1) {
		if (find->left == NULL) {
			break;
		}
		find = find->left;
		printf("%c ", find->data);
		if (find->right == NULL) {
			break;
		}
		printf("%c ", find->right->data);
	}
}

/*void descendants2(Node* self) {
	if (self == NULL) {}
	else {
		printf("%c ", self->data);
		if (self->left != NULL) {}
		descendants2(self->left);
		if (self->right == NULL) {}
		descendants2(self->right);
	}	
}


void get_descendants2(Node* self, char data) {
	Node* find = find_node(self, data);
	descendants2(find);
}*/


int degree(Node* self) {
	int degree =0 ;
	if (self->left != NULL) {
		self = self->left;
		degree = 1;
		while (self->right != NULL) {
			self = self->right;
			degree++;
		}
	}
	else {
		degree = 0;
	}
	return degree;
}

int degree2(Node* tree) {

}

void degree_of_node(Node* self, char data) {
	Node* find = find_node(self, data);
	int degree = 0;
	if (find->left != NULL) {
		find = find->left;
		degree = 1;
		while (find->right != NULL) {
			find = find->right;
			degree++;
		}
	}
	else {
		degree = 0;
	}
	printf("%d", degree);
}

void degree_of_node2(Node* self, char data) {
	Node* find = find_node(self, data);
	int degree = 0;
	if (find->left != NULL) {
		find = find->left;
		degree = 1;
		if (find->right != NULL) {
			degree = 2;
		}
	}
	else {
		degree = 0;
	}
	printf("%d", degree);
}

void degree_of_tree(Node* self) { //수정
	Node* find = self;
	int degree1 = 0;
	int degree2 = 0;

	degree1 = degree(find);
	degree2 = (degree2 > degree1 ? degree2 : degree1);
	
	if (self->left == NULL) {}

	degree1 = degree(find->left);
	degree2 = (degree2 > degree1 ? degree2 : degree1);

	if (self->right == NULL) {}

	degree1 = degree(find->right);
	degree2 = (degree2 > degree1 ? degree2 : degree1);

	printf("%d", degree2);
}

void degree_of_tree2(Node* self) {
	int degree = 0;

}

int count_node(Node* self) {
	int cnt = 0;
	if (self == NULL) {
		cnt = 0;
	}
	else {
		cnt=count_node(self->left)+count_node(self->right)+1;
	}
	return cnt;
}

void insert_sibling(Node* self, char data, char s_data) {
	Node* find = find_node(self, data);
	if (find == NULL) {
		printf("Error\n");
	}
	else {
		while (find->right!=NULL) {
			find = find->right;
		}
		find->right = new_node(s_data);
		find->right->parent =find->parent;
	}
}

void insert_sibling2(Node* self, char data, char s_data) {
	Node* find = find_node(self, data);
	Node* parent = find->parent;
	Node* child = parent->left;
	if (find == NULL) {
		printf("Error\n");
	}
	else {
		if (child->right != NULL) {
			printf("Full\n");
		}
		else {
			child->right = new_node(s_data);
			child->right->parent = child->parent;
		}
	}
}

Node* join_trees(char n_data, Node* tree1, Node* tree2) {
	Node* root = new_node(n_data);
	root->left = tree1;
	tree1->right = tree2;
	tree1->parent = root;
	tree2->parent = root;
	return root;
}

void clear(Node* self) {
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
}


