
#include "ebox_mem.h"
#include "ebox_printf.h"
#include "ebox.h"

void ebox_printf(const char *fmt, ...)
{
    char *buf;
    int     size1 = 0;
    size_t  size2 = 32;
    va_list va_params;

    va_start(va_params, fmt);
    
    do{
        buf = (char *)ebox_malloc(size2);
        if(buf == NULL)
            return ;
        size1 = vsnprintf(buf, size2,fmt, va_params);
        if(size1 == -1  || size1 > size2)
        {
            size2+=32;
            size1 = -1;
            ebox_free(buf);
        }
    }while(size1 == -1);

    va_end(va_params);
    uart1.write(buf,size1);
    ebox_free(buf);

}




































//#pragma import(__use_no_semihosting)
//_sys_exit(int x)
//{
//x = x;
//}
//struct __FILE
//{
//int handle;
// 
// 
// 
//};
// 
//FILE __stdout;
//int fputc(int ch, FILE *f)
//{
//    uint8_t *p;
//    *p = ch;
//    my_fifo_put(x_ptr,p,1);
//    return ch;
//}

//_ttywrch(int ch)
//{
//ch = ch;
//}
