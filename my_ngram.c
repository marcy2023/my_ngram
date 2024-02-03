#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void function_sorting_string(char *str) {
    int i,j,size;
    size = strlen(str);
    for (i = 1; i < size; i++) {
        j = i - 1;
        char temporary = str[i];
        while (j >= 0 && str[j] > temporary) {
            str[j + 1] = str[j];
            j--;
        }
        str[j + 1]=temporary;
    }
}

void my_ngram(char *text) {
    function_sorting_string(text);
    int size = strlen(text);
    char *arr = malloc(size * sizeof(char));
    int letter_count = 0;

    for (int i = 0; i < size; i++) {
        if (strchr(arr, text[i]) == NULL) {
            arr[letter_count] = text[i];
            letter_count = letter_count +1;
            int letter_counter = 0;

            for (int c = 0; c < size; c++)
            {
                if (text[i] == text[c])
                {
                    letter_counter = letter_counter +1;
                }
            }       
            printf("%c:%d\n", text[i], letter_counter);
        }
    }
    free(arr); 
}

int main(int argc, char** argv) {
     if(argc > 1)
     {
         my_ngram(argv[1]);
     }
    return 0;
}
