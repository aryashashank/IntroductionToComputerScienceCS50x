#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[]){

    if(!argv[1] || atoi(argv[1])<0 || argv[2]){
        printf("Please enter a non negative integer\n");
        return 1;
    }
    int key = atoi(argv[1])%26;
    string str = GetString();
    for(int i=0, n=strlen(str);i<n;i++){
        if(str[i]>='a' && str[i]<='z'){
            if(str[i]+key>'z'){
            printf("%c",str[i]+key-26);    
            }
            else{
                printf("%c",str[i]+key);    
            }
        }
        else if(str[i]>='A' && str[i]<='Z'){
            if(str[i]+key>'Z'){
            printf("%c",str[i]+key-26);    
            }
            else{
                printf("%c",str[i]+key);    
            }
        }
        else{
            printf("%c",str[i]);
        }
    }
    printf("\n");
    return 0;
    
}
