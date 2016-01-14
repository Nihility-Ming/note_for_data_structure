# C语言复习

## 指针

所有的指针变量只占8个子节(32位系统占4字节）  用第一个字节的地址表示整个变量的地址

```C

int main(void)
{
    double *p;
    double x = 66.6;
    
    p = &x; // x占8个字节，1个字节是8位，1个字节一个地址
    
    double arr[3] = {1.1, 2.2, 3.3};
    double *q;
    
    q = &arr[0];
    printf("%p\n", q); // %p实际就是以十六进制输出
    q = &arr[1];
    printf("%p\n", q);
    
    return 0;
}

```


如何通过函数修改实参的值

```C
void f(int *i)
{
    *i = 9;
}

int main(void) 
{
    int i = 0;
    f(&i);
    printf("i = %d", i);
    return 0;
}
```

如何通过函数修改指针的值
```C
void f(int **q)
{
    *q = (int *)0xFFFFFFFF;
}

int main(void)
{
    int i = 9;
    int *p = &i;
    printf("%p\n", p);
    f(&p);
    printf("%p\n", p);
    return 0;
}
```

## 结构体
