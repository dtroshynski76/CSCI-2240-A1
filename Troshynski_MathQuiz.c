/*
Name: Donovan Troshynski
Program #: 1
Due Date: 26 January 2016
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int genQuestion(int diff);
int answerQuestion(int answer);
int response(int correct, int correctAnswer);

int main(void)
{
    unsigned int numQuestions;
    unsigned int difficulty;
    unsigned int counter = 0;
    int numCorrect;
    int correctAnswer;

    printf("How many questions for this test(1-20)? ");
    scanf("%u", &numQuestions);

    while(numQuestions < 1 || numQuestions > 20)
    {
        printf("How many questions for this test(1-20)? ");
        scanf("%u", &numQuestions);
    }

    printf("Select difficulty(1-4): ");
    scanf("%u", &difficulty);

    while(difficulty < 1 || difficulty > 4)
    {
        printf("Select difficulty(1-4): ");
        scanf("%u", &difficulty);
    }

    while(counter < numQuestions)
    {
        printf("Question %d: ", counter + 1);
        correctAnswer = genQuestion(difficulty);
        numCorrect += response(answerQuestion(correctAnswer), correctAnswer);
        counter++;
    }
    printf("Your score was %d/%u\n", numCorrect, numQuestions);
    return 0;
}

int genQuestion(int diff)
{
    int first;
    int last;
    int operator;
    char op;
    int answer;

    srand(time(NULL));
    if (diff == 1)
    {
        first = 1 + rand() % 10;
        last = 1 + rand() % 10;
        operator = 1 + rand() % 4;
    }

    if(diff == 2)
    {
        first = 1 + rand() % 50;
        last = 1 + rand() % 50;
        operator = 1 + rand() % 4;
    }

    if(diff == 3)
    {
        first = 1 + rand() % 100;
        last = 1 + rand() % 100;
        operator = 1 + rand() % 4;
       
    }

    if(diff == 4)
    {
        first = (rand() % 201) - 100;
        last = (rand() % 201) - 100;
        operator = 1 + rand() % 4;
    }

    switch(operator)
    {
        case 1:
            op = '+';
            break;
        case 2:
            op = '-';
            break;
        case 3:
            op = '*';
            break;
        case 4:
            op = '/';
            break;
        default:
            op = '*';
            break;
    }
    if(last == 0)
        last = 1;
    printf("%d %c %d =\n", first, op, last);

    if(operator == 1)
        answer = first + last;
    if(operator == 2)
        answer = first - last;
    if(operator == 3)
        answer = first * last;
    if(operator == 4)
        answer = first / last;
    return answer;
}

int answerQuestion(int x)
{
    int userAnswer;
    printf("Enter answer: ");
    scanf("%d", &userAnswer);

    if(userAnswer == x)
        return 1;

    return 0;
}

int response(int correct, int correctAnswer)
{
    int numCorrect;
    unsigned int grade;

    grade = 1 + rand() % 3;

    numCorrect = 0;
    if(correct > 0)
    {
        if(grade == 1)
            puts("Correct!");
        if(grade == 2)
            puts("Great job!");
        if(grade == 3)
            puts("Nice!");
        numCorrect++;
    }
    else
    {
        if(grade == 1)
            puts("Incorrect.");
        if(grade == 2)
            puts("Sorry!");
        if(grade == 3)
            puts("Wrong.");
        printf("The correct answer was %d\n", correctAnswer);
    }
    return numCorrect;
}
