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

    Text txt = {};
    
    CountBytes(&txt, argv[1]);

    MakeBuf(&txt, fin);

    CountStr(&txt);

    MakeStrArray(&txt);

    QuickSort(txt.str_array, 0, txt.num_of_str - 1, CompReverse);

    FILE* fout = fopen("output.txt", "a");
    if(fout == NULL)
    {
        printf("Can't open the file!\n");
        abort();
    }

    fprintf(fout, "\n\nreverrsed sorted text\n\n");
    PrintStrArray(&txt, fout);
    
    fprintf(fout, "\n\nbuffer\n\n");
    PrintBuf(&txt, fout);

    Clear(&txt);

    fclose(fin);
    fclose(fout);

    return 0;

}