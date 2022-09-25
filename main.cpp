#include "onegin.h"


int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "ru_RU.cp1251");

    FILE* fin = fopen(argv[1], "r");
    if(fin == NULL)
    {
        printf("Can't open the file!\n");
        abort();
    }  
   
    int num_of_bytes = count_bytes(argv[1]);

    char* buf = make_buf(fin, num_of_bytes);

    int count = count_str(buf, num_of_bytes);

    string* text = (string*)calloc(count, sizeof(string)); 
    if(text == NULL)
    {
        printf("Can't find the required memory block\n");
        abort(); 
    }

    make_str_array(text, buf, num_of_bytes);

    quick_sort(text, 0, count - 1, comp);

    FILE* fout = fopen("output.txt", "a");
    if(fout == NULL)
    {
        printf("Can't open the file!\n");
        abort();
    }

    //fprintf(fout, "reverrsed sorted text\n\n\n");
    //print_str_array(text, count, fout);
    
    fprintf(fout, "\n\nbuffer\n\n");
    print_buf(buf, num_of_bytes, fout);

    clear(text, buf);

    fclose(fin);
    fclose(fout);

    return 0;

}