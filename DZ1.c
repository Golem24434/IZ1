#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h> 
#include <time.h>
#include "function.h"

#define MAX_SIZE_NAME 30 
#define MAX_SIZE_STRING 40 
#define SIZE_NUMBER_IN_FILE 3

int main() {
	srand(time(NULL));
	MusComp	*ArrayMuCo = (MusComp*)malloc(1*sizeof(MusComp));
	MusComp ElementMuCo;
	char 	strin[MAX_SIZE_STRING];
	int  	NumberInArray, SizeArray = 1, inputCount;
	FILE 	*fin = fopen("C:\\Users\\Omar\\Desktop\\Tehnopark_C_Cpp\\Second\\DataBase.txt", "r");
	if (fin == NULL) printf("Error! File with data can't open!");
	for (NumberInArray = 0;NumberInArray < 125;NumberInArray++) {
		if (fgets(strin, MAX_SIZE_STRING, fin) == NULL) printf("Error with gets()!");
		ElementMuCo = create_struct_music_composition(strin, fin);
		ArrayMuCo = add_in_array(ArrayMuCo, &SizeArray, &NumberInArray, ElementMuCo);
	}
	scanf("How many tracks do you want to see? %d",&inputCount);
    find_random_music_composition(ArrayMuCo,NumberInArray,inputCount);
	fclose(fin);
    return 0;
}
