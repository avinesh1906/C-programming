#include <stdio.h> // library to import printf and scanf
#include <stdlib.h> //library to generate a random number
#include <time.h> // library to generate different random number each time the program runs
#include <unistd.h> // library to import function sleep

// CONSTANT
#define MAX 24

// prototype
int languageCheck(int langue);
int requirementFaces(int checkFaces);
int requirementThrows(int checkThrows);
void randomNumberGenerator(int lower, int upper);
void print(void);
int checkChoice(int i);

// create my own datatype
typedef struct
{
    int face;
    int occurence;
}
die;

// declaration of global variables
int faces, throws, language, choice;

// create a global array variable name roll of datatype die(datatype created above)
die roll[MAX];

// main function
int main(void)
{
    // declaration of local variable of type char to store input of user that would be converted later for validation
    char langue[100];
    char face[100];
    char throw[100];
    char choix[100] = "1";

    // printing the grreting messages
    printf("\t\tHello \\ Bonjour 😄 \n");
    printf("🎲 Welcome to the Dice Rolling Program \\ Bienvenue dans le programme de lancer de dés. 🎲\n\n");

    // prompt the user to choose its desired language
    printf("🗣️ Make your choice for your desired language \\ Faites votre choix pour la langue souhaitée 🗣️\n1: English \n2: Français\nYour choice \\ Votre choix: ");
    scanf("%s", langue);
    language = atoi(langue); // The function ATOI takes as input the string that is to be converted to an integer.

    // loop until meet the language requirement
    while (languageCheck(language) != 0)
    {
        printf("\nWrong input \\ Mauvaise entrée :( \nEnter again \\ Entrer à nouveau: \a"); // \a is used to make the beeping sound for wrong input
        scanf("%s", langue);
        language = atoi(langue);
    }

    // choose between english or french
    if (language == 1)
    {
        printf("\nThank you for choosing ☺️ \n");
    }
    else if (language == 2)
    {
        printf("\nMerci d'avoir choisi ☺️ \n");
    }

    // convert choice into integer
    choice = atoi(choix);

    // keep looping until the user decides to quit
    while (choice == 1)
    {

        // declaration of local variable
        int lower;
        int upper;

        // program sleeps for 1 sec
        sleep(1);

        // run the code according to the language
        if (language == 1)
        {

            // prompt the user for number of faces
            printf("\nPlease enter the number of faces: ");
            scanf("%s", face);
            faces = atoi(face);

            // loop until requirement is not met
            while (requirementFaces(faces) != 0)
            {
                // prompt the user for number of faces
                printf("Please re-enter the number of faces: \a");
                scanf("%s", face);
                faces = atoi(face);

            }

            // prompt the user for number of throws
            printf("Please enter the number of throws: ");
            scanf("%s", throw);
            throws = atoi(throw);

            // loop until requirement is not met
            while (requirementThrows(throws) != 0)
            {
                // prompt the user for number of throws
                printf("Please re-enter the number of throws: \a");
                scanf("%s", throw);
                throws = atoi(throw);
            }

        }

        else if (language == 2)
        {
            // prompt the user for number of faces
            printf("\nVeuillez saisir le nombre de faces: ");
            scanf("%s", face);
            faces = atoi(face);


            // loop until requirement is not met
            while (requirementFaces(faces) != 0)
            {
                // prompt the user for number of faces
                printf("Veuillez saisir à nouveau le nombre de visages: \a");
                scanf("%s", face);
                faces = atoi(face);

            }

            // prompt the user for number of throws
            printf("Veuillez saisir le nombre de lancers: ");
            scanf("%s", throw);
            throws = atoi(throw);

            // loop until requirement is not met
            while (requirementThrows(throws) != 0)
            {
                // prompt the user for number of throws
                printf("Veuillez saisir à nouveau le nombre de lancers: \a");
                scanf("%s", throw);
                throws = atoi(throw);
            }
        }

        // assigning the face's number
        for (int i = 0; i < faces; i++)
        {
            roll[i].face = i + 1;
        }

        // assigning zero to the number of occurence of roll
        for (int i = 0; i < faces; i++)
        {
            roll[i].occurence = 0;
        }

        // Use current time as seed for random generator
        srand(time(0));

        // Generate the random number within the range
        lower = 1;
        upper = faces;

        // function call for randomNumberGenerator with argument lower and upper
        randomNumberGenerator(lower, upper);

        // function for printing the occurence
        print();


        // ask the user if want to play again
        if (language == 1)
        {
            printf("\nPress 1 to play again or 2 to exit...\n");
        }
        else if (language == 2)
        {
            printf("\nAppuyez sur 1 pour lire à nouveau ou sur 2 pour quitter ...\n");
        }

        // read the input from the user
        scanf("%s", choix);
        choice = atoi(choix);

        // check whether user insert 1 or 2 only
        while (checkChoice(choice) != 0)
        {
            if (language == 1)
            {
                printf("Wrong input :( Please re-enter 1 or 2 only :\a\n");
                scanf("%s", choix);
                choice = atoi(choix);
            }
            else if (language == 2)
            {
                printf("Mauvaise saisie:( Veuillez saisir à nouveau 1 ou 2 uniquement : \a\n");
                scanf("%s", choix);
                choice = atoi(choix);
            }

        }

    }

    sleep(1);

    // displaying the goodbye message
    if (language == 1)
    {
        printf("\nBye Bye 👋👋👋Take Care...\nDone by Culloo Avinesh & Arvind Khulputeea. 🧑🎓\n");
    }
    else if (language == 2)
    {
        printf("\nBye Bye 👋👋👋Faites attention ...\nFait par Culloo Avinesh & Arvind Khulputeea. 🧑🎓\n");
    }

}

