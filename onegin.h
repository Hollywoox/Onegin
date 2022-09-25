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


int count_bytes(char* adr); 

char* make_buf(FILE* fp, int num_of_bytes);

int count_str(char* buf, int num_of_bytes);

void make_str_array(string* text, char* buf, int num_of_bytes);

int comp(const void* aPtr, const void* bPtr);

int comp_reverse(const void* aPtr, const void* bPtr);

void swap(string* str1, string* str2);

void bubble_sort(string* text, int num_of_str, int (*comp)(const void*, const void*));

void quick_sort(string* text, int first, int last, int (*comp)(const void*, const void*));

void print_buf(char* buf, int num_of_bytes, FILE* fp);

void print_str_array(string* text, int num_of_str, FILE* fp);

void clear(string* text, char* buf);