#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ListNode {
	int value;
	struct ListNode* next;
}ListNode;

typedef struct LinkedList {
	struct ListNode* head;
}LinkedList;

typedef struct Stats {
	int count;
	int sum;
	double average;
	int minimum;
	int maximum;
}Stats;


LinkedList* createLinkedList();
void freeLinkedList(LinkedList* list);
ListNode* createNode(int val);
Stats* createStats();
void displayList(const LinkedList* list);
void printStats(Stats* myListStats);
void insertListNode(LinkedList* list, int val);
void appendListNode(LinkedList* list, int val);
Stats* findStats(ListNode* start);
void reverseList(LinkedList* list);

int main() {

	/* Create a new linked list */
	LinkedList* list = NULL;
	Stats *testStats = NULL;

	list = createLinkedList();
	if (list == NULL) {
		printf("Failed to create linked list.\n");
		return 1;
	}

	/* Insert some nodes into the linked list */
	insertListNode(list, 88);
	insertListNode(list, 23);
	insertListNode(list, 36);
	insertListNode(list, 17);
	insertListNode(list, 2);
	insertListNode(list, 63);
	insertListNode(list, 28);
	printf("linked list: \n");
	displayList(list);

	testStats = createStats();
	if (testStats == NULL) {
		printf("Failed to create Stats.\n");
                free( list );
		return 1;
	}
	testStats = findStats(list->head);
	printStats(testStats);

	printf("Original List\n");
	displayList(list);
	reverseList(list);
	printf("Reversed List\n");
	displayList(list);
	/* Free memory allocated for the linked list */
	freeLinkedList(list);
	free(testStats);
	printf("\n\n");

	list = createLinkedList();
	if (list == NULL) {
		printf("Failed to create linked list.\n");
		return 1;
	}

	appendListNode(list, 88);
	appendListNode(list, 83);
	appendListNode(list, 45);
	appendListNode(list, 27);
	appendListNode(list, 91);
	appendListNode(list, 76);
	appendListNode(list, 62);
	appendListNode(list, 97);
	printf("linked list: \n");
	displayList(list);

	testStats = createStats();
	if (testStats == NULL) {
		printf("Failed to create Stats.\n");
        free( list );
		return 2;
	}
	testStats = findStats(list->head);
	printStats(testStats);
	printf("Original List\n");
	displayList(list);
	reverseList(list);
	printf("Reversed List\n");
	displayList(list);
	/* Free memory allocated for the linked list */
	freeLinkedList(list);
	free(testStats);
	return 0;
}


/* Function to append a new node with the given value to the end of the linked list */
void appendListNode(LinkedList* list, int val) {
	ListNode* newListNode = NULL;
	newListNode = createNode(val);
	if (newListNode) {

		/* If the list is empty, make the new node the head of the list */
		if (list->head == NULL) {
			list->head = newListNode;
			return;
		}

		/* Otherwise, traverse the list to find the last node */
		ListNode* current = list->head;
		while (current->next != NULL) {
			current = current->next;
		}

		/* Insert the new node after the last node */
		current->next = newListNode;
	}
	else
	{
		printf("Memory allocation failed.\n");
	}
}

/* Function to insert a new node with the given value in decending order */
void insertListNode(LinkedList* list, int val) {
	ListNode *newListNode;
	newListNode = createNode(val);
	if (newListNode)
	{
		/* If the list is empty or the new node's value is greater than the value of the head node,
		   insert the new node at the front. */
		if (list->head == NULL || val > list->head->value)
		{
			newListNode->next = list->head;
			list->head = newListNode;
			return;
		}

		/* Otherwise, traverse the list to find the correct position to insert the new node. */
		ListNode* current = list->head;
		while (current->next != NULL && current->next->value > val)
		{
			current = current->next;
		}

		/* Insert the new node after the current node. */
		newListNode->next = current->next;
		current->next = newListNode;
	}
	else {
		printf("Memory allocation failed.\n");
	}
}


/* Function to initialize a new linked list */
LinkedList* createLinkedList() {
	LinkedList* list = NULL;
	list = (LinkedList*)malloc(sizeof(LinkedList));
	if (list != NULL) {
		list->head = NULL;
	}
	return list;
}

/* Function to free memory allocated for the linked list */
void freeLinkedList(struct LinkedList* list) {
	struct ListNode* current = list->head;
	while (current != NULL) {
		struct ListNode* temp = current;
		current = current->next;
		free(temp);
	}
	free(list);
}


ListNode * createNode(int value)
{
	ListNode* newListNode = NULL;
	newListNode = (ListNode*)malloc(sizeof(ListNode));
	if (newListNode != NULL) {
		newListNode->value = value;
		newListNode->next = NULL;
	}
	return newListNode;
}

Stats * createStats()
{
	Stats* newStats = NULL;
	newStats = (Stats*)malloc(sizeof(Stats));
	if (newStats != NULL) {
		newStats->count = 0;
		newStats->sum = 0;
		newStats->average = 0;
	}
	return newStats;
}


void displayList(const struct LinkedList* list) {
	const struct ListNode* current = NULL;
	current = list->head;
	while (current != NULL) {
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}


void printStats(Stats* myListStats) {
	printf("\nStats for Linked List\n");
	printf("	count   = %d\n", myListStats->count);
	printf("	sum     = %d\n", myListStats->sum);
	printf("	average = %lf\n", myListStats->average);
	printf("	minimum = %d\n", myListStats->minimum);
	printf("	maximum = %d\n", myListStats->maximum);
	printf("\n");
}

Stats* findStats(ListNode* start) {
	Stats* stats = (Stats*)malloc(sizeof(Stats));
	if (stats == NULL) {
		fprintf(stderr, "Memory allocation failed for Stats structure.\n");
		return NULL;
	}

	stats->count = 0;
	stats->sum = 0;
	stats->average = 0.0;
	stats->minimum = 0;
	stats->maximum = 0;

	if (start == NULL) {
		return stats;
	}

	int count = 0;
	int sum = 0;
	int min, max;

	min = start->value;
	max = start->value;

	ListNode* current = start;
	while (current != NULL) {
		count++;
		sum += current->value;

		if (current->value < min) min = current->value;
		if (current->value > max) max = current->value;

		current = current->next;
	}

	stats->count = count;
	stats->sum = sum;
	stats->average = (double)sum / count;
	stats->minimum = min;
	stats->maximum = max;

	return stats;
}

void reverseList(LinkedList* list) {
	if (list == NULL || list->head == NULL) {
		return;
	}

	ListNode* prev = NULL;
	ListNode* current = list->head;
	ListNode* next = NULL;

	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	list->head = prev;
}
