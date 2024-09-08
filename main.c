#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint32_t;

struct box {
    int used;
    char stuff[64];
};

struct box boxes[100] = {0};

void print_box(uint32_t i) {
    printf("Box %d: %s\n", i, boxes[i].stuff);
    return;
}

void edit_box(uint32_t i) {
    if (boxes[i].used == 0) {
        printf("What's in the box?\n");
        scanf("%64s", boxes[i].stuff);
        boxes[i].used = 1;
    }
    else {
        printf("The box is already occupied.\n");
    }
    return;
}

int read_int(uint32_t *out) {
    uint32_t i = 0;
    int n_parsed = scanf("%u", &i);
    if (n_parsed > 0) {
        *out = i;
    }
    return n_parsed;
}

void print_menu() {
    printf("Inventory simulator 1.0\n");
    printf("\tp: print a box\n");
    printf("\te: edit a box\n");
    printf("\tq: quit\n");
}

void main(int argc, char **argv) {
    char selection = 'a';

    print_menu();

    int box = 0;
    while (selection != 'q') {
        selection = getchar();

        if (selection == '\n') {
            continue;
        }
        switch (selection) {
            case 'q':
                break;
            case 'p':
                box = 0;
                printf("Box id: ");
                if (!read_int(&box)) {
                    printf("Please enter an integer number.\n");
                    continue;
                }
                print_box(box);
                break;
            case 'e':
                box = 0;
                printf("Box id: ");
                if (!read_int(&box)) {
                    printf("Please enter an integer number.\n");
                    continue;
                }
                edit_box(box);
                break;
            case '\n':
                break;
            default:
                printf(":(\n");

        }
    }
}