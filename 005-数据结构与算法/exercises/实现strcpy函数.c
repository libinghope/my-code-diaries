//已知stpy函数的原型是：char*strcpy(char*strDest,constchar*strSrc);
#define NULL 0
char* strcpy(char* strDest,const char *strSrc){
    if(!strDest || !strSrc) return NULL;

    char * ret = strDest;
    while ((*strDest++ = *strSrc++)!='\0');
    
    return ret;
}