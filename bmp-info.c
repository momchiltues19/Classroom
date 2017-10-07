void bmp_info(char *);

int main(/*char* argv[]*/)
{
    bmp_info("2020.bmp");
    return 0;
}

void bmp_info(char *file_name)
{
    int32_t width, height;
    uint8_t *f;
    f = read_image(file_name);
    width = *(f+18);
    height = *(f+22);
    printf("BMP image width: %d\nBMP image height: %d\n", width, height);
}
