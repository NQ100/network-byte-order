#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <netinet/in.h>

uint32_t read_file(const char* filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Failed to open file: %s\n", filename);
        exit(1);
    }

    uint32_t number;
    size_t count = fread(&number, 1, sizeof(uint32_t), file);
    if (count != sizeof(uint32_t)) {
        printf("Failed to read data from file: %s\n", filename);
        exit(1);
    }

    fclose(file);
    return ntohl(number);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("syntax : add-nbo <file1> <file2>\n");
        printf("sample : add-nbo a.bin b.bin\n");
        return 1;
    }

    uint32_t num1 = read_file(argv[1]);
    uint32_t num2 = read_file(argv[2]);
    uint32_t sum = num1 + num2;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, sum, sum);
    return 0;
}

