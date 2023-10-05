#include <stdio.h>
#include <stdlib.h>

int* list;
int size;

void add(int item) {
	size += 1;
	list = (int*) realloc(list, sizeof(int) * (size));
	list[size - 2] = item;
}

void show() {
	int i;
	printf("\n");
	for (i = 0; i < size - 1; i++) {
		printf_s("%d ", list[i]);
	}
}

void insert(int index, int item) {
	if (index >= size) {
		printf_s("\ninvalid index\n");
		return;
	}
	list = (int*)realloc(list, sizeof(int) * (size));
	int i;
	for (i = size - 2; i >= index; i--) {
		list[i + 1] = list[i];
	}
	list[index] = item;
	size += 1;
}

void showSize() {
	printf_s("\nsize: %d", size - 1);
}

void set(int index, int item) {
	if (index >= size - 1) {
		printf_s("\ninvalid index\n");
		return;
	}
	list[index] = item;
}

void removeFromList(int index) {
	if (index >= size - 1) {
		printf_s("\ninvalid index\n");
		return;
	}
	int i;
	for (i = index; i < size - 2; i++) {
		list[i] = list[i + 1];
	}
	size -= 1;
}

void get(int index) {
	if (index >= size - 1) {
		printf_s("\ninvalid index\n");
		return;
	}

	printf_s("\nlist[%d]: %d", index, list[index]);
}

int main() {
	list = (int*) malloc(list, sizeof(int));
	size = 1;

	add(4);
	add(5);
	add(6);
	add(7);
	add(8);

	show();
	
	insert(1, 10);
	insert(1, 20);

	set(6, 100);

	removeFromList(2); // нельзя просто "remove" (

	show();

	showSize();

	get(5);


	free(list);
	return 0;
}