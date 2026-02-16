#define YEAR_MASK 0xFE00
#define MONTH_MASK 0x01E0
#define DAY_MASK 0x001F



uint16_t pack_dos_date(int year, int month, int day)
{
    // 
    uint16_t packed = 0;
    packed = (year - 1980) << 9;
    // packed after
    // 0101101 0000 00000 this is what the packed looks like with our sample year month day after shifting
    
    //month variable
    packed |= (month << 5);
    // Equal to packed = packed | (month << 5);

    packed |= (day);
    return packed;
}

int get_year(uint16_t dos_date)
{
    // uint16_t upper_seven_bits = dos_date & 0xFE00;
    // uint16_t upper_seven_bits = dos_date & 0b1111111000000000;
    // uint16_t shifted = upper_seven_bits >> 9;

    // return shifted
    return ((dos_date & 0b1111111000000000) >> 9) + 1980;
}

int get_month(uint16_t dos_date) 
{
    return(dos_date & 0b0000000111100000) >> 5;
}

int get_day(uint16_t dos_date)
{
    return(dos_date & 0b0000000000011111);
}

void print_bit(uint16_t value)
{
    for (int i = 15; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
        if (i == 3 || i == 9) printf(" ");
    }
}