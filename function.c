#include "function.h"

mus_comp *add_in_array(mus_comp *array_mu_co,int *SizeArray, int *number_in_array, mus_comp element_mu_co)
{
	if ((array_mu_co == NULL) || (SizeArray == NULL)) 
	{
		printf("Error associated with pointers in function add_in_array()!");
		return NULL;
	}
	if (*number_in_array + 1 == *SizeArray)	 
	{
		(*SizeArray)  *= 2;
		mus_comp	*old_ptrarray_mu_co = array_mu_co;
		array_mu_co = (mus_comp *) realloc(old_ptrarray_mu_co,(*SizeArray)*sizeof(mus_comp));
		if (array_mu_co == NULL)
		{
			printf("Error associated with Realloc() in function add_in_array()!");
		}
	}

	array_mu_co[*number_in_array] = element_mu_co;
	return array_mu_co;
}

int output_info(mus_comp *array_mu_co, int number_in_array)
{
	if (array_mu_co == NULL) 
	{
		printf("Error associated with pointers in function output_info()!");
		return ERROR;
	}
	int i = 0;
	while (i != number_in_array) 
	{
		mus_comp element_mu_co;
		element_mu_co = array_mu_co[i];
		printf("\n INDEX[%d]\n Bit: %d \n Duration: %d \n Name: %s\n",i, element_mu_co.bit, element_mu_co.duration, element_mu_co.name);
		i++;
	}
}

int find_random_music_composition(mus_comp *array_mu_co, int number_in_array, int coun_element) 
{
	if (array_mu_co == NULL) 
	{
		printf("Error associated with pointers in function output_info()!");
		return ERROR;
	}
	int rand_bit = rand()%5 + 150;
	int rand_duration=rand()%20 + 240;
	int out_count = 1;
	int index = 0;
	printf(" Search for a track with parameters such as:\n Rhythm-> %d +-1 bit/min \n Duration -> %d +-5 second \n",rand_bit, rand_duration);
	while ((out_count != coun_element+1) && (index < number_in_array)) 
	{
		if ((abs(array_mu_co[index].bit - rand_bit) <= 1) && (abs(array_mu_co[index].duration - rand_duration) <= 5)) 
		{
				mus_comp element_mu_co = array_mu_co[index];
				printf("\n INDEX[%d]\n Bit: %d \n Duration: %d \n Name: %s\n",out_count, element_mu_co.bit, element_mu_co.duration, element_mu_co.name);
				++out_count;
		}
		index++;
	}
	if (out_count != coun_element + 1) printf("There are no more music tracks with such parameters.");
}

mus_comp create_struct_music_composition(char *strin, FILE *fin) 
{
	if (strin == NULL) 
	{
		printf("Error associated with pointers in function output_info()!");
		mus_comp element_mu_co;
		element_mu_co.duration = NULL;
		return element_mu_co;
	}
	char sbit[SIZE_NUMBER_IN_FILE+1],sduration[SIZE_NUMBER_IN_FILE+1],sname[MAX_SIZE_NAME];
	mus_comp element_mu_co;
	strncpy(sbit, &strin[0],SIZE_NUMBER_IN_FILE);
	element_mu_co.bit = atoi(sbit);
	strncpy(sduration, &strin[SIZE_NUMBER_IN_FILE+1],SIZE_NUMBER_IN_FILE);
	element_mu_co.duration = atoi(sduration);
	strcpy(element_mu_co.name, &strin[2*(SIZE_NUMBER_IN_FILE+1)]);
	return element_mu_co;
}