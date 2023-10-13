#include <stdio.h>
#include <stdlib.h>

int tph, philname[20], status[20], howhung, hu[20], cho;

void one() {
    int pos = 0, x, i;
    printf("\nAllow one philosopher to eat at any time\n");
    for (i = 0; i < howhung; i++, pos++) {
        printf("\nP %d is granted to eat", philname[hu[pos]]);
        for (x = pos; x < howhung; x++)
            printf("\nP %d is waiting", philname[hu[x]]);
    }
}

void two() {
    int i, j, s = 0, t, r, x;
    printf("\nAllow two philosophers to eat at the same time\n");
    for (i = 0; i < howhung; i++) {
        for (j = i + 1; j < howhung; j++) {
            int diff = abs(hu[i] - hu[j]);
            if (diff != 1 && diff != (tph - 1)) {
                printf("\n\ncombination %d\n", (s + 1));
                t = hu[i];
                r = hu[j];
                s++;
                printf("\nP %d and P %d are granted to eat", philname[hu[i]], philname[hu[j]]);
                for (x = 0; x < howhung; x++) {
                    if ((hu[x] != t) && (hu[x] != r))
                        printf("\nP %d is waiting", philname[hu[x]]);
                }
            }
        }
    }
}

int main() {
    int i;
    printf("\nDINING PHILOSOPHER PROBLEM\n");
    printf("Enter the total number of philosophers: ");
    scanf("%d", &tph);
    for (i = 0; i < tph; i++) {
        philname[i] = (i + 1);
        status[i] = 1;
    }
    printf("How many are hungry: ");
    scanf("%d", &howhung);
    if (howhung == tph) {
        printf("\nAll are hungry...\nDeadlock stage will occur\n");
        printf("Exiting\n");
        return 0;
    } else {
        for (i = 0; i < howhung; i++) {
            printf("Enter philosopher %d position: ", (i + 1));
            scanf("%d", &hu[i]);
            status[hu[i]] = 2;
        }
        while (1) {
            printf("\n1. One can eat at a time\n2. Two can eat at a time\n3. Exit\nEnter your choice: ");
            scanf("%d", &cho);
            switch (cho) {
                case 1:
                    one();
                    break;
                case 2:
                    two();
                    break;
                case 3:
                    return 0;
                default:
                    printf("\nInvalid option..\n");
                    break;
            }
        }
    }
}
