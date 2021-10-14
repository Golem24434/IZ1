#include "function.h"

int main() {
	srand(time(NULL));
	mus_comp	*array_mu_co = (mus_comp*)malloc(sizeof(mus_comp));\
	if (array_mu_co == NULL) 
	{
		printf("Error associeted with malloc() in main()!");
	} 
	mus_comp element_mu_co;
	char 	strin[MAX_SIZE_STRING];
	int  	number_in_array, size_array = 1, input_count;
	FILE 	*fin = fopen("C:\\Users\\Omar\\Desktop\\Tehnopark_C_Cpp\\Second\\DataBase.txt", "r");
	if (fin == NULL) 
	{
		printf("Error! File with data can't open!");
		return 0;
	} 
	for (number_in_array = 0;number_in_array < 125;++number_in_array) {
		if (fgets(strin, MAX_SIZE_STRING, fin) == NULL) 
		{
			printf("Error with gets()!");
			return 0;
		}
		element_mu_co = create_struct_music_composition(strin, fin);
		if (element_mu_co.duration == NULL) 
		{
			return 0;
		}
		array_mu_co = add_in_array(array_mu_co, &size_array, &number_in_array, element_mu_co);
		if (array_mu_co == NULL) 
		{
			return 0;
		}
	}
	scanf("How many tracks do you want to see? %d",&input_count);
    if (find_random_music_composition(array_mu_co, number_in_array, input_count) == ERROR) 
	{
		return 0;
	}
	fclose(fin);
    return 0;
}
