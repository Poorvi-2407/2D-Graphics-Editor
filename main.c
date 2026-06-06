#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 24

#define EMPTY '_'
#define PIXEL '*'

char picture[HEIGHT][WIDTH];

void clearPicture() {
    int i, j;

    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            picture[i][j] = EMPTY;
        }
    }
}

void displayPicture() {
    int i, j;

    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            printf("%c", picture[i][j]);
        }
        printf("\n");
    }
}

void setPixel(int x, int y) {
    if(x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        picture[y][x] = PIXEL;
    }
}

void drawLine(int x1, int y1, int x2, int y2) {

}

void drawRectangle(int x1, int y1, int x2, int y2) {

}

void drawCircle(int cx, int cy, int radius) {

}

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {

}

int main() {
    int choice;

    clearPicture();

    printf("2D Graphics Editor\n");

    while (1) {

        printf("\nMenu\n");
        printf("1. Display Picture\n");
        printf("0. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        if(choice == 1) {
            displayPicture();
        }
        else if(choice == 0) {
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}