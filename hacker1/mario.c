#include <cs50.h>
#include <stdio.h>

int main(){
    int i, j, height;
    do{
    printf("Height: ");
    height=GetInt();
    }
    while(height<0 || height>23);
    
    for(i=1;i<=height;i++){
        for(j=1;j<=height-i;j++){
            printf(" ");
        }
        for(j=1;j<=i;j++){
            printf("#");
        }
        printf("  ");
        for(j=1;j<=i;j++){
            printf("#");
        }
        printf("\n");
    }
    
    
    return 0;
}