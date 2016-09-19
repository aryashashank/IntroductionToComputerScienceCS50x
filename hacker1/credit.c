#include <cs50.h>
#include <stdio.h>

int main(){
    long long cardNumber, tempNum;
    printf("Number: ");
    cardNumber=GetLongLong();
    tempNum=cardNumber;
    int valid=0, simple=0, multiple=0,evenOddFlag=0,temp=0;
    while(tempNum>0){
        if(evenOddFlag==0){
            simple+=(tempNum%10);
            evenOddFlag=1;
        }
        else{
            temp=(tempNum%10)*2;
            while(temp>0){
                    multiple+=temp%10;
                    temp=temp/10;
                }
                evenOddFlag=0;
        }
        tempNum/=10;
    
}
if((simple+multiple)%2==0){
    valid=1;
}  
    int i=0;
    tempNum=cardNumber;
    if(valid == 1){
        while(tempNum){
        tempNum/=10;
        i++;
        }
        tempNum=cardNumber;
        if(i==16){
        if(tempNum/1000000000000000==4){
            printf("VISA\n");
        }
        else{
            printf("MASTERCARD\n");
        }
        }
        else if(i==15){
            printf("AMEX\n");
        }
        else if(i==14){
            printf("VISA\n");

        }
        
    }
    else{
        printf("INVALID\n");
    }
    
return 0;    
}
