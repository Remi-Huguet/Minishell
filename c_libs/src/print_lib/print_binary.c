void print_int(int number);
void print_char(char c);

void print_binary(int number)
{
    int binary = 0;
    int mult = 1;

    if (number < 0)  {
        number = number * (-1);
        print_char('-');
    }
    while (number != 0) {
        int rest = number % 2;
        binary = binary + (mult * rest);
        mult = mult * 10;
        number = number / 2;
    }
    print_int(binary);
}