#include <stdio.h>
#if 1
#include "header.h"
#include <unistd.h>
#include <string.h>
#endif

/*
 * Author: Anagh
 * Date: <++>
 * Description: <++>
 */
int read_and_validate( char string[]);
int main(int argc , char *argv[])
{
    char string[100];
    int i = 1;
    do{

        if( argc < 2 )
        {
            printf("\n---Invalid Input---\n");

        }
        else
        {
            strcpy( string, argv[1]);
            read_and_validate(string);
        }
        printf("\n---do you want to continue--\n1-> Continue\n2-> Exit\n-> ");
       // printf("Enter the file\n");
        scanf("%d",&i);
        getchar();

        printf("Enter the file\n");
        scanf("%s",string);
        strcmp( argv[1], string);
    }while( i == 1);
    return 0;
}



