#include <stdio.h>
#include <time.h>
#include <stdlib.h>


float rand_f() {

    return ((float)rand() / (float)(RAND_MAX)) * 50;

}

int main() {
    int len;
    char mode;

    srand(time(NULL));

    printf("Input array len:");
    while (!scanf("%d", &len) || len <= 0) {
        printf("Wrong len, input again:");
        rewind(stdin);
    }


    float arr[len];
    printf("Fill array random numbers? [y/n]");
    scanf(" %c", &mode);
    while (mode != 'y' && mode != 'n') {

        printf("Wrong answer, input again:");
        scanf(" %c", &mode);
        rewind(stdin);
    }


    if (mode == 'y') {
        printf("Generated array:");
        for (int i = 0; i < len; i++) {
            arr[i] = rand_f();
            printf(" %f", arr[i]);
        }
        printf("\n");
    }
    else {
        printf("Input %d elements:", len);
        for (int i = 0; i < len; i++) {
            while (!scanf("%f", &arr[i])) {
                printf("Wrong elem, input again:");
                rewind(stdin);
            }
        }
    }


    int k;

    printf("Input k:");
    while (!scanf("%d", &k) || k <= 0 || k > len) {
        printf("Wrong k, input again:");
        rewind(stdin);
    }


    int sub = 0;

    for (int i = 0; i < len + sub; i++) {

        if (!((i + 1) % k)) {
            for (int j = i - sub; j < len; j++) {
                arr[j] = arr[j + 1];
            }
            sub++;
            len--;
        }
    }


    printf("\nNew array:");
    for (int v = 0; v < len; v++) {
        printf(" %f", arr[v]);
    }


    return 0;
}