#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]){

    if(!argv[1] || atoi(argv[1])<0 || argv[2]){
        printf("Please enter a non negative integer\n");
        return 1;
    }
    for(int i=0, n=strlen(argv[1]);i<n;i++){
        if(argv[1][i]<'A' || argv[1][i]>'z' || (argv[1][i]>'Z' && argv[1][i]<'a' ) ){
         printf("Please enter a non negative integer\n");
        return 1;    
        }
    } 
    string key = argv[1];
    int keyLen=strlen(key);
    for(int i=0, n=strlen(key);i<n;i++){
        key[i]=toupper(key[i]);
        key[i]-=65;
    }
        string str = GetString();
        for(int i=0,j=0, n=strlen(str);i<n;i++){
        int k= j%keyLen;
        if(str[i]>='a' && str[i]<='z'){
            if(str[i]+key[k] >'z'){
            printf("%c",str[i]+key[k]-26 );    
            }
            else{
                printf("%c",str[i]+key[k] );    
            }
        
            j++;
        }
        else if(str[i]>='A' && str[i]<='Z'){
            if(str[i]+key[k] >'Z'){
            printf("%c",str[i]+key[k] -26);    
            }
            else{
                printf("%c",str[i]+key[k] );    
            }
            j++;
        }
        else{
            printf("%c",str[i]);
        }
    }
    printf("\n");
    return 0;
    
}
