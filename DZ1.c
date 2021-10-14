#include "function.h"

int main() {
	srand(time(NULL));
	MusComp	*ArrayMuCo = (MusComp*)malloc(sizeof(MusComp));\
	if (ArrayMuCo == NULL) 
	{
		printf("Error associeted with malloc() in main()!");
	} 
	MusComp ElementMuCo;
	char 	strin[MAX_SIZE_STRING];
	int  	NumberInArray, SizeArray = 1, inputCount;
	FILE 	*fin = fopen("C:\\Users\\Omar\\Desktop\\Tehnopark_C_Cpp\\Second\\DataBase.txt", "r");
	if (fin == NULL) 
	{
		printf("Error! File with data can't open!");
	} 
	for (NumberInArray = 0;NumberInArray < 125;++NumberInArray) {
		if (fgets(strin, MAX_SIZE_STRING, fin) == NULL) 
		{
			printf("Error with gets()!");
		}
		ElementMuCo = create_struct_music_composition(strin, fin);
		if (ElementMuCo.duration == NULL) 
		{
			return 0;
		}
		ArrayMuCo = add_in_array(ArrayMuCo, &SizeArray, &NumberInArray, ElementMuCo);
		if (ArrayMuCo == NULL) 
		{
			return 0;
		}
	}
	scanf("How many tracks do you want to see? %d",&inputCount);
    if (find_random_music_composition(ArrayMuCo,NumberInArray,inputCount) == ERROR) 
	{
		return 0;
	}
	fclose(fin);
    return 0;
}
