#include <stdio.h>
#include "header.h"
static const char* keywords[30] = {
    "int", "float", "return", "if", "else", "while", "for", "do", "break", "continue",
    "char", "double", "void", "switch", "case", "default", "const", "static", "sizeof", "struct"
};

static const char* operators = "+-*/%=!<>|&";
static const char* specialCharacters = ",;{}()[]";


int read_and_validate(char string[])
{
    char buffer[100];
    int count =0;
    FILE *fptr = fopen( string , "r");
    if( fptr == NULL)
    {
        printf("enter file is not exit\n");
        return FAILED;
    }
    else
    {
        while( fscanf(fptr,"%s",buffer) == 1)
        {
            //fscanf( fptr, "%s", buffer);
            //printf("%s ",buffer);
            checking_token(buffer);

        }
    }

}

checking_token( char buffer[])
{
    for( int num =0; num < 20 ; num++)
    {
        if( strcmp( buffer, keywords[num]) == 0 )
        {
            printf("keyword -> %s\n",buffer);
            return 0;
        }

    }

    if( strchr( operators,buffer[0] ) != NULL)
    {
        printf("operators -> %s\n",buffer);
        return 0;
    }



    if( strchr( specialCharacters,buffer[0] ) != NULL)
    {
        printf("operators -> %s\n",buffer);
        return 0;
    }
    return 0;

}
