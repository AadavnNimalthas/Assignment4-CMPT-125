/*
	Aadavn Nimalthas
	April 5th, 2025

	newFunctions.c - Two C functions where findStats() calculates stats for linked list and 
 			 reverseList() reverses the linked list in place
*/

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
