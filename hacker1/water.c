#include <cs50.h>
#include <stdio.h>

int main(){
      int minutes;
      do{
          printf("minutes: ");
          minutes=GetInt();
      }
      while(minutes<=0);
       printf("bottles: %i\n",minutes*12);

    
}