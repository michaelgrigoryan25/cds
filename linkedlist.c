#include <stdio.h>
#include <stdlib.h>

struct ListNode {
		int data;
		struct ListNode* next;
};

struct ListNode* ll_create(int data) {
		struct ListNode* node = malloc(sizeof(struct ListNode));
		node->data = data;
		node->next = NULL;
		return node;
}

struct ListNode* ll_insert(struct ListNode* head, int data) {
		struct ListNode* node = ll_create(data);
		if (head == NULL) {
				head = node;
				return head;
		} else {
				node->next = head;
				return node;
		}
}

void ll_display(struct ListNode* node) {
		while (node != NULL) {
				printf("%d->", node->data);
				node = node->next;
		}

		printf("\n");
}

struct ListNode* ll_insert_at(struct ListNode* node, int data, int index) {
		int i = 0;
		struct ListNode* curr = node;
		struct ListNode* prev = node;

		while (curr != NULL) {
				if (i == index) {
						prev->next = ll_create(data);
						prev->next->next = curr;
						break;
				}

				prev = curr;
				curr = curr->next;
				i++;
		}

		return node;
}

int ll_delete(struct ListNode* node, int data) {
		struct ListNode* curr = node;
		struct ListNode* prev = curr;

		while (curr != NULL) {
				if (curr->data == data) {
						prev->next = curr->next;
						return 1;
				}

				prev = curr;
				curr = curr->next;
		}

		return 0;
}

int ll_delete_at(struct ListNode* node, int index) {
		int i = 0;
		struct ListNode* curr = node;
		struct ListNode* prev = node;

		while (curr != NULL) {
				if (i == index) {
						prev->next = curr->next;
						return 1;
				}

				prev = curr;
				curr = curr->next;
				i++;
		}

		return 0;
}

void ll_free(struct ListNode* node) {
		free(node);
}

void menu() {
		int n = 0;
		struct ListNode* node = NULL;
		while (n != 7) {
				n = 0;
				printf("\t1. Create a node.\n");
				printf("\t2. Create a node at index.\n");
				printf("\t3. Delete a node.\n");
				printf("\t4. Delete a node at index.\n");
				printf("\t5. Display the node.\n");
				printf("\t6. Free the node.\n");
				printf("\t7. Quit.\n");

				printf("Please enter an option: ");
				scanf("%d", &n);

				switch (n) {
						case 1:
								printf("Enter the number: ");
								scanf("%d", &n);
								node = ll_insert(node, n);
								printf("Node created.\n");
								break;
						case 2:
								if (node == NULL) {
										printf("You have to initialize a node first.\n");
										break;
								}

								printf("Enter the number: ");
								scanf("%d", &n);

								int i;
								printf("Enter the index: ");
								scanf("%d", &i);
								node = ll_insert_at(node, n, i);
								printf("Node created.\n");
								break;
						case 3:
								if (node == NULL) {
										printf("You have to initialize a node first.\n");
										break;
								}

								printf("Enter the number: ");
								scanf("%d", &n);

								ll_delete(node, n);
								printf("Node deleted.\n");
								break;
						case 4:
								if (node == NULL) {
										printf("You have to initialize a node first.\n");
										break;
								}

								printf("Enter the index of the node: ");
								scanf("%d", &n);

								ll_delete_at(node, n);
								printf("Node deleted.\n");
								break;
						case 5: 
								ll_display(node);
								break;
						case 6:
								printf("Cleared.\n");
								ll_free(node);
								break;
						case 7:
								n = 7;
								break;
				}

				n = -1;
		}
}

int main(int argc, char** argv) {
		menu();
		return 0;
}

