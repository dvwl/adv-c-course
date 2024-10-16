#include <stdio.h>
#include <stdlib.h>

struct my_struct {
    int x;
    char name[20];
};

// Writing Binary File Example
int main() {
    FILE *fp = fopen("example.bin", "wb"); // Open file in binary write mode
    if (!fp) {
        perror("Error opening file");
        return 1;
    }
    struct my_struct data = {2, "Ahmad"};
    fwrite(&data, sizeof(struct my_struct), 1, fp); // Write struct to file
    fclose(fp);
    return 0;
}

// Reading Binary File Example
// int main() {
//     FILE *fp = fopen("example.bin", "rb"); // Open file in binary read mode
//     if (!fp) {
//         perror("Error opening file");
//         return 1;
//     }
//     struct my_struct data;
//     fread(&data, sizeof(struct my_struct), 1, fp); // Read struct from file
//     printf("x: %d, name: %s", data.x, data.name);
//     fclose(fp);
//     return 0;
// }

