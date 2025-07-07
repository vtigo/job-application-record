#include <stdio.h>
#include <string.h>
#include "application.h"

// Function to convert status enum to string
char* status_to_string(ApplicationStatus status) {
    switch(status) {
        case SUBMITTED: return "Submitted";
        case REJECTED: return "Rejected";
        case ACCEPTED: return "Accepted";
        case WITHDRAWN: return "Withdrawn";
        default: return "Unknown";
    }
}

// Function to create a job application
Application create_job_application(const char* company, const char* role, const char* date, ApplicationStatus status) {
    Application app;
    
    strncpy(app.company_name, company, sizeof(app.company_name) - 1);
    app.company_name[sizeof(app.company_name) - 1] = '\0';
    
    strncpy(app.role, role, sizeof(app.role) - 1);
    app.role[sizeof(app.role) - 1] = '\0';
    
    strncpy(app.application_date, date, sizeof(app.application_date) - 1);
    app.application_date[sizeof(app.application_date) - 1] = '\0';
    
    app.status = status;
    
    return app;
}

// Function to print job application details
void print_job_application(const Application* app) {
    printf("Company: %s\n", app->company_name);
    printf("Role: %s\n", app->role);
    printf("Application Date: %s\n", app->application_date);
    printf("Status: %s\n", status_to_string(app->status));
    printf("------------------------\n");
}
