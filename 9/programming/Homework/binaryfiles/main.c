#include <stdio.h>
#include <string.h>

// Enum for education
enum Education {
    NO_EDUCATION,
    PRIMARY,
    SECONDARY,
    HIGHER
};

// Enum for employment status
enum EmploymentStatus {
    UNEMPLOYED,
    EMPLOYED
};

// Enum for marital status
enum MaritalStatus {
    SINGLE,
    MARRIED
};

// Structure to represent citizen data
struct Citizen {
    char EGN[11];
    char fullName[256];
    int age;
    enum Education education;
    enum EmploymentStatus employmentStatus;
    enum MaritalStatus maritalStatus;
};

// Function to add a new citizen record to the file
void addCitizen(FILE *file) {
    struct Citizen citizen;
    printf("Enter EGN: ");
    scanf("%s", citizen.EGN);
    printf("Enter full name: ");
    scanf(" %[^\n]s", citizen.fullName);
    printf("Enter age: ");
    scanf("%d", &citizen.age);
    printf("Enter education (0-none, 1-primary, 2-secondary, 3-higher): ");
    scanf("%d", (int *)&citizen.education);
    printf("Enter employment status (0-unemployed, 1-employed): ");
    scanf("%d", (int *)&citizen.employmentStatus);
    printf("Enter marital status (0-single, 1-married): ");
    scanf("%d", (int *)&citizen.maritalStatus);

    // Write the citizen to the file
    fwrite(&citizen, sizeof(struct Citizen), 1, file);
    printf("Citizen added successfully.\n");
}

// Function to delete a record by EGN
void deleteCitizen(FILE *file) {
    char searchEGN[11];
    printf("Enter the EGN of the citizen to delete: ");
    scanf("%s", searchEGN);

    FILE *tempFile = fopen("temp.bin", "wb");
    struct Citizen citizen;

    // Copy all records from the original file to the temporary file, excluding the record to be deleted
    while (fread(&citizen, sizeof(struct Citizen), 1, file)) {
        if (strcmp(citizen.EGN, searchEGN) != 0) {
            fwrite(&citizen, sizeof(struct Citizen), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    // Remove the original file
    remove("citizens.bin");
    // Rename the temporary file to the original file
    rename("temp.bin", "citizens.bin");

    // Open the file again after renaming
    file = fopen("citizens.bin", "ab+");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    printf("Citizen deleted successfully.\n");
}

// Function to print all citizens
void printAllCitizens(FILE *file) {
    fseek(file, 0, SEEK_SET); // Move file pointer to the beginning of the file

    struct Citizen citizen;

    printf("%-30s %-5s %-10s %-10s %-10s\n", "EGN", "Name", "Age", "Education", "Employment", "Marital");

    // Print valid records from the file
    while (fread(&citizen, sizeof(struct Citizen), 1, file)) {
        if (citizen.EGN[0] != '\0') { // Check if EGN field is not empty
            char education[10];
            switch (citizen.education) {
                case NO_EDUCATION:
                    strcpy(education, "None");
                    break;
                case PRIMARY:
                    strcpy(education, "Primary");
                    break;
                case SECONDARY:
                    strcpy(education, "Secondary");
                    break;
                case HIGHER:
                    strcpy(education, "Higher");
                    break;
                default:
                    strcpy(education, "-");
                    break;
            }

            char employment[12];
            switch (citizen.employmentStatus) {
                case UNEMPLOYED:
                    strcpy(employment, "Unemployed");
                    break;
                case EMPLOYED:
                    strcpy(employment, "Employed");
                    break;
                default:
                    strcpy(employment, "-");
                    break;
            }

            char maritalStatus[10];
            switch (citizen.maritalStatus) {
                case SINGLE:
                    strcpy(maritalStatus, "Single");
                    break;
                case MARRIED:
                    strcpy(maritalStatus, "Married");
                    break;
                default:
                    strcpy(maritalStatus, "-");
                    break;
            }

            printf("%-12s %-30s %-5d %-10s %-10s %-10s\n", citizen.EGN, citizen.fullName, citizen.age, education, employment, maritalStatus);
        }
    }

    printf("\n");
}

int main() {
    FILE *file;
    int choice;

    // Open the file for read and write in binary mode
    file = fopen("citizens.bin", "ab+");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    do {
        printf("-- Menu --\n");
        printf("1. Add citizen\n");
        printf("2. Delete citizen by EGN\n");
        printf("3. Print all citizens\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCitizen(file);
                break;
            case 2:
                deleteCitizen(file);
                break;
            case 3:
                printAllCitizens(file);
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    fclose(file);
    return 0;
}
