#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef MAX
#define MAX 1000
#endif
#define NO_MORE_THAN 5000
#define OR_LESS 15
#define LENGTH_NOTLESS 1500
#define MAXC 256
char **words = 0;
int numberWords = 0;
char longerString[150];
char findletterinText(int wordNumber, int charNumber);
void promptKeyFromUserOption2Helper2();
int generateRandomIthwithGMULast4();

void printMenu(){
    printf("------------------------------------\n");
    printf("Choose an option from the menu below:\n");
    printf(" 1 - Read in the name of a text file to use as a cipher key\n");
    printf(" 2 - Create a cipher using the input text file (and save the result to a file)\n");
    printf(" 3 - Decode an existing cipher (prompt user for a file to read containing the cipher text\n");
    printf(" 4 - Exit\n");
}
int readFileOption11() {

    FILE *fptr;
    int w,i, letter;
    char inputFileName[5000]="";
    size_t ln;
    int c;
    scanf("%*c");
/* discard all characters up to and including newline */


    printf("\nEnter the  name of a cipher text file: ");
    fgets (inputFileName, MAXC, stdin);

    printf("inputFileName: %s",inputFileName);
    ln = strlen(inputFileName) - 1;
    if (*inputFileName && inputFileName[ln] == '\n') {
        inputFileName[ln] = '\0';
    }


    if ((fptr = fopen(inputFileName, "r")) == 0)
        printf("\nError\n");
    else {
        words = malloc(NO_MORE_THAN * sizeof(char *));
        i=0;
        for ( i = 0; i < NO_MORE_THAN; i++)
            words[i] = malloc(OR_LESS * sizeof(char));

        while (fscanf(fptr, "%s", words[numberWords]) != EOF) {
            ++numberWords;
        }

        for (w = 0; w < numberWords; w++){
            letter=0;
            for ( letter = 0; words[w][letter] != '\0'; letter++){
                if (words[w][letter] >= 'A' && words[w][letter] <= 'Z'){
                    words[w][letter] = 'a' + (words[w][letter] - 'A');
                }

            }

        }
        fclose(fptr);

    }
    printf("\n");
    return 0;
}


int readFileOption3() {

    char inputFileName[MAXC] = {0};
    char *fptr = inputFileName;
    char pco [MAXC];
    FILE *fp;
    char buff[255];
    char buf[MAXC] = {0};
    char *p = buff;
    char decodedText[100];
    int ii=0;
    int iii=0;
    int a, b, numberOfPais=0;
    char arr[200][200];
    char c;
    int mapping[100][100];
    int even=1;
    size_t ln;
    char * token;
    fflush(stdin);
    scanf("%*c");
    printf ("\nEnter file name containing an encoded text: ");
    fgets (inputFileName, MAXC, stdin);

    stpcpy(pco, inputFileName);

    ln = strlen(pco) - 1;
    if (*pco && pco[ln] == '\n') {
        pco[ln] = '\0';
    }


    printf("%s\n", inputFileName);


    fp = fopen(pco, "r");
    fscanf(fp, "%s", buff);
    fflush(stdin);

    for (p = strtok (buff, " "); p; p = strtok (NULL, " \n")){
        printf ("   %s\n", p);
        strcpy(arr[ii++],p);
    }


    while(ii>-1){
        token = strtok(arr[iii++], ", \t");
        even=1;
        while( token != NULL ) {
            if (even){
                a=atoi(token);
                even=0;
            }else {
                b=atoi(token);
                even=1;
                c = findletterinText(a,b);
                printf( "%c", c);

            }
            token = strtok(NULL, ", \t");

        }
        ii--;
    }
    printf("\n");
}

