//Author:DEADPOOL
//User@DEADPOOL
//Device name:LAPTOP-MGJPSU5N
//***************************
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// dlt function definition
 void dlt(char str[],char c){
    int j,len=strlen(str);// storing the length of string in len
    for (int i = j = 0; i < len ; i++)
        if (str[i]!=c)
           str[j++]=str[i];//stores the value of str[i] in str[j], then increase the value of j
    str[j]='\0';
 }

 // palindrome function definition
int palindrome(char str[]){
    int l = 0;//pointing to left most element
    int n = strlen(str) - 1;// pointing to right most element
  // comparing the characters from each side
    while (n > l){
        if (str[l++] != str[n--]){

            return 1;
        }
    }
    return 0;
}



// main function
int main(){
    int len=20;
    char *str= malloc(len * sizeof(char));// initially capacity of str is 20 byte
    int flag=0,count=0;
    char c;
    system("color 3");
    printf("\n enter the string :");

    while((c = getchar()) != '\n'){
        if (count >= (len-1))//if the string will very large then realloc() the str
            str = realloc( str ,(len += 10)*sizeof(char));
        str[count++] = c;// stores the value of c in str[count] then increases the value of count by 1
    }
    str[count]='\0';// adding a null character to the end of the string so that i can use strlen()
    printf("\n\aEntered string is : %s",str);
   //removing the unwanted characters ...
    system("color 4");
    printf("\n\aEnter the character  you want to remove : ");
    scanf("%c",&c);
    dlt(str,c);
    printf("\nAfter removing the character from the string : %s",str);
  //squeezing the string ....
    dlt(str,' ');
    printf("\nThe string squeezed to  :  %s",str);
  //checking for palindrome  .....
    flag = palindrome(str);
    //initially flag=0  , if string is not a palindrome then the palindrome() returns 1....
    if (flag == 1)
        printf("\n\aResultant string is not a palindrome......");
    else
        printf("\n\aResultant string is a palindrome ");

return 0;
}
