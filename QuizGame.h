#include <stdio.h>

void showIntroduction()
{
    printf("===================================================================\n");
    printf("Welcome to C Language Online Quiz Game!\n\n");
    printf("[1] Start\n");
    printf("[2] Exit\n");
    printf("===================================================================\n");
}

void showMainMenu(int scores[])
{
    printf("===================================================================\n");
    printf("Main Menu\tScores---->History: %d/10 Basics: %d/10 Functions: %d/10\n", scores[0], scores[1], scores[2]);
    printf("===================================================================\n");
    printf("[1] C Language History\n");
    printf("[2] C Language Basics\n");
    printf("[3] C Language Functions\n");
    printf("[4] Exit\n");
    printf("===================================================================\n");
}

void showInstructions()
{
    printf("===================================================================\n");
    printf("Pls. carefully select the correct answer (5 items, 2 points each).\n\n");
}

void inputName(char *name)
{
    // Get name from user if only name has not been entered yet, otherwise display it
    if (name[0] == '\n')
    {
        printf("Enter Full Name: ");
        scanf("%[^\n]", name);
    }
    else
    {
        printf("Full Name: %s\n", name);
    }
}

int checkCorrectAnswer(char answer, char correct, char reveal[], int points)
{
    // Adds 2 points if the answer is correct and no points if wrong, show the correct one afterwards
    if (answer == correct)
    {
        points = points + 2;
        printf("\nCorrect! You've got %d/10 points.\n\n", points);
    }
    else
    {
        printf("\nWrong answer! You've got %d/10 points. ", points);
        printf("The correct answer is: [%c] %s\n\n", correct, reveal);
    }

    return points;
}

void showRemarks(int totalScore)
{
    if (totalScore < 10)
    {
        printf("\nStudent Remarks: Failed!\n\n");
    }
    else
    {
        printf("\nStudent Remarks: Passed!\n\n");
    }
}

int computeTotalScore(int scores[])
{
    return scores[0] + scores[1] + scores[2];
}

double computeGenAverage(int scores[])
{
    return (scores[0] + scores[1] + scores[2]) / 3.0;
}

int startHistoryQuiz()
{
    // These variables contain the correct answers for the quiz
    char reveal[5][20] = {"Dennis Ritchie", "1972", "C Language", "B Language", "BCPL, B, Algol"},
            correct[5] = {'b', 'c', 'b', 'a', 'd'},
            answer = ' ';
    int question, points = 0;

    showInstructions();

    // Display the questions in order
    for (question = 1; question <= 5; question++)
    {
        switch (question)
        {
            case 1:
                printf("1. Who developed C language?\n");
                printf("[a] Cecile Arkson\t[b] Dennis Ritchie\t[c] Erik Isakson\t[d] Mel Mathew\n");
                break;

            case 2:
                printf("2. C programming language was developed in _______ by Dennis Ritchie at Bell Laboratories of AT&T.\n");
                printf("[a] 1960\t[b] 1971\t[c] 1972\t[d] 1980\n");
                break;

            case 3:
                printf("3. What is referred to as the middle-level language?\n");
                printf("[a] C++ Language\t[b] C Language\t[c] Java\t[d] Pascal\n");
                break;

            case 4:
                printf("4. What language influenced the creators of the C language to name it as C?\n");
                printf("[a] B Language\t[b] C++ Language\t[c] C-- Language\t[d] Pascal\n");
                break;

            case 5:
                printf("5. C was evolved from?\n");
                printf("[a] B, C++, BCPL\t[b] B, C++, Algol\t[c] BCPL, C++, Algol\t[d] BCPL, B, Algol\n");
                break;
        }

        // Get answer from user
        printf("\nYour answer is: ");
        scanf(" %c", &answer);

        // Check if answer is correct, add points accordingly
        points = checkCorrectAnswer(answer, correct[question - 1], reveal[question - 1], points);
    }

    return points;
}

int startBasicsQuiz()
{
    // These variables contain the correct answers for the quiz
    char reveal[5][20] = {"char", "float", "medium", "Comments", "Identifiers"},
            correct[5] = {'a', 'c', 'b', 'a', 'a'},
            answer = ' ';
    int question, points = 0;

    showInstructions();

    // Display the questions in order
    for (question = 1; question <= 5; question++)
    {
        switch (question)
        {
            case 1:
                printf("1. One of the 4 basic data types in C that is a single character.\n");
                printf("[a] char\t[b] double\t[c] float\t[d] int\n");
                break;

            case 2:
                printf("2. One of the 4 basic data types in C that is a number containing a decimal point and/or exponent.\n");
                printf("[a] char\t[b] double\t[c] float\t[d] int\n");
                break;

            case 3:
                printf("3. Which of these is not a type of qualifier?\n");
                printf("[a] long\t[b] medium\t[c] short\t[d] signed\n");
                break;

            case 4:
                printf("4. These are the remarks and non executable phrases or sentences.\n");
                printf("[a] Comments\t[b] Declaration\t[c] Function\t[d] Header\n");
                break;

            case 5:
                printf("5. These are names that are given to various program elements.\n");
                printf("[a] Identifiers\t[b] Names\t[c] Qualifiers\t[d] Variables\n");
                break;
        }

        // Get answer from user
        printf("\nYour answer is: ");
        scanf(" %c", &answer);

        // Check if answer is correct, add points accordingly
        points = checkCorrectAnswer(answer, correct[question - 1], reveal[question - 1], points);
    }

    return points;
}

int startFunctionsQuiz()
{
    // These variables contain the correct answers for the quiz
    char reveal[5][20] = {"Function", "scanf()", "printf()", "strcpy()", "scanf()"},
            correct[5] = {'c', 'b', 'c', 'a', 'd'},
            answer = ' ';
    int question, points = 0;

    showInstructions();

    // Display the questions in order
    for (question = 1; question <= 5; question++)
    {
        switch (question)
        {
            case 1:
                printf("1. It is the 'block of statements' that perform a specific task.\n");
                printf("[a] Built-in functions\t[b] Code\t[c] Function\t[d] Statement\n");
                break;

            case 2:
                printf("2. <stdio.h> is a header file in order to use the _______ function.\n");
                printf("[a] main()\t[b] scanf()\t[c] while()\t[d] None of the above\n");
                break;

            case 3:
                printf("3. A function in C that allows you print characters and symbols on the screen.\n");
                printf("[a] fprintf()\t[b] getchar()\t[c] printf()\t[d] scanf()\n");
                break;

            case 4:
                printf("4. It copies (duplicates) one string to another.\n");
                printf("[a] strcpy()\t[b] strncat()\t[c] strncpy()\t[d] strstr()\n");
                break;

            case 5:
                printf("5. A function in C that allows you to accept input from standard input.\n");
                printf("[a] main()\t[b] printf()\t[c] puts()\t[d] scanf()\n");
                break;
        }

        // Get answer from user
        printf("\nYour answer is: ");
        scanf(" %c", &answer);

        // Check if answer is correct, add points accordingly
        points = checkCorrectAnswer(answer, correct[question - 1], reveal[question - 1], points);
    }

    return points;
}