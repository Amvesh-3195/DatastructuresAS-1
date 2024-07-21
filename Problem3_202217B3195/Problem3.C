#include <stdio.h>
#define MAX 100 // Define maximum size of the stack
int stack[MAX], choice, n, top = -1, x, i;
void push(void);
void pop(void);
void display(void);
int main() {
    // top is initialized to -1 indicating an empty stack
    printf("\nEnter the size of STACK[MAX=100]: ");
    scanf("%d", &n);
    if (n > MAX) {
        printf("Size exceeds maximum limit of %d.\n", MAX);
        return 1; // Exit the program if size is invalid
    }
    printf("\n\tSTACK OPERATIONS USING ARRAY");
    printf("\n\t----------------------------");
    printf("\n\t1. PUSH\n\t2. POP\n\t3. DISPLAY\n\t4. EXIT");
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n\tEXIT POINT");
                break;
            default:
                printf("\n\tPlease enter a valid choice (1/2/3/4)");
        }
    } while (choice != 4);
    return 0;
}
void push() {
    if (top >= n - 1) {
        printf("\n\tSTACK is full (overflow)");
    } else {
        printf("Enter a value to be pushed: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}
void pop() {
    if (top <= -1) {
        printf("\n\tSTACK is empty (underflow)");
    } else {
        printf("\n\tThe popped element is %d", stack[top]);
        top--;
    }
}
void display() {
    if (top >= 0) {
        printf("\nThe elements in the STACK:\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    } else {
        printf("\nThe STACK is empty");
    }
}
