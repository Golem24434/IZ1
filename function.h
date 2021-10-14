#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <time.h>

#define MAX_SIZE_NAME 30 
#define MAX_SIZE_STRING 40 
#define SIZE_NUMBER_IN_FILE 3
#define ERROR 404

typedef struct mus_comp mus_comp;

struct mus_comp {
	int bit;
	int duration;
	char name[MAX_SIZE_NAME];
};

mus_comp *add_in_array(mus_comp *array_mu_co,int *SizeArray, int *number_in_array, mus_comp element_mu_co);

int output_info(mus_comp *array_mu_co, int number_in_array);

int find_random_music_composition(mus_comp *array_mu_co, int number_in_array, int coun_element);

mus_comp create_struct_music_composition(char *strin, FILE *fin);

#endif