void clearMem(int memory[]){
    int i=0;
    for (i=0; i<50; i++){
        memory[i] =-1;
    }
}
char * readFromInputBufferOption22() {
    char key[1500];
    int ii= 0;
    char buffer[MAX];
    char buffer2[MAX];
    int kArray[128];
    char value [128] ;
    int w, y, k, keysFound=0,goback=0;
    int numberOfMatches=0;
    char* str1 = " ";
    int keyCharFound=0;
    int emptybefore=1;
    int n= strlen(key);
    int memory[50];
    int r, xx, memcounter=0;
    char *num;
    char t;
    int i = 0;
    char cc;
    int ctr=0;
    int m=0;
    int saveLastMatchWordNumber;

    scanf("%*c");
    promptKeyFromUserOption2Helper2(key);

    for(y=0;y< strlen(key)-1;y++) {


        numberOfMatches=0;
        clearMem(memory);
        memcounter=0;
        r = generateRandomIthwithGMULast4();
        if (key[y] == ' ') {
            printf ("something here? \n");
            strcat(longerString, " ");
            emptybefore=1;
        } else {
            for (w = 0; w < numberWords; w++) {
                if (keysFound == strlen(key)) {
                    w=numberOfMatches;
                }


                for (ii = 0; ii < strlen(words[w]); ii++) {
                    t=words[w][ii];
                    k=key[ii];

                    if (key[y] == words[w][ii]) {
                        /*                printf("------------------------------------------\n");
                                        printf("key being searched: %c ", key[y]);
                                        printf("iteration  w %d\n", w);
                                        printf("numberOfMatches %d\n", );
                                        printf("------------------------------------------\n");
                                        printf("wrote to memory[%d][%d]\n" , memcounter, w);*/

                        numberOfMatches++;

                        memory[memcounter++] = w;
                        k++;
                        if (r == numberOfMatches) {

                            keysFound++;


                            memset(buffer, 0, sizeof buffer);
                            memset(buffer2, 0, sizeof buffer2);
                            xx = memory[goback];

                            if (asprintf(&num, "%d", w) == -1) {
                                perror("asprintf");
                            } else {
                                if(y>0){
                                    strcat(strcpy(buffer, ","), num);
                                    emptybefore=0;
                                }else{
                                    strcat(strcpy(buffer, ""), num);
                                }

                                strcat(longerString, buffer);
                                free(num);

                                if (asprintf(&num, "%d", ii) == -1) {
                                    perror("asprintf");
                                } else {
                                    strcat(strcpy(buffer2, ""), num);
                                    free(num);
                                }

                                strcat(longerString, ",");
                                strcat(longerString, buffer2);
                                ii=strlen(words[w]);
                                w=numberWords;
                            }
                        }
                    }

                }

            }

            if (numberOfMatches < r) {




                goback = r - numberOfMatches-1;
                i = 0;

                ctr=0;
                m=0;
                saveLastMatchWordNumber=memory[m];


                while ( goback> 0  ){
                    if(memory[m+1]!=-1) {
                        saveLastMatchWordNumber = memory[m++];
                    }
                    goback--;
                }
                ctr=m;
                for (i = 0; i < strlen(words[memory[ctr]]); i++) {
                    cc = words[memory[ctr]][i];
                    if (key[y] == words[memory[ctr]][i]) {

                        int n1 = 1234;
                        memset(buffer, 0, sizeof buffer);
                        memset(buffer2, 0, sizeof buffer2);
                        xx = memory[ctr];
                        if (asprintf(&num, "%d", xx) == -1) {
                            perror("asprintf");
                        } else {
                            if(y>0){
                                strcat(strcpy(buffer, ","), num);
                            }else{
                                strcat(strcpy(buffer, ""), num);
                            }

                            strcat(longerString, buffer);
                            free(num);
                            if (asprintf(&num, "%d", i) == -1) {
                                perror("asprintf");
                            } else {
                                strcat(strcpy(buffer2, ""), num);
                                free(num);
                            }
                            keysFound++;
                            strcat(longerString, ",");
                            strcat(longerString, buffer2);
                        }

                    }

                }
            }
            numberOfMatches = 0;
            w = 0;
        }
    }
    return longerString;
}

int generateRandomIthwithGMULast4() {
    int r= 0;
    r= rand()%10;
    return r;
}

void promptKeyFromUserOption2Helper2(char key[LENGTH_NOTLESS]) {
    int i;
    if (numberWords > 0) {
        fflush(stdin);
        printf("Enter the string to encode:" );
        fgets(key, 100, stdin);
        for(i=0; key[i]!='\0'; i++)
        {

            if(key[i]>='A' && key[i]<='Z')
            {
                key[i] = key[i] + 32;
            }
        }


    }
    else {
        printf("No file was loaded");
        readFileOption11();
    }
}



char findletterinText(int wordNumber, int charNumber){

    char targetC = words[wordNumber][charNumber];
    return targetC;
}



int readFromInputBuggerOption33() {
    FILE *fptr;
    char encodedText[1500];
    char *p=encodedText;
    int numberWords = 0;
    int i;
    char * token;
    printf("Enter the  name of a cipher text file: ");
    scanf("%s\n", &encodedText);


    for (p = strtok (encodedText, " "); p; p = strtok (NULL, " \n"))
        printf ("   %s\n", p);

    for( i=0; i<strlen(encodedText);i++){
        printf("[%d][%c]\n",i,encodedText[i]);
    }
    token = strtok(encodedText, ", \t");
    while( token != NULL ) {
        printf( " %s|\n", token );
        token = strtok(NULL, ", \t");
    }


    return 0;
}


int main() {
    int option;
    int nwords;
    char **keyWords;
    char *fileName;
    char *longerStrin;
    int x;
    srand((unsigned) 4138);


    while (1) {
        printMenu();

        x =  scanf("%d", &option);
        if (x == EOF) {
        } else if (x == 0) {
            fseek(stdin, 0, SEEK_END);
        }

        if (option == 1) {

            readFileOption11();

        } else if (option == 2) {
            longerStrin = readFromInputBufferOption22();
            printf("%s\n",longerStrin);
            memset(longerStrin, 0, 150);

        } else if (option == 3) {
            readFileOption3();
        }
        else if (option == 4) {
            return 0;
        }
        if (option == EOF) {
            /* ... you're not going to get any input ... */
        }
        if (option == 0) {
            while (fgetc(stdin) != '\n')
                ;
        }
        option=0;
    }
}