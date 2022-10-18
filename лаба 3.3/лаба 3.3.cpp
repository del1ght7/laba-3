#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define len 30

int num_cmp_(int* s1, int* s2) {
    int i = 0;

    while (s1[i] == s2[i]) {
        i++;
    }

    return s1[i] - s2[i];
}

int abs_(int value) {
    return value * ((value > 0) - (value < 0));
}


int main() {
    char mode;

    srand(time(NULL));


    int num1[len];
    int num2[len];

    printf("Fill array random numbers? [y/n]");
    scanf("%c", &mode);

    while (mode != 'y' && mode != 'n') {
        printf("Wrong answer, input again:");
        scanf("%c", &mode);
        rewind(stdin);
    }


    if (mode == 'y') {

        printf("Generated nums:\n");

        for (int i = 0; i < len; i++) {
            num1[i] = (rand() % 9) + 1;
            printf("%d", num1[i]);
        }

        printf("\n");

        for (int i = 0; i < len; i++) {
            num2[i] = (rand() % 9) + 1;
            printf("%d", num2[i]);
        }

        printf("\n");

    }
    else {

        char c[len];
        int cnt = 0;

        while (cnt != len) {
            cnt = 0;

            printf("Input number1:");
            scanf("%s", c);

            for (int i = 0; i < len; i++) {
                num1[i] = c[i] - 48;

                if (!(0 < num1[i] && num1[i] < 10)) {
                    break;
                }
                cnt++;
            }
            rewind(stdin);
        }

        cnt = 0;

        while (cnt != len) {

            cnt = 0;

            printf("Input number2:");
            scanf("%s", c);

            for (int i = 0; i < len; i++) {
                num2[i] = c[i] - 48;

                if (!(0 < num2[i] && num2[i] < 58)) {
                    break;
                }
                cnt++;
            }
            rewind(stdin);
        }
    }


    int sub, null = 0, tmp;

    printf("Result: ");

    if (abs_((num_cmp_(num1, num2))) > 9) {
        printf("0");
        return 0;

    }
    else if (num_cmp_(num1, num2) < 0) {
        printf("-");
        for (int i = 0; i < len; i++) {
            tmp = num2[i];
            num2[i] = num1[i];
            num1[i] = tmp;

        }
    }


    for (int i = len - 1; i >= 0; i--) {
        sub = num1[i] - num2[i];
        if (sub < 0) {
            sub = num1[i] + 10 - num2[i];
            num1[i - 1]--;
        }
        num1[i] = sub;
    }


    for (int i = 0; i < len; i++) {
        if (num1[i] != 0) {
            null = 1;
        }
        if (null) {
            printf("%d", num1[i]);
        }

    }


    return 0;
}