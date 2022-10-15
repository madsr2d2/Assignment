// code adapted from example found at https://codereview.stackexchange.com/questions/23845/random-sentences-generator

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define countOf(arr) (sizeof(arr)/sizeof(arr[0])) // Gets number of elements in array

// Word arrays
const char* article[] = {"den", "en", "nogle", "enhver", "det", "flere"};
const char* noun[] = {"personer", "studerende", "arbejdsløse", "by", "og", "cykel", "s-tog"};
const char* verb[] = {"korte", "hoppede", "lob", "gik", "sad", "bevægede"};
const char* preposition[] = {"til", "fra", "over", "under", "på", "ved siden af"};

const int maxWordLength = 11; // Length of longest word
const int sentenceLength = 6; // words in sentence
const int sentenceNumber = 50; // Number of sentences


char* randomSentenceGenerator();

int main()
{
	srand(time(0));

	for(int i = 0; i <= sentenceNumber; i++) {
        char* sentence = randomSentenceGenerator();
        printf("%s\n", sentence);
        free(sentence);
    }

	return 0;
}

char* randomSentenceGenerator() {
	char* sentence = calloc((sentenceLength*maxWordLength + sentenceLength), sizeof(char)); // Allocate memory

  	// Construct sentence
  	strcat(sentence, article[rand()%countOf(article)]); // Add article
  	strcat(sentence, " ");

  	strcat(sentence, noun[rand()%countOf(noun)]); // Add noun
  	strcat(sentence, " ");

  	strcat(sentence, verb[rand()%countOf(verb)]); // Add verb
  	strcat(sentence, " ");

  	strcat(sentence, preposition[rand()%countOf(preposition)]); // Add preposition
  	strcat(sentence, " ");

  	strcat(sentence, article[rand()%countOf(article)]); // Add article
  	strcat(sentence, " ");

  	strcat(sentence, noun[rand()%countOf(noun)]); // Add noun
  	strcat(sentence, ".");

  	sentence[0] = toupper(sentence[0]); // Capitalize first letter

	return sentence;
}








