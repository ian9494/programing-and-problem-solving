// A die game simulation in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int top;
    int bottom;
    int left;
    int right;
    int front;
    int back;
} Die;

void roll_north(Die *d) {
    int temp = d->top;
    d->top = d->front;
    d->front = d->bottom;
    d->bottom = d->back;
    d->back = temp;
}

void roll_south(Die *d) {
    int temp = d->top;
    d->top = d->back;
    d->back = d->bottom;
    d->bottom = d->front;
    d->front = temp;
}

void roll_east(Die *d) {
    int temp = d->top;
    d->top = d->left;
    d->left = d->bottom;
    d->bottom = d->right;
    d->right = temp;
}

void roll_west(Die *d) {
    int temp = d->top;
    d->top = d->right;
    d->right = d->bottom;
    d->bottom = d->left;
    d->left = temp;
}

int main(void) {
    Die die; // will be initialized per test case
    char command[16];
    int n;

    while (scanf("%d", &n) == 1 && n != 0) { // Number of commands
        // Initial die configuration: top=1, bottom=6, west=3, east=4, south=5, north=2
        die.top = 1;
        die.bottom = 6;
        die.left = 3;   // west
        die.right = 4;  // east
        die.front = 5;  // south
        die.back = 2;   // north
        for (int i = 0; i < n; i++) {
            if (scanf("%15s", command) != 1) break;
            if (strcmp(command, "north") == 0) {
                roll_north(&die);
            } else if (strcmp(command, "south") == 0) {
                roll_south(&die);
            } else if (strcmp(command, "east") == 0) {
                roll_east(&die);
            } else if (strcmp(command, "west") == 0) {
                roll_west(&die);
            }
        }
        printf("%d\n", die.top);
    }
    
    return 0;
}