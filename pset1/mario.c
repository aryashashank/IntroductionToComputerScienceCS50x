#include <cs50.h>
#include <stdio.h>

int main(){
    int i, j, height;
    do{
    printf("Height: ");
    height=GetInt();
    }
    while(height<0 || height>23);
    
    for(i=2;i<=height+1;i++){
        for(j=1;j<=height-i+1;j++){
            printf(" ");
        }
        for(j=1;j<=i;j++){
            printf("#");
        }
        printf("\n");
    }
    
    
    return 0;
}