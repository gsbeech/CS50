#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <math.h>

// Functions to count the number of letters / words / sentences in a given text string.
int count_letters(string inputText);
int count_words(string inputText);
int count_sentences(string inputText);

// Counters for respective functions
int lettercounter;
int spacecounter;
int sentenceterminatorcounter;


int total_letters;
int total_words;
int total_sentences;

float lettersPer100Words;
float sentencesPer100Words;
float index;

int main(void)
{
    string inputText = get_string("Text: ");
    total_letters = count_letters(inputText);
    total_words = count_words(inputText);
    total_sentences = count_sentences(inputText);
    lettersPer100Words = (((float)total_letters / (float)total_words) * 100);
    sentencesPer100Words = (((float)total_sentences / (float)total_words) * 100);

//    Debug
//    printf("%lu characters in string\n\r",strlen(inputText));
//    printf("%i letter(s) in string\n\r", total_letters);
//    printf("%i words in string \n\r", total_words);
//    printf("%i sentences in string \n\r", total_sentences);
//    printf("%f = letters per 100 words \n\r", lettersPer100Words);
//    printf("%f = sentences per 100 words \n\r", sentencesPer100Words);

    index = (0.0588 * lettersPer100Words - 0.296 * sentencesPer100Words - 15.8);
    index = round(index);
    if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }
}

// This function iterates through every element in the string (which is an array). For every element, it
// checks if the element has a value between 65-90 (upper case A-Z), or a value between 97-122 (lower case a-z)
// If it is in one of these brackets, we know it is a letter, and add one to the letter count returned.

int count_letters(string inputText)
{
    //return strlen(inputText);
    int stringlength = strlen(inputText);
    for (int i = 0; i <= stringlength; i++)
    {
        if ((inputText[i] >= 65 && inputText[i] <= 90) || (inputText[i] >= 97 && inputText[i] <= 122))
        {
            lettercounter += 1;
        }
    }
    total_letters = lettercounter;
    return total_letters;
}


// If we assume that sentences don't begin or end with spaces, and that phrases like "mother-in-law" are
// one word, then the total number of words in a string is the number of spaces + 1.
int count_words(string inputText)
{
    int stringlength = strlen(inputText);
    for (int i = 0; i <= stringlength; i++)
    {
        if (inputText[i] == 32)
        {
            spacecounter += 1;
        }
    }
    total_words = spacecounter + 1;
    return total_words;
}


// For each element in the string, if the element matches the ASCII value for !, ., or ? (sentence terminators)
// increment the return value. We assume that there will be a 1:1 ratio of sentence terminators to sentences
// which is not strictly true, e.g. Mr. Dursley isn't a sentence but contains a terminator
int count_sentences(string inputText)
{
    int stringlength = strlen(inputText);
    {
        for (int i = 0; i <= stringlength; i++)
        {
            if ((inputText[i] == 46) || (inputText[i] == 33) || (inputText[i] == 63))
            {
                sentenceterminatorcounter += 1;
            }
        }
        total_sentences = sentenceterminatorcounter;
        return total_sentences;
    }
}