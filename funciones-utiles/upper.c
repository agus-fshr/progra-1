void upper(char * str){
    for (int i=0; i<str_len(str); i++){
        if ((*(str+i)>='A') && (*(str+i)<='Z')){
            *(str+i) = *(str+i) - ('a'-'A');
        }
    }
}
