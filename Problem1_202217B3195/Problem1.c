#include <stdio.h>

#define MAX_SIZE 100

int list[MAX_SIZE];
int count = 0;

void insert(int data) {
  if (count == MAX_SIZE) {
    printf("List is full!\n");
    return;
  }

  if (count == 0) {
    list[count] = data;
    count++;
    return;
  }

  // Insert at the end (simplification)
  list[count] = data;
  count++;
}

void delete(int data) {
  if (count == 0) {
    printf("List is empty!\n");
    return;
  }

  int found = 0;
  int i;

  for (i = 0; i < count; i++) {
    if (list[i] == data) {
      found = 1;
      break;
    }
  }

  if (found) {
    for (int j = i; j < count - 1; j++) {
      list[j] = list[j + 1];
    }
    count--;
  } else {
    printf("Element not found!\n");
  }
}

void display() {
  if (count == 0) {
    printf("List is empty!\n");
    return;
  }

  printf("List elements: ");
  for (int i = 0; i < count; i++) {
    printf("%d ", list[i]);
  }
  printf("\n");
}

int main() {
  int choice, data;

  while (1) {
    printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter data to insert: ");
        scanf("%d", &data);
        insert(data);
        break;
      case 2:
        printf("Enter data to delete: ");
        scanf("%d", &data);
        delete(data);
        break;
      case 3:
        display();
        break;
      case 4:
        printf("Exiting...\n");
        return 0;
      default:
        printf("Invalid choice!\n");
    }
  }

  return 0;
}
