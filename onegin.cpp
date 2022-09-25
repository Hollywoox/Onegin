#include "onegin.h"


int count_bytes(char* adr)
{
    struct stat data = {};
    stat(adr, &data);
    return (int)data.st_size;
}

char* make_buf(FILE* fp, int num_of_bytes)
{
    char *buf = (char*)calloc(num_of_bytes + 1, sizeof(char));
    if(buf == NULL)
    {
        printf("Can't find the required memory block\n");
        abort(); 
    }

    int read = fread(buf, sizeof(char), num_of_bytes, fp);
    if(read != num_of_bytes) 
    {
        printf("Can't read from the file\n");
        abort();
    }
    *(buf + read) = '\0';

    return buf;
}

int count_str(char* buf, int num_of_bytes)
{
    int count = 1;
    for(int i = 0; i < num_of_bytes; i++){
        if(buf[i] == '\n')
        {
            ++count;
            buf[i] = '\0';
        }
    }
    
    return count;
}

void make_str_array(string* text, char* buf, int num_of_bytes)
{
    char *begin_of_str = buf;
    char *end_of_str = buf;
    int  num_of_str = 0;

    for(int i = 0; i <= num_of_bytes; ++i)
    {
        if(i == num_of_bytes)
        {
           text[num_of_str].str = begin_of_str;
           text[num_of_str].size = end_of_str - begin_of_str; 
           break;
        }

        if((*end_of_str) == '\0')
        {
            text[num_of_str].str = begin_of_str;
            text[num_of_str].size = end_of_str - begin_of_str;
            
            ++num_of_str;
            begin_of_str = end_of_str + 1;
        }    

        end_of_str = end_of_str + 1;
    }
}

int comp(const void* aPtr, const void* bPtr)
{
    int str1_size = ((string*)aPtr)->size; 
    if(str1_size == 0) return -1;

    int str2_size = ((string*)bPtr)->size;
    if(str2_size == 0) return 1;

    char* str1 = ((string*)aPtr)->str;
    char* str2 = ((string*)bPtr)->str;

    int i = 0;
    int j = 0;
    while(i < str1_size && j < str2_size)
    {
        while(!isalpha(*(str1 + i)) && i < str1_size - 1) ++i;
        while(!isalpha(*(str2 + j)) && j < str2_size - 1) ++j;

        if(i == str1_size - 1 && !isalpha(*(str1 + i))) return -1;
        if(j == str2_size - 1 && !isalpha(*(str2 + j))) return 1;

        if((int)(*(str1 + i)) > (int)(*(str2 + j))) return 1;
        if((int)(*(str1 + i)) < (int)(*(str2 + j))) return -1; 

        ++i;
        ++j;

        if(i == str1_size && j != str2_size) return -1;
        if(i != str1_size && j == str2_size) return 1;
    }

    return 0;
}

int comp_reverse(const void* aPtr, const void* bPtr)
{
    int str1_size = ((string*)aPtr)->size; 
    if(str1_size == 0) return -1;

    int str2_size = ((string*)bPtr)->size;
    if(str2_size == 0) return 1;

    char* str1 = ((string*)aPtr)->str + str1_size - 1;
    char* str2 = ((string*)bPtr)->str + str2_size - 1;

    int i = 0;
    int  j = 0;
    while(i < str1_size && j < str2_size)
    {
        while(!isalpha(*(str1 - i)) && i < str1_size - 1) ++i;
        while(!isalpha(*(str2 - j)) && j < str2_size - 1) ++j;

        if(i == str1_size - 1 && !isalpha(*(str1 - i))) return -1;
        if(j == str2_size - 1 && !isalpha(*(str2 - j))) return 1;

        if((int)(*(str1 - i)) > (int)(*(str2 - j))) return 1;
        if((int)(*(str1 - i)) < (int)(*(str2 - j))) return -1; 

        ++i;
        ++j;

        if(i == str1_size && j != str2_size) return -1;
        if(i != str1_size && j == str2_size) return 1;
    }

    return 0;
}

void swap(string* str1, string* str2)
{
    string exchange = *str1;

    *str1 = *str2;
    *str2 = exchange;
}

void bubble_sort(string* text, int num_of_str, int (*comp)(const void*, const void*))
{
    for(int i = 0; i < num_of_str; ++i)
    {
        for(int j = 1; j < num_of_str - i; ++j)
        {
            if(comp(&text[j - 1], &text[j]) > 0) swap(&text[j - 1], &text[j]);
        }
    }
}

void quick_sort(string* text, int first, int last, int (*comp)(const void*, const void*))
{
    int left, right, pivot;
    
    if(first < last)
    {
        pivot = first;
        left = first;
        right = last;

        while(left < right)
        {
            while(comp(&text[left], &text[pivot]) <= 0 && left < last) left++;
            while(comp(&text[right], &text[pivot]) > 0) right--;
            if(left < right)
            {
                swap(&text[left], &text[right]);
            }
        }

        swap(&text[pivot], &text[right]);
        quick_sort(text, first, right - 1, comp);
        quick_sort(text, right + 1, last, comp);
    }
}

void print_buf(char *buf, int num_of_bytes, FILE* fp)
{
    char *begin_of_str = buf;
    char *end_of_str = buf;

    for(int i = 0; i <= num_of_bytes; ++i)
    {
        if(i == num_of_bytes)
        {
            fprintf(fp, "%s", begin_of_str);
            fprintf(fp, "\n");
            break;
        }

        if((*end_of_str) == '\0')
        {
            fprintf(fp, "%s", begin_of_str);
            fprintf(fp, "\n");

            begin_of_str = end_of_str + 1;
        }

        end_of_str = end_of_str + 1;
    }
}

void print_str_array(string *text, int count_str, FILE* fp)
{
    for(int i = 0; i < count_str; ++i)
    {
        if(text[i].size != 0)
        {
            fprintf(fp, "%s", text[i].str);
            fprintf(fp, "\n");
        }
    }
}

void clear(string *text, char *buf)
{
    free(text);
    text = NULL;

    free(buf);
    buf = NULL;
}