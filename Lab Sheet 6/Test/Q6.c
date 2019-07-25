#include <stdio.h> 
#include <string.h> 
  
void printSubStr(char* str, int low, int high) 
{ 
    for(int i=low;i<=high/2;i++)
    {
        if(str[i]>str[i+1])
        {
            printf("-1");
            return;
        }
    }

    for(int i=low;i<=high;i++) 
        printf("%c", str[i]); 
} 
  
void longestPalSubstr(char *str) 
{ 
    int maxLength = 1;  
    int start = 0; 
    int len = strlen(str); 
    int low, high; 

    for (int i=1;i<len;i++) 
    {    
        low = i-1; 
        high = i; 
        while (low >= 0 && high < len && str[low] == str[high]) 
        { 
            if (high-low+1 > maxLength) 
            { 
                start = low; 
                maxLength = high-low+1; 
            } 
            --low; 
            ++high; 
        } 
  
        low = i-1; 
        high = i+1; 
        while (low >= 0 && high < len && str[low] == str[high]) 
        { 
            if (high-low+1 > maxLength) 
            { 
                start = low; 
                maxLength = high-low+1; 
            } 
            --low; 
            ++high; 
        } 
    } 
    printSubStr(str, start, start+maxLength-1);  
} 

int main() 
{
    char str[100];
    scanf("%s",str);
    longestPalSubstr(str); 
}