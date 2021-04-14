void print_str(char * w1){
    for (char c=0; c<str_len(w1); c++){
        printf("%c", *(w1+c));
    }
    printf("\n");
}
