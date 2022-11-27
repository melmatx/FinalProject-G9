#include <stdio.h>
#include "QuizGame.h"

int main()
{
    char name[50] = {'\n'},
            taken[3] = {'n', 'n', 'n'};
    int scores[3] = {0, 0, 0},
            input = 0, choice = 0, totalScore = 0;
    double genAve;

    do
    {
        // Display introduction and get name from user
        inputName(name);
        showIntroduction();

        // Get input from user
        printf("Enter your choice: ");
        scanf(" %d", &input);

        if (input == 2)
        {
            printf("\nThank you, have a great day ahead!\n\n");
        }
        else if (input == 1)
        {
            do
            {
                // Display menu using the scores array
                showMainMenu(scores);

                // Get choice from user
                printf("Enter your choice: ");
                scanf(" %d", &choice);

                // Check if the chosen test is already taken ('y'), otherwise continue if not ('n')
                if (taken[choice - 1] == 'y')
                {
                    printf("\nThis test has already been taken and is no longer available.\n\n");
                }
                else
                {
                    switch (choice)
                    {
                        // Starts chosen quiz and stores resulting points in the scores array
                        case 1:
                            scores[0] = startHistoryQuiz();
                            break;

                        case 2:
                            scores[1] = startBasicsQuiz();
                            break;

                        case 3:
                            scores[2] = startFunctionsQuiz();
                            break;
                    }

                    // Modifies the chosen quiz to say it is now taken
                    if (taken[choice - 1] == 'n')
                    {
                        taken[choice - 1] = 'y';
                    }
                }
            } while (choice != 4);

            // Print total score
            totalScore = computeTotalScore(scores);
            printf("\nTotal: %d/30", totalScore);

            // Print general average
            genAve = computeGenAverage(scores);
            printf("\nAverage: %.1f", genAve);

            // Print remarks
            showRemarks(totalScore);
        }
    } while (input != 2);

    return 0;
}