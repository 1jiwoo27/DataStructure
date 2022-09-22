#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#pragma warning(disable:4996)

#define NUM 30

typedef struct TreeNode {
	struct TreeNode* parent;
	//struct TreeNode* child;
	struct TreeNode* left;
	struct TreeNode* right;
	char data;
} Node;

Node* new_node(char data) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->parent = NULL;
	//new_node->child = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

Node* n_find;

void find_init() {
	n_find = NULL;
}

void find_preorder(Node* tree, char f_data) {
	if (tree == NULL) {
		return;
	}
	if (tree->data == f_data) {
		n_find = tree;
	}
	find_preorder(tree->left, f_data);
	find_preorder(tree->right, f_data);
}

Node* find(Node* tree, char data) {
	find_preorder(tree, data);
	return n_find;
}

Node* find_node(Node* tree, char data) {
	find_init();
	return find(tree, data);
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


void transfer(Node* self) {
	Node* child = self->left;
	while (child->right != NULL) {

		child->right = child->left->right;
		child = child->right;
	}
	transfer(self->left);
	transfer(self->right);
}

int main(void) {
	char user[NUM];
	int index, p_data;
	Node* my_tree = NULL;

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

			else if (user[i] == 'T') {
				transfer(my_tree);
				break;
			}

			else if (user[i] == 'Q') {
				printf("Quit");
				break;
			}

		if (user[0] == 'Q') {
			break;
		}
		else {
			print(my_tree);
		}
		printf("\n");
		}

	}
	return 0;
}