// function to check correct input for language
int languageCheck(int langue)
{
    // check if the language input meet the criteria
    if (langue == 1 || langue == 2)
    {
        return 0; // return 0 if meet the requirements
    }
    return 1; // else return 1 if do not meet it
}

// function to check if the input matches criteria
int requirementFaces(int checkFaces)
{
    // check if number of faces is between 1 and 25 exclusive
    if (checkFaces <= 1 || checkFaces > MAX)
    {
        // display error messages according to the language
        if (language == 1)
        {
            printf("Please do enter a number between 1 and 25 only for number of faces\a\n");
        }
        else if (language == 2)
        {
            printf("Veuillez saisir un nombre entre 1 et 25 uniquement pour le nombre de visages\a\n");
        }
        return 1; // return 1 if do not meet condition
    }

    // else return 0 if met the requirments.
    return 0;

}

// function to check if the input matches criteria
int requirementThrows(int checkThrows)
{

    // check if number of throws is between 1 and 500 exclusive
    if (checkThrows <= 1 || checkThrows >= 500)
    {
        // error message according to the language type
        if (language == 1)
        {
            printf("Please do enter a number between 1 and 500 only for number of throws\a\n");
        }
        else if (language == 2)
        {
            printf("Veuillez saisir un nombre entre 1 et 500 uniquement pour le nombre de lancers\a\n");
        }
        return 1; // return 1 if do not meet criteria
    }

    // else return 0 if met the requirments.
    return 0;

}

// function to generate the random number
void randomNumberGenerator(int lower, int upper)
{

    /*****************************************************************************
     As C does not have an inbuilt function for
     generating a number in the range, but it does have rand function which
     generate a random number from 0 to RAND_MAX. With the help of rand () a number
     in range can be generated as num = (rand() % (upper – lower + 1)) + lower
     Source: https://www.geeksforgeeks.org/generating-random-number-range-c/
    *******************************************************************************/

    // heading for generating throws
    if (language == 1)
    {
        printf("\nCollecting the dice...🎲\n");
        sleep(1);
        printf("Throwing the dice...🎲\n");
        sleep(1);
        printf("Now generating all throws: \n");
    }
    else if (language == 2)
    {
        printf("\nCollecter les dés...🎲\n");
        sleep(1);
        printf("Jeter les dés...🎲\n");
        sleep(1);
        printf("Générer maintenant tous les lancers: \n");
    }


    // loop number of throws' times
    for (int k = 0; k < throws; k++)
    {

        // formula to generate random number
        int num = (rand() % (upper - lower + 1)) + lower;

        // print the number
        printf("%d\n", num);

        sleep(1);

        // insert the generated number in roll's occurence
        for (int j = 0; j < upper; j++)
        {
            if (roll[j].face == num)
            {
                roll[j].occurence += 1;
            }
        }

    }
}

// function to print the occurence of each face
void print(void)
{
    sleep(1);

    if (language == 1)
    {
        printf("\nCalculating the ouccurence of each face...🖩");
        sleep(1);
        printf("\nNow displaying the occurence of each face.\n");
    }
    else if (language == 2)
    {
        printf("\nCalcul de l'occurence de chaque face ... 🖩");
        sleep(1);
        printf("\nAffiche maintenant l'occurrence de chaque visage.\n");
    }

    // loop number of faces times
    for (int i = 0; i < faces; i++)
    {
        // calculate the probability of each face occured
        float probability = ((float)roll[i].occurence / throws) * 100;

        sleep(1);

        // choose between english or french
        if (language == 1)
        {
            // print the probability
            printf("Occurrence of %d: %.2f %%\n", (roll[i].face), probability);
        }
        else if (language == 2)
        {
            printf("Occurrence de %d: %.2f %%\n", (roll[i].face), probability);
        }

    }

}

// function to check whether the user entered the correct input to continue or quit
int checkChoice(int inputChoice)
{
    // check if the input of choice is only 1 or 2
    if (inputChoice == 1 || inputChoice == 2)
    {
        return 0; // return 0 if met condition
    }
    return 1; // else return 1 if do not meet condition
}