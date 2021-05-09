int i;
char no_nro;

double detector(void)
{
    int c;
    double nro;
    double dec;
    char neg;
    char fin;
    while ((c = getchar()) && c != '\n')
    {
        if (c == '.'|| c == ',')
        {
            c = getchar();
            for (i = 0; c != '\n'; c = getchar(), ++i)
            {
            dec = dec*10.0;
            dec += c - '0';
            }
            while (dec >= 1)
            {
                dec = dec/10.0;
            }
            nro += dec;
            break;
        }
        else if (c >= '0' && c <= '9')
        {
            nro = nro*10.0; // +=     op1 = (op1 + op2)
            nro += c - '0'; // '0' = 48
        }
        else if (c == '-')
        {
            neg = 1;
        }
        else
        {
            no_nro = 1;
            break;
        }    
    }   
    if (neg == 1)
    {
        nro = nro*-1;
    }
    return nro;
}