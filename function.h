#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h> 
#include <time.h>

#define MAX_SIZE_NAME 30 
#define MAX_SIZE_STRING 40 
#define SIZE_NUMBER_IN_FILE 3

typedef struct MusComp MusComp;

struct MusComp {
	int bit;
	int duration;
	char name[MAX_SIZE_NAME];
};

MusComp *add_in_array(MusComp *ArrayMuCo,int *SizeArray, int *NumberInArray, MusComp ElementMuCo);

void output_info(MusComp *ArrayMuCo, int NumberInArray);

void find_random_music_composition(MusComp *ArrayMuCo, int NumberInArray, int CountElement);

MusComp create_struct_music_composition(char *strin, FILE *fin);
