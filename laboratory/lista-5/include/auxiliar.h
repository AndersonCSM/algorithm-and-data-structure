#ifndef AUXILIAR_h
#define AUXILIAR_h

void gerar_array_aleatorio(int *arr[], int n);
void gerar_array_char_aleatorio(char *arr, int n);

void copiar_array_int(int *arr[], int *arr2[], int n);
void copiar_array_char(char *arr[], char *arr2[], int n);

int count_word(const char *text);
void extract_word(const char *text, char *word[], int n);
void free_word(char *text[], int n);

void sorting_switch(int opc, int *ordenado, int size);
void sorting_switch_c(int opc, int *ordenado, int size);

#endif