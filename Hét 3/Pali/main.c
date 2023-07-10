#include <stdio.h>
#include <stdlib.h>

int palindrome(int* arr,int length)
{
    for(int i=0; i<length; i++)
    {
        if(arr[i] == arr[length-i-1])
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int main()
{
    int number1,number2,length=0;
    printf("Give me the number: \n");
    scanf("%i",&number1);
    number2 = number1;

    while(number1 != 0)
    {
        number1=number1/10;
        length++;
    }

    int *arr;
    arr = (int*)calloc(length,sizeof(int));

    for(int i=length; i>=0; i--) /// Valami Hiba van itt
    {
        arr[i]=number2%10;
        number2=number2/10;
    }

    printf("number: \n");
    for(int i=0; i<length; i++)
    {
        printf("%i",arr[i]);
    }

    int x = palindrome(*arr,length);

    if(x == 1)
    {
        printf("A szamsorozat palindrome!\n");
    }
    else
    {
        printf("A szamsorozat nem plaindrome!\n");
    }

    return 0;
}
