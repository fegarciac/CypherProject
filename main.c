#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NO_MORE_THAN 5000
#define OR_LESS 15
#define LENGTH_NOTLESS 1500

int readFileOption1(){
    FILE *fptr;
    char **words=0;
    char DeclarationOfIndependence[5000];
    int numberWords=0;
    int w;
    printf("Enter the  name of a cipher text file: ");
    scanf("%s",&DeclarationOfIndependence);
    if((fptr=fopen(DeclarationOfIndependence,"r"))==0)
        printf("Error\n");
    else
    {
        words=malloc(NO_MORE_THAN*sizeof(char *));
        for(int i=0;i<NO_MORE_THAN;i++)
            words[i]=malloc(OR_LESS*sizeof(char));
        while(fscanf(fptr,"%s",words[numberWords])!=EOF)
        {
            ++numberWords;
        }
        printf("\nTotal words: %d\n",numberWords);
        for( w=0;w<numberWords;w++)
            for(int letter=0;words[w][letter]!='\0';letter++)
                if(words[w][letter]>='A' && words[w][letter]<='Z')
                    words[w][letter]='a' + (words[w][letter]-'A');
        for(int w=0;w<numberWords;w++)
            printf("\n%s",words[w]);
        fclose(fptr);
    }
    printf("\n");
    return 0;
}

int readFromInputBufferOption2(){
//read from user
//

//store their input in some sort of array

//use this array to
}



int readFromInputBuggerOption3(){
    FILE *fptr;
    char **words=0;
    char DeclarationOfIndependence[5000];
    int numberWords=0;
    int w;
    printf("Enter the  name of a cipher text file: ");
    scanf("%s",&DeclarationOfIndependence);
    if((fptr=fopen(DeclarationOfIndependence,"r"))==0)
        printf("Error\n");
    else
    {
        words=malloc(NO_MORE_THAN*sizeof(char *));
        for(int i=0;i<NO_MORE_THAN;i++)
            words[i]=malloc(OR_LESS*sizeof(char));
        while(fscanf(fptr,"%s",words[numberWords])!=EOF)
        {
            ++numberWords;
        }
        printf("\nTotal words: %d\n",numberWords);
        for( w=0;w<numberWords;w++)
            for(int letter=0;words[w][letter]!='\0';letter++)
                if(words[w][letter]>='A' && words[w][letter]<='Z')
                    words[w][letter]='a' + (words[w][letter]-'A');
        for(int w=0;w<numberWords;w++)
            printf("\n%s",words[w]);
        fclose(fptr);
    }
    printf("\n");
    return 0;
}
int main(){
    int option;
    int nwords;
    char **keyWords;
    char*fileName;
    printf("Choose an option from thr menu below:\n");
    printf(" 1 - Read in the name of a text file to use as a cipher key\n");
    printf(" 2 - Create a cipher using the input text file (and save the result to a file\n");
    printf(" 3 - Decode an existing cipher (prompt user for a file to read containing the cipher text\n");
    printf(" 4 - Exit\n");
    scanf("%d", &option);
    if(option == 1){
        readFileOption1();
    }
    else if(option == 2){
        readFileOption1();
    }
    else if(option == 3){
        readFromInputBuggerOption3();
    }
}