/*==================================================================
 * File Name	:	hangman.c
 *
 * Description	:   Programme that allows the user to play the game
 *                  of hangman.
 *
 * Author		:	Dami Abagun - 19349771
 *
 * Date			:	01/12/2020
 *
 *==================================================================*/

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  #define COLOUMNSMAX 40
  #define ROWSMAX 10                 /*Numeric Constants are defined*/

  int randomWord(int);
  int FileReaderFunction(char[][COLOUMNSMAX]); /*Function prototypes are created.*/


 void main()

{
 srand(time(NULL));

 char HangmanWord [ROWSMAX][COLOUMNSMAX];   /*Creates the unknown word for hangman.*/
 char z;                                    /*Stores input from user to see whether or not the wish to play hangman.*/
 char y;                                    /*Stores the guess of a letter from the user input.*/
 int SuccessfulAttempts = 0;                /*This stores the counts of how many successful guess attempts are made.*/
 int RemainingAttempts = 10;                /*This stores the counts of the remaining attempts.*/
 int LetterChecker;                         /*Variable created to check if a letter is within the word.*/
 int numberOfWords = FileReaderFunction(HangmanWord); /*Calls the function to read file and stores the words within the variable.*/
 int b; /*Loop variable.*/

 do

{

 int position = RandomNumber(numberOfWords);     /*Calls the function to generate an index number between 0 and number of words.*/
 int WordLength = strlen(HangmanWord[position]); /*Stores the length of the secret word at generated random index position.*/
 char GuessInput [WordLength];                   /*Creates user guess letters input.*/
 char wordGuess [WordLength];                    /*This stores the word entered by the user.*/
 char TypeOfGuess;                               /*To store the type of guess that's made.*/

 printf("\n Ready to Start!");

 for(b = 0; b < WordLength; b++)                 /*Assigns '*' to all characters in the unknown word.*/

 GuessInput[b] = '*';
 GuessInput[b] = '\0';

 SuccessfulAttempts = 0;
 RemainingAttempts  = 10; /*Sets these numbers back to their original numbers after each play*/
{
 do

{
 LetterChecker =0;

 printf("\n The word is: ");

 printf("\t %s", GuessInput);

 fflush(stdin); /*Move the buffered data to console (in case of stdout) or disk (in case of file output stream).*/

 printf("\n Number of turns remaining: %d", RemainingAttempts);

 printf("\n Would you like to guess the word [w] or guess a letter [l]: "); /*Checks if they are guessing a letter in the word or the word.*/

 scanf("%c", &TypeOfGuess);

 fflush(stdin);


 if(TypeOfGuess == 'L' || TypeOfGuess == 'l') /*This checks if guess type is a letter ('l' or 'L')*/

{
 printf("\n What letter have you chosen?: ");
 scanf("%c", &y);

 for (b = 0; b < WordLength; b++)

{
 if ( (y) == HangmanWord[position][b]) /*Checks if the character input guess by the user is equal to any characters within the unknown word.*/

{
 GuessInput[b] = (y);                  /*Assigns the guess character in the relevant places within the unknown word if it is correct.*/
 LetterChecker = 1;                    /*This sets that it is true that a letter has been guessed correctly by the user.*/

 SuccessfulAttempts++;
}

}
 RemainingAttempts--;                /*Decreases the amount of attempts left by one.*/

 printf("\n************************************************ \n");

 if(LetterChecker == 1)               /*Checks if the letter checker value is one and if it is a letter has been guessed correctly.*/
    printf("\n Good choice!");        /*If character is correct this is displayed.*/

 else if (LetterChecker == 0)
    printf("\n Bad choice!");         /*If the character is wrong this is displayed.*/

 if (SuccessfulAttempts == WordLength)
    RemainingAttempts = -1;           /*This is to make sure that if the all the right characters are guessed loop will end.*/

 fflush(stdin);
}

 else if(TypeOfGuess == 'W' || TypeOfGuess == 'w') /*Checks if guess type is 'w' or 'W'*/

{
 printf("\n What is your guessed word?: ");       /*Checks the word input by user.*/
 scanf("%s", wordGuess);

 if(strcmp(wordGuess, HangmanWord[position]) == 0) /*Compares the user input word with the word that is hidden, to see if it is the same word.*/
 RemainingAttempts= -1;     /*This is to make sure that if the word matches the loop ends.*/

 else
 {
 printf("\n Wrong word");   /*If word doesnt match and is wrong it produces this.*/
 RemainingAttempts--;
 }
 fflush(stdin);
}

 else

 printf("\n Invalid choice!");       /*If any input is invalid.*/

}while(RemainingAttempts>0);         /*If the user runs out of attempts loop is ended.*/

 if (RemainingAttempts == 0)         /*Message displayed if the user has lost.*/
 printf("\n Unlucky! The correct word is %s. Better luck next time.", HangmanWord[position]);

 else if (RemainingAttempts == -1)
 printf("\n Congratulations!");       /*Message displayed if the user has won.*/


 }
  printf("\n************************************************ \n");
  printf(" Do you want to play again?[y/n]: "); /*Gives the user the choice to play again.*/

  scanf("%c", &z);


  if(z == 'N' || z == 'n')    /*If the user inputs N or n they no longer wish to play the game again meaning the program will end.*/
  break;

}while(1);

}




int RandomNumber(int numberOfWords) /* This function generates a random number in the word file then returns it*/

{

return (rand() % (numberOfWords - 0)) + 0;

}


int FileReaderFunction(char HangmanWord[][COLOUMNSMAX]) /*Function that reads in the unknown word.*/

{
 FILE *fp;
 char filename[128]; /*Variable and pointer declared to store the named file.*/

 printf("\n Give the filename with the unknown word: \t"); /*Requests filename from the user*/
 scanf("%s", filename);
 fp = fopen(filename, "r");                                /*This opens the file for file reading.*/
 int WordLength = 0;                                       /* Number of letters in word is stored in here. */


if(!fp) /*If the file is not able to be opened this error message is displayed.*/
{
  printf("ERROR: The file cannot be opened for reading");

return(0);
}


while(!feof(fp))

{
fscanf(fp, "%s", &HangmanWord[WordLength]); /*Obtains a word from the file*/
WordLength++;
}

fclose(fp);        /*This closes the file*/
return WordLength; /*Returns back the length of the word within the word.*/

}
