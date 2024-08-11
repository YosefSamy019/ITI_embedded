#include <stdio.h>
#include <string.h>

// Define data types for easier usage
typedef double f64;
typedef float f32;
typedef unsigned long long int u64;
typedef long long int s64;
typedef unsigned long int u48;
typedef long int s48;
typedef unsigned int u32;
typedef int s32;
typedef unsigned short int u16;
typedef unsigned char u8;
typedef signed short int s16;
typedef signed char s8;

// Constants
#define MAX_PATIENTS 100
#define DEFAULT_PASSWORD 1234
#define MAX_SLOTS 5
#define STRING_LENGTH 50
#define TRIALS_OF_PASSWORD 3

// Password Trials
#define LOW 0
#define HIGH 1

#define DPRINT(str,...) do{ printf("##FUN %s, \t",__func__ );  printf(str,__VA_ARGS__); }while(0)

// Patient Structure
typedef struct {
    u32 ID;
    u8 name[50];
    u32 age;
    u32 gender;
} Patient;

// Slots
u32 slot_taken[MAX_SLOTS] = {LOW};
f32 available_slots[MAX_SLOTS] = {2.5, 3.0, 3.5, 4.0, 4.5};

// Prototypes for Functions
void Void_Add_Patient(Patient patients[], u32 *count);
void Void_Edit_Patient(Patient patients[], u32 count);
u8 u8_Is_Unique_Id(Patient patients[], u32 count, u32 id);
u8 u8_Is_Valid_Id(Patient patients[], u32 count, u32 id);
void Void_Reserve_Slot(Patient patients[], u32 count);
void Void_Cancel_Reservation();
void View_Patient_Records(Patient patients[], u32 count);
void view_today_reservations(); // Move this to User mode
void Clear_Screen(); // New function to clear the screen

// Main Function
int main(void) {
    Clear_Screen(); // Clear the screen at the start of the main function
    
    static  Patient patients[MAX_PATIENTS]; // Array to hold patient data
    static u8 option_mode;
    static u32 entered_password;
    static u8 trials;
    static u32 patient_count = 0;

    printf("             WELCOME             \n");
    printf("Choose mode or exit: \n");
    printf("1: Admin mode \n");
    printf("2: User mode \n");
    printf("3: Exit \n");
    scanf("%hhu", &option_mode);
    fflush(stdin);

    switch (option_mode) {
        case 1: // Admin mode
            for (trials = LOW; trials < TRIALS_OF_PASSWORD; trials++) {
                printf("Please enter the password: \n");
                scanf("%u", &entered_password);
                fflush(stdin);
                if (DEFAULT_PASSWORD == entered_password) {
                    // Admin Options Loop
                    u8 admin_option;
                    do {
                        printf("Choose admin option:\n");
                        printf("1: Add new patient \n");
                        printf("2: Edit current patient \n");
                        printf("3: New reservation \n");
                        printf("4: Cancel reservation \n");
                        printf("5: View today's reservations \n");
                        printf("6: Exit admin mode\n");
                        scanf("%hhu", &admin_option);
                        fflush(stdin);
                        
                        switch (admin_option) {
                            case 1: // Add new patient
                                DPRINT("BEFORE CALL %u\n",patient_count);
                                Void_Add_Patient(patients, &patient_count);
                                DPRINT("AFTER CALL %u\n",patient_count);
                                break;
                            case 2: // Edit current patient
                                Void_Edit_Patient(patients, patient_count);
                                break;
                            case 3: // New reservation
                                Void_Reserve_Slot(patients, patient_count);
                                break;
                            case 4: // Cancel reservation
                                Void_Cancel_Reservation();
                                break;
                           
                            case 6: // Exit admin mode
                                main();
                            default:
                                main();
                        }
                    } while (admin_option != 6); // Continue until admin chooses to exit
                    break;
                } else {
                    printf("Wrong password, try again.\n");
                }
            }
            break;

        case 2: // User mode
        {
            u8 user_option;
            do {
                printf("Choose user option:\n");
                printf("1: View patient record \n");
                printf("2: View today's reservations \n");
                printf("3: Exit user mode \n");
                scanf("%hhu", &user_option);
                fflush(stdin);

                switch (user_option) {
                    case 1: // View patient record
                        View_Patient_Records(patients, patient_count);
                        break;
                    case 2: // View today's reservations
                        view_today_reservations();
                        break;
                    case 3: // Exit
                        printf("Exiting user mode...\n");
                        break;
                    default:
                        printf("Invalid option.\n");
                        break;
                }
            } while (user_option != 3); // Continue until user chooses to exit
            break;
        }

        case 3: // Exit option
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid option selected.\n");
            break;
    }

    return 0;
}

// Function Definitions

