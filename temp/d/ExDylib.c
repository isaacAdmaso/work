#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>

typedef int (*PtrFunc)(int*,int*);


int main(int argc, char const *argv[])
{
    int num1,num2;
    char ch,func_name[8],*error;
    void* handle;
    PtrFunc func;

    if (argc != 4)
    {
        printf("invalid input");
        return 1;
    }    
    num1 = atoi(argv[1]);
    num2 = atoi(argv[3]);
    ch = argv[2][0];
    switch(ch)
    {
        case '+':
            handle = dlopen("./libAdd.so", RTLD_LAZY);
            strcpy(func_name,"Add_F");
            break;
        case '-':
            handle = dlopen("./libSub.so", RTLD_LAZY);
            strcpy(func_name,"Sub_F");
            break;
        case '*':
            handle = dlopen("./libMult.so", RTLD_LAZY);
            strcpy(func_name,"Mult_F");
            break;
        case '/':
            handle = dlopen("./libDiv.so", RTLD_LAZY);
            strcpy(func_name,"Div_F");
            break;
        default:
            break;
    }
    if (!handle)
    {
        fputs("Error", stderr);
        exit(1);
    }

    func = (PtrFunc) dlsym(handle, func_name);

    if ((error = dlerror()) != NULL)
    {
        fputs("Error", stderr);
        exit(1);
    }

    printf("%s %s %s = %d",argv[1],argv[2],argv[3],func(&num1,&num2));
    dlclose(handle);

    return 0;
}

