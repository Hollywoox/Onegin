#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/stat.h>
#include <locale.h>
#include <ctype.h>

typedef struct{
    char *str;
    int size;
} string;

/* counts the number of symbols(bytes) int the file */
int count_bytes(char* adr); 

/* makes a buffer for original text */
char* make_buf(FILE* fp, int num_of_bytes);

/* counts the number of strings in the text */
int count_str(char* buf, int num_of_bytes);

/* makes an array of strings */
void make_str_array(string* text, char* buf, int num_of_bytes);

/* compares two strings, returns 1 if the first string is bigger,
0 if they are equal, -1 if the second is bigger */
int comp(const void* aPtr, const void* bPtr);

/* compares two strings in reverse way, returns 1 if the first string is bigger,
0 if they are equal, -1 if the second is bigger */
int comp_reverse(const void* aPtr, const void* bPtr);

/* swaps two strings */
void swap(string* str1, string* str2);

/* algorithm of sorting in o(n^2) */
void bubble_sort(string* text, int num_of_str, int (*comp)(const void*, const void*));

/* algorithm of sorting in o(n*logn) */
void quick_sort(string* text, int first, int last, int (*comp)(const void*, const void*));

/* prints buffer */
void print_buf(char* buf, int num_of_bytes, FILE* fp);

/* prints the array of strings */
void print_str_array(string* text, int num_of_str, FILE* fp);

/* clears the memory */
void clear(string* text, char* buf);