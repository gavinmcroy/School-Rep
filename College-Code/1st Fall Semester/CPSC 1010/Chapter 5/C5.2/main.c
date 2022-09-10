#include <stdio.h>

int main() {

    char candidateName[5][40];
    int votes[5];
    double sumOfVotes = 0;
    printf("Enter candidate's name and the votes received by the candidate.\n");
    for (int i = 0; i < 5; i++) {
        scanf("%s", candidateName[i]);
        scanf("%d", &votes[i]);
        sumOfVotes += votes[i];
    }

    printf("%10s %17s %19s", "Candidate", "Votes Received", "% of Total Votes\n");
    printf("%10s %17s %19s", "---------", "--------------", "----------------\n");
    printf("%10s %10d %21.2lf\n", candidateName[0], votes[0], (double) (votes[0] / sumOfVotes) * 100.0);
    printf("%10s %10d %21.2lf\n", candidateName[1], votes[1], (double) (votes[1] / sumOfVotes) * 100.0);
    printf("%10s %10d %21.2lf\n", candidateName[2], votes[2], (double) (votes[2] / sumOfVotes) * 100.0);
    printf("%10s %10d %21.2lf\n", candidateName[3], votes[3], (double) (votes[3] / sumOfVotes) * 100.0);
    printf("%10s %10d %21.2lf\n", candidateName[4], votes[4], (double) (votes[4] / sumOfVotes) * 100.0);

    printf("\nTotal Votes: %.0lf\n", sumOfVotes);

    int winner = 0;
    int max = votes[0];

    for (int i = 0; i < 5; i++) {
        if (votes[i] > max) {
            winner = i;
            max = votes[i];
            printf("%d\n", i);
        }
    }
    printf("The Winner of the Election is: %s\n", candidateName[winner]);

    return 0;
}