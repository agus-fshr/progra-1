int str_len(char * str){
    int len = 0, i = 0;

    while (*(str+i) != '\0'){
        len++;
        i++;
    }

    return len;
}
