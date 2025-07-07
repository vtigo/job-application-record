#ifndef APPLICATION_H
#define APPLICATION_H

typedef enum {
    SUBMITTED,
    ACCEPTED,
    REJECTED,
    WITHDRAWN,
    ONGOING
} ApplicationStatus;

typedef struct {
    char company_name[100];
    char role[100];
    char application_date[11]; // Format: YYYY-MM-DD
    ApplicationStatus status;
} Application;

char* status_to_string(ApplicationStatus status);
Application create_job_application(const char* company, const char* role, const char* date, ApplicationStatus status);
void print_job_application(const Application* app);

#endif