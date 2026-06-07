#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

    int x, y;

    if(y1 == y2) {

        for(x = x1; x <= x2; x++) {

            setPixel(x, y1);
        }
    }

    else if(x1 == x2) {

        for(y = y1; y <= y2; y++) {

            setPixel(x1, y);
        }
    }
}

void drawRectangle(int x1, int y1, int x2, int y2) {

    drawLine(x1, y1, x2, y1);

    drawLine(x1, y2, x2, y2);

    drawLine(x1, y1, x1, y2);

    drawLine(x2, y1, x2, y2);
}

void drawCircle(int cx, int cy, int radius) {

    int x, y;

    for(y = 0; y < HEIGHT; y++) {

        for(x = 0; x < WIDTH; x++) {

            int dx = x - cx;
            int dy = y - cy;

            if(dx * dx + dy * dy <= radius * radius) {

                setPixel(x, y);
            }
        }
    }
}

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {

    drawLine(x1, y1, x2, y2);

    drawLine(x2, y2, x3, y3);

    drawLine(x3, y3, x1, y1);
}

int main() {

    int choice;

    clearPicture();

    while (1) {

        printf("\n2D Graphics Editor\n");

        printf("1. Draw Horizontal Line\n");
        printf("2. Draw Vertical Line\n");
        printf("3. Draw Rectangle\n");
        printf("4. Draw Circle\n");
        printf("5. Draw Triangle\n");
        printf("6. Display Picture\n");
        printf("0. Exit\n");

        printf("Enter choice: ");

        scanf("%d", &choice);

        if(choice == 1) {

            int x1, x2, y;

            printf("Enter x1 x2 y: ");

            scanf("%d %d %d", &x1, &x2, &y);

            drawLine(x1, y, x2, y);
        }

        else if(choice == 2) {

            int x, y1, y2;

            printf("Enter x y1 y2: ");

            scanf("%d %d %d", &x, &y1, &y2);

            drawLine(x, y1, x, y2);
        }

        else if(choice == 3) {

            int x1, y1, x2, y2;

            printf("Enter x1 y1 x2 y2: ");

            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

            drawRectangle(x1, y1, x2, y2);
        }

        else if(choice == 4) {

            int cx, cy, radius;

            printf("Enter center x y and radius: ");

            scanf("%d %d %d", &cx, &cy, &radius);

            drawCircle(cx, cy, radius);
        }

        else if(choice == 5) {

            int x1, y1, x2, y2, x3, y3;

            printf("Enter x1 y1 x2 y2 x3 y3: ");

            scanf("%d %d %d %d %d %d",
                  &x1, &y1, &x2, &y2, &x3, &y3);

            drawTriangle(x1, y1, x2, y2, x3, y3);
        }

        else if(choice == 6) {

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