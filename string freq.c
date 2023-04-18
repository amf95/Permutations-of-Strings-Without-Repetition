// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRING_MAX_SIZE 11
int exists(char * word, char **arr, int n){
    for(int i = 0; i < n; i++)
        if(strcmp(word, *(arr+i)) == 0) // if exists.
            return 1;
    return 0;
}

int factorial(int n){
    if((n == 0) || (n == 1)) return 1;
    int factorial = 1;
    for(int i = 2; i <= n; i++)
        factorial *= i;

    return factorial;
}

char** getBasicElements(int n, char **s){
    char **basicElements;
    basicElements = calloc(n, sizeof(char *));
    for (int i = 0; i < n; i++)
		basicElements[i] = calloc(11, sizeof(char));

    for(int i = 0, j = 0; j < n; j++)
        if(!exists(s[j], basicElements, n)){
            strcpy(basicElements[i], s[j]);
            i++;
        }
    return basicElements;
}
	
int* getElementsFrequencies(int n, char **basicElements, char **s){
    int *frequencies;
    frequencies = (int *)calloc(n, sizeof(int));
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(strcmp(basicElements[i], s[j]) == 0)
                frequencies[i]++; 
            
    
    return frequencies;
}

int* getElementsFactorial(int n, int *elements){
    int *elementsFactorial;
    elementsFactorial = (int *)calloc(n, sizeof(int));
    
    for(int i = 0; i < n; i++)
        elementsFactorial[i] = factorial(elements[i]);  

    return elementsFactorial;
}
int getnumberOfSolutions(int n, char **s){
    // create basic elements non-repetitive array
    char **basicElements;
    basicElements = getBasicElements(n, s);
    //printElements(n, basicElements);
    
    // count the freq of each basic element in a different int array
    int *frequencies = getElementsFrequencies(n, basicElements, s);
    /*for(int i = 0; i < n; i++)
        printf("%d ", frequencies[i]);
    
    printf("\n");*/
    
    // get the fact of each element
    int *frequenciesFactorial = getElementsFactorial(n , frequencies);
    
    // get frequenciesFactorial multiplication (repetition)
    int repetition = 1;
    for(int i = 0; i < n; i++)
        repetition *= frequenciesFactorial[i];
    
    // calc number of solutions = n!/repetition(each string freq! * each other)
    // n: number of elements in input array s
    int numberOfSolutions = factorial(n) / repetition;
    
    free(frequencies);
    free(frequenciesFactorial);
    for (int i = 0; i < n; i++)
		free(basicElements[i]);
	free(basicElements);
	
	return numberOfSolutions;
}

void printElements(int n, char **s){
    for(int i = 0; i < n; i++)
        printf("%s ", s[i]);
    
    printf("\n");
}


int main() {
    // Write C code here
    char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	// now we have an array of strings s
	
	// ----------------- TEST -----------------
	printf("%d\n", getnumberOfSolutions(n, s));
	
    for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	///printf("\nend\n");
    return 0;
}


