[ 1]#include <stdio.h>
[ 2]#include <stdint.h>
[ 3]
[ 4]
[ 5]
[ 6]int main()
[ 7]{
[ 8]    uint32_t i; 
[ 9]    uint32_t j; 
[10]    uint32_t k; 
[11]    
[12]    for (i=1; i<5; i++)
[13]    {
[14]        for (j=1; j<5; j++)
[15]        {
[16]            
[17]            
[18]            if (j==i)
[19]            {
[20]                continue;
[21]            }
[22]            
[23]            for (k=1; k<5; k++)
[24]            {
[25]                
[26]                
[27]                if (k==j || k==i)
[28]                {
[29]                    continue;
[30]                }
[31]                
[32]                printf("%u,%u,%u\n", i, j, k);
[33]            }
[34]        }
[35]    }
[36]}
