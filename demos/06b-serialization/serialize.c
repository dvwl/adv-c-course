#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    char name[20];
	int age;
	char gender;
} Person;

// Function to serialize Person to JSON string
void serializePersonToJSON(Person person, char* jsonString) {
    // Construct the JSON string
    sprintf(jsonString, "{ \"name\": \"%s\", \"age\": %d, \"gender\": \"%c\" }", person.name, person.age, person.gender);
}

const char* FORMAT = "{ \"name\": \"%[^\"]\", \"age\": %d, \"gender\": \"%c\" }";
// Function to deserialize Person to JSON string
void deserializePersonToJSON(const char* jsonString, Person* person) {
    // Parse the JSON string and extract values
    sscanf(jsonString, FORMAT, person->name, &person->age, &person->gender);
}

// Writing to File Example
// int main() {
//     FILE *fp = fopen("example.txt", "w"); // Open file in write mode
//     if (!fp) {
//         perror("Error opening file");
//         return 1;
//     }
//     Person data = {"Alice", 30, 'F'};

// 	char jsonString[100];
// 	serializePersonToJSON(data, jsonString);
	
// 	printf("%s", jsonString);
    
// 	fwrite(&jsonString, strlen(jsonString), 1, fp); // Write struct to file
//     fclose(fp);
//     return 0;
// }

// Reading from File Example
int main() {
    FILE *fp = fopen("example.txt", "r"); // Open file in read mode
    if (!fp) {
        perror("Error opening file");
        return 1;
    }
    
	Person data;
	char jsonString[100];

	fread(jsonString, sizeof(char), sizeof(jsonString) - 1, fp);
	jsonString[sizeof(jsonString) - 1] = '\0';  // Null-terminate to ensure it’s a valid string
	printf("%s\n", jsonString);

	deserializePersonToJSON(jsonString, &data);    // Output the JSON string
	fclose(fp);

    printf("name: %s, age: %d, gender: %c", data.name, data.age, data.gender);
    return 0;
}

