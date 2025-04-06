/*
	Aadavn Nimalthas
	April 5th, 2025

	newFunctions.c - Two C functions where findStats() calculates stats for linked list and 
 			 reverseList() reverses the linked list in place
*/

Stats* findStats(ListNode* start) {
	Stats* statsp = (Stats*)malloc(sizeof(Stats));
	if (statsp == NULL) {
		fprintf(stderr, "Memory allocation failed for Stats structure.\n");
		return NULL;
	}

	statsp->count = 0;
	statsp->sum = 0;
	statsp->average = 0.0;
	statsp->minimum = 0;
	statsp->maximum = 0;

	if (start == NULL) {
		return statsp;
	}

	int count = 0;
	int sum = 0;
	int min, max;

	min = start->value;
	max = start->value;

	ListNode* currentp = start;
	while (currentp != NULL) {
		count++;
		sum += currentp->value;

		if (currentp->value < min) min = currentp->value;
		if (currentp->value > max) max = currentp->value;

		currentp = currentp->next;
	}

	statsp->count = count;
	statsp->sum = sum;
	statsp->average = (double)sum / count;
	statsp->minimum = min;
	statsp->maximum = max;

	return statsp;
}

void reverseList(LinkedList* list) {
	if (list == NULL || list->head == NULL) {
		return;
	}

	ListNode* prevp = NULL;
	ListNode* currentp = list->head;
	ListNode* nextp = NULL;

	while (currentp != NULL) {
		nextp = currentp->next;
		currentp->nextp = prevp;
		prevp = currentp;
		currentp = nextp;
	}

	list->head = prevp;
}
