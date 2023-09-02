// 大端模式：数据的低位放在内存高地址中，数据的高位放在内存低地址中
// 小端模式：数据的低位放在内存低地址中，数据的高位放在内存高地址中
#include <stdio.h>

int main()
{
    union Test // 联合体中成员共用内存空间
    {
        unsigned int n; // 4字节
        char arr[4]; // 4个1字节的字符变量
    };

    union Test num;
    num.n = 0x12345678; // 305419896
    // 由于联合体成员共用内存空间，因此该变量的四字节也会分布在数组arr中

    for (int i = 0; i < 4; i ++)
        printf("arr[%d] = %p, arr[%d] = 0x%x\n", i, &num.arr[i], i, num.arr[i]);
    
    /* 输出如下：
        arr[0] = 000000000061FE18, arr[0] = 0x78
        arr[1] = 000000000061FE19, arr[1] = 0x56
        arr[2] = 000000000061FE1A, arr[2] = 0x34
        arr[3] = 000000000061FE1B, arr[3] = 0x12
        数据的低位在内存的低地址中，数据的高位在内存的高地址中，这说明本机是小端模式
    */

    return 0;
}