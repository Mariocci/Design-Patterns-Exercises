#include <stdio.h>
#include <string.h>

const void* mymax(
    const void *base, size_t nmemb, size_t size,
    int (*compar)(const void *, const void *)){

    const unsigned long *maximum = base;

	for (size_t i = 1, offset = size; i < nmemb; ++i, offset += size) {
		const unsigned long *temp = base + offset;
		if (compar(temp, maximum) == 1) {
			maximum = temp;

		}
	}
	return maximum;
}

int gt_int(const void *a, const void *b) {
    if (*(int*)a <= *(int*)b){
        return 0;
    }
    return 1;
}
int gt_char(const void *c1, const void *c2) {
	if (*(char*)c1 <= *(char*)c2){
        return 0;
    }
    return 1;
}
int gt_str(const void *s1, const void *s2) {
	int result = strcmp(*(const char**)s1, *(const char**)s2);
    return result >= 0 ? 1 : 0;
}

int main(){

    int arr_int[] = { 1, 3, 5, 7, 4, 6, 9, 2, 0 };
    char arr_char[]="Suncana strana ulice";
    const char* arr_str[] = {
    "Gle", "malu", "vocku", "poslije", "kise",
    "Puna", "je", "kapi", "pa", "ih", "njise"};

    for (int j = 0; j < 3; j++){
        if(j==0){
            printf("Maximum of (");
            for (int i = 0; i < 20; ++i) {
		        printf("%c", arr_char[i]);
		        if (i != 19) printf(", ");
	        }
            printf(") = %c\n", *(char*)mymax(arr_char, 20, sizeof(char), gt_char));
        }
        if(j==1){
            printf("Maximum of (");
            for (int i = 0; i < 9; ++i) {
		        printf("%d", arr_int[i]);
		        if (i != 8) printf(", ");
	        }
            printf(") = %d\n", *(int*)mymax(arr_int, 9, sizeof(int), gt_int));
        }
        if(j==2){
            printf("Maximum of (");
            for (int i = 0; i < 11; ++i) {
		        printf("%s", arr_str[i]);
		        if (i != 10) printf(", ");
	        }
            printf(") = %s\n", *(char**)mymax(arr_str, 11, sizeof(char*), gt_str));
        }
    }
    return 0;
}