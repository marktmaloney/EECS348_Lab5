#include <stdio.h>

void printCombinations(int td2pt, int tdFg, int td, int fg, int safety) {
    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2pt, tdFg, td, fg, safety);
}

int main() {
    int score;
    printf("Enter 0 or 1 to STOP\n");
    printf("Enter the NFL score: ");
    scanf("%d", &score);

    while (score > 1) {
        printf("Possible combinations of scoring plays for the score %d:\n", score);

        int td2pt = 0;
        while (td2pt * 8 <= score) {
            int tdFg = 0;
            while (tdFg * 7 + td2pt * 8 <= score) {
                int td = 0;
                while (td * 6 + tdFg * 7 + td2pt * 8 <= score) {
                    int fg = 0;
                    while (fg * 3 + td * 6 + tdFg * 7 + td2pt * 8 <= score) {
                        int remainingScore = score - (td2pt * 8 + tdFg * 7 + td * 6 + fg * 3);
                        if (remainingScore % 2 == 0) {
                            int safety = remainingScore / 2;
                            printCombinations(td2pt, tdFg, td, fg, safety);
                        }
                        fg++;
                    }
                    td++;
                }
                tdFg++;
            }
            td2pt++;
        }

        printf("Enter the NFL score (Enter 0 or 1 to STOP): ");
        scanf("%d", &score);
    }

    return 0;
}
