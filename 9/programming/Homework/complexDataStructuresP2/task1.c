#include <stdbool.h>
#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year;
    struct {
        int hour;
        int minute;
    } time;
} Date;

typedef struct {
    int num_participants;
    char title[50];
    char description[200];
    struct {
        char first_name[20];
        char middle_name[20];
        char last_name[20];
        char email[50];
        char phone[20];
    } participants[100];
    bool responses[100];
    Date date;
} Cause;

int main() {
    Cause causes[2] = {{.num_participants = 3,
                        .title = "Community clean-up event",
                        .description = "Join us for a community clean-up event!",
                        .date = {.day = 10,
                                 .month = 4,
                                 .year = 2023,
                                 .time = {.hour = 14, .minute = 30}},
                        .participants = {{.first_name = "John",
                                          .last_name = "Doe",
                                          .email = "john.doe@example.com",
                                          .phone = "555-1234"},
                                         {.first_name = "Jane",
                                          .last_name = "Smith",
                                          .email = "jane.smith@example.com",
                                          .phone = "555-5678"},
                                         {.first_name = "Bob",
                                          .last_name = "Johnson",
                                          .email = "bob.johnson@example.com",
                                          .phone = "555-9101"}},
                        .responses = {true, false, true}},
                       {.num_participants = 2,
                        .title = "Charity fundraiser",
                        .description = "Help us raise money for a local charity!",
                        .date = {.day = 15,
                                 .month = 4,
                                 .year = 2023,
                                 .time = {.hour = 18, .minute = 0}},
                        .participants = {{.first_name = "Alice",
                                          .last_name = "Brown",
                                          .email = "alice.brown@example.com",
                                          .phone = "555-1212"},
                                         {.first_name = "Charlie",
                                          .last_name = "Lee",
                                          .email = "charlie.lee@example.com",
                                          .phone = "555-3434"}},
                        .responses = {true, false}}};

    // пример за извеждане на информация за кауза и нейните участници
    printf("Cause title: %s\n", causes[0].title);
    printf("Description: %s\n", causes[0].description);
    printf("Date: %d/%d/%d %d:%d\n", causes[0].date.day, causes[0].date.month,
           causes[0].date.year, causes[0].date.time.hour,
           causes[0].date.time.minute);

    for (int i = 0; i < causes[0].num_participants; i++) {
        printf("Participant %d: %s %s, email: %s, phone: %s, response: %s\n", i + 1,
               causes[0].participants[i].first_name,
               causes[0].participants[i].last_name, causes[0].participants[i].email,
               causes[0].participants[i].phone,
               causes[0].responses[i] ? "Yes" : "No");
    }

    return 0;
}
