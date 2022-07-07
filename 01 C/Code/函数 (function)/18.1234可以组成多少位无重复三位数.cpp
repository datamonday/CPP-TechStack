#include <stdio.h>
#include <stdint.h>
// 有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？


int main()
{
    uint32_t i; // 百位
    uint32_t j; // 十位
    uint32_t k; // 个位
    
    for (i=1; i<5; i++)
    {
        for (j=1; j<5; j++)
        {
            // 百位与十位重复
            // 跳过当前十位
            if (j==i)
            {
                continue;
            }
            
            for (k=1; k<5; k++)
            {
                // 个位与百位或十位重复
                // 跳过当前个位
                if (k==j || k==i)
                {
                    continue;
                }
                
                printf("%u,%u,%u\n", i, j, k);
            }
        }
    }
}
