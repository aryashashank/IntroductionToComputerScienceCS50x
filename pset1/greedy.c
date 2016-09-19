#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(){
float change;
double in;
double count=0;
do{
    printf("O hai! How much change is owed?\n");
    change=GetFloat();
}
while(change<0);
change = modf(change, &in);
change = roundf(change * 100);
in*=4;

while(change>0){
    if(change>=25){
        change-=25;
    }
    else if(change>=10){
        change-=10;
    }
    else if(change>=5){
        change-=5;
    }
    else if(change>=1){
        change-=1;
    }
count++;
}
printf("%g\n",count+in);


return 0;
}