void Void_Add_Patient(Patient patients[], u32 *count) {
    DPRINT("START %u\n",*count);
    
    if (*count >= MAX_PATIENTS) {
        printf("Cannot add more patients, maximum number reached.\n");
        return;
    }

    u32 id;
    printf("Enter patient ID: ");
    scanf("%u", &id);
    
    if (!u8_Is_Unique_Id(patients, *count, id)) {
        printf("Patient with this ID is already recorded.\n");
        return;
    }

    patients[*count].ID = id;
    printf("Enter patient age: ");
    scanf("%u", &patients[*count].age);
    
    // Validate gender input
    do {
        printf("Enter patient gender (0 for male, 1 for female): ");
        scanf("%u", &patients[*count].gender);
        if (patients[*count].gender != 0 && patients[*count].gender != 1) {
            printf("Invalid gender option. Please choose 0 for male or 1 for female.\n");
        }
    } while (patients[*count].gender != 0 && patients[*count].gender != 1);
    
    printf("Enter patient name: ");
    scanf("%s", patients[*count].name);
    printf("Patient added successfully.\n");
    (*count)++;
    
    DPRINT("END %u\n",*count);

}

void Void_Edit_Patient(Patient patients[], u32 count) {
    u32 id;
    printf("Enter ID to edit data: ");
    scanf("%u", &id);

    for (u32 i = LOW; i < count; i++) {
        if (patients[i].ID == id) {
            printf("Enter new age: ");
            scanf("%u", &patients[i].age);
            
            // Validate gender input
            do {
                printf("Enter new gender (0 for male, 1 for female): ");
                scanf("%u", &patients[i].gender);
                if (patients[i].gender != 0 && patients[i].gender != 1) {
                    printf("Invalid gender option. Please choose 0 for male or 1 for female.\n");
                }
            } while (patients[i].gender != 0 && patients[i].gender != 1);
            
            printf("Enter new name: ");
            scanf("%s", patients[i].name);
            printf("Patient updated successfully.\n");
            return;
        }
    }
    printf("Patient not found.\n");
}

u8 u8_Is_Unique_Id(Patient patients[], u32 count, u32 id) {
    for (u32 i = LOW; i < count; i++) {
        if (patients[i].ID == id) {
            return 0; // Not unique
        }
    }
    return 1; // Unique
}

u8 u8_Is_Valid_Id(Patient patients[], u32 count, u32 id) {
    for (u32 i = LOW; i < count; i++) {
        if (patients[i].ID == id) {
            return 1; // Valid ID
        }
    }
    return 0; // Invalid ID
}

void Void_Reserve_Slot(Patient patients[], u32 count) {
    u32 id;
    f32 desired_slot;

    // Display available slots
    printf("Available slots:\n");
    for (u32 i = 0; i < MAX_SLOTS; i++) {
        if (slot_taken[i] == LOW) {
            printf("Slot %.1f PM to %.1f PM\n", available_slots[i], available_slots[i] + 0.5);
        }
    }

    printf("Enter patient ID to reserve: ");
    scanf("%u", &id);
    
    if (!u8_Is_Valid_Id(patients, count, id)) {
        printf("Invalid patient ID.\n");
        return;
    }

    printf("Enter the desired slot (e.g., 2.5, 3.0): ");
    scanf("%f", &desired_slot);

    for (u32 i = LOW; i < MAX_SLOTS; i++) {
        if (available_slots[i] == desired_slot) {
            if (slot_taken[i] == LOW) {
                                slot_taken[i] = HIGH;
                printf("Slot reserved successfully.\n");
                return;
            } else {
                printf("Slot already taken.\n");
                return;
            }
        }
    }
    printf("Invalid slot selected.\n");
}

void Void_Cancel_Reservation() {
    f32 slot_to_cancel;

    printf("Enter the slot to cancel (e.g., 2.5): ");
    scanf("%f", &slot_to_cancel);

    for (u32 i = LOW; i < MAX_SLOTS; i++) {
        if (available_slots[i] == slot_to_cancel && slot_taken[i] == HIGH) {
            slot_taken[i] = LOW;
            printf("Slot %.1f PM to %.1f PM reservation cancelled.\n", available_slots[i], available_slots[i] + 0.5);
            return;
        }
    }
    printf("No reservation found for the given slot.\n");
}

void View_Patient_Records(Patient patients[], u32 count) {
    printf("Patient Records:\n");
    DPRINT("COUNTS %d",count);
    for (u32 i = 0; i < count; i++) {
        printf("ID: %u, Name: %s, Age: %u, Gender: %u\n", patients[i].ID, patients[i].name, patients[i].age, patients[i].gender);
    }
}

void view_today_reservations() {
    int any_reservations = 0;

    printf("Today's Reservations:\n");
    for (int i = 0; i < MAX_SLOTS; i++) {
        if (slot_taken[i] == HIGH) {
            printf("Slot %.1f PM to %.1f PM is reserved.\n", available_slots[i], available_slots[i] + 0.5);
            any_reservations = 1;
        }
    }

    if (!any_reservations) {
        printf("No reservations for today.\n");
    }
}

void Clear_Screen() {

    
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}