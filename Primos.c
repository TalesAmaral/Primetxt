#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Pra funcionar, vc cria um arquivo chamado PRimos.txt e coloca o 2, aperta enter, coloca o 3, aperta enter, coloca o 5, aperta enter. Pronto! Está funcional
unsigned long long int b;
unsigned long long int countLines(FILE* f){
    unsigned long long int a;
    scanf("%llu",&b);
    a=b;
    char ch;
    while((ch=getc(f)) != EOF){
        if (ch == '\n')a++;
    }
    return a;
}
int main(){
    FILE *texto;
    if ((texto= fopen("Primos.txt","a+"))==NULL){
        printf("Erro n abriu vei");
        return 0;
    }else{
        char str[100];
        char * eptr;
        unsigned long long int* listaP = (unsigned long long int*) malloc(countLines(texto)*sizeof(unsigned long long int));
        unsigned long long int index=0;
        rewind(texto);
        while(fscanf(texto,"%llu\n",&listaP[index]) == 1){
            index++;
        }
        unsigned long long int primo = listaP[index-1]+2;
        for(int i=0;i<b;i++){
            int bol =1;
            while (bol){
                int j=0;
                while (listaP[j]<(sqrtl(primo)+1)){
                    if (!(primo%listaP[j])){
                            bol =0;
                            break;
                    }
                    j++;
                }
                if (bol){
                    listaP[index] = primo;
                    index++;
                    fprintf(texto,"%llu\n",primo);
                    bol = 0;
                }else{
                    bol = 1;
                }
                primo+=2;

            }
        }
        fclose( texto );
    }
    return 0;
}
