// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Sadman"
#define YEAR "2022"

int main() {
    // Write C code here
    printf("*****************************\n");
    printf("%s\n", TITLE);
    printf("%s %s\n", "Written by:", AUTHOR);
    printf("%s %s\n", "Date:", YEAR);
    printf("*****************************\n");
    
    printf("%s", "Enter a decimal number: ");
    int num;
    scanf("%d", &num);
    
    while(num>0){   //First take num value then enter the while loop
    printf("%s %d\n", "The decimal number you have entered is", num);
    
    printf("%s", "Enter a radix for the converter between 2 and 16: ");
    int radix;
    scanf("%d", &radix);
    printf("%s %d\n", "The radix you have entered is", radix);
    printf("%s %.2f\n", "The log2 of the number is", log2(num));
    printf("%s %d %s %d\n", "The integer result of the number divided by", radix, "is", (num/radix));
    printf("%s %d\n", "The remainder is", (num%radix));
    Dec2RadixI(num, radix);
    printf("%s\n", "Enter a decimal number: ");
    scanf("%d", &num);
    
    }
    printf("%s", "EXIT");
    
    return 0;
}

void Dec2RadixI(int decValue, int radValue){
    char values[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E','F'};
    char convert_array[10000];      
    convert_array[0]= '0';          //To deal with user entering 0
    int i=0;
    while (decValue > 0){
        int mod;
        mod = decValue%radValue;
        convert_array[i]= values[mod];      // finds character in particular base and adds it to array
        decValue = decValue/radValue ;       // divides decimal number for next iteration
        i++;
    }
    char reverse_array[i+1];        // to reverse array since numbers assigned from left to right
    for (int j=0; j<i; j++){
        reverse_array[j] = convert_array[i-j-1];
    }
    printf("The radix-%d value is %s\n", radValue, reverse_array);
    

}