# include "stdio.h"
# include "stdlib.h"

//enum DAY {
//	MON = 1, TUE, WED, THU, FRI, SAT, SUN
//} day;
//
//int main() {
//	for (day = MON; day <= SUN; ++day) {
//		printf("枚举元素：%d\n", day);
//	}
//}


int main()
{
    enum color { red=1, green, blue };
 
    enum  color favorite_color;
 
    /* 用户输入数字来选择颜色 */
    printf("请输入你喜欢的颜色: (1. red, 2. green, 3. blue): ");
    scanf("%u", &favorite_color);
 
    /* 输出结果 */
    switch (favorite_color)
    {
    	case red:
    		printf("你喜欢的颜色是红色");
    		break;
    	case green:
        	printf("你喜欢的颜色是绿色");
        	break;
    	case blue:
        	printf("你喜欢的颜色是蓝色");
        	break;
    	default:
        	printf("你没有选择你喜欢的颜色");
    }

    return 0;
}

