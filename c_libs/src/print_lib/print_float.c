void print_int(int number);
void print_char(char c);

void print_float(float number, int precision)
{
    int integer_part = (int)number;

    print_int(integer_part);
    if (precision > 0) {
        print_char('.');
    } else {
        return;
    }
    if (integer_part >= 0) {
        number = number - integer_part;
    } else {
        number = (number * (-1)) - (integer_part * (-1));
    }
    for (int i = 1; i <= precision; i++) {
        number = number * 10;
        integer_part = (int)number;
        print_int(integer_part);
        number = number - integer_part;
    }
}