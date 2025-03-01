/* application.c */

#include "application.h"
#include "user.h"
#include "request.h"
#include "helpers.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char * DELIMITER = ";";

void start_application()
{
    /* Open user file in append mode and set ~user_fp~ points to file's stream. */
    user_fp = fopen(user_file_name, "a+");

    /* Open request file in append mode and set ~request_fp~ points to file's stream. */
    request_fp = fopen(request_file_name, "a+");

    /* If pointer cannot be set then warn operator about it and quit program. */
    if (user_fp == NULL || request_fp == NULL)
    {
        printf("Something went wrong, while operating database file. \n");
        printf("Please make sure that file %s resides in current directory\n", user_file_name);
        getchar();
        return;
    }

    /* Fetch all users and setup array of all users */
    users= read_all_users_from_file(user_fp);
    
    /* Fetch all requests and setup array of all requests */
    requests= read_all_requests_from_file(request_fp);

    /* Show welcome page*/
    welcome();
}

void welcome()
{
    system("clear");

    gotoxy(25, 5);
    printf("Welcome to Bidyut Suraksha \n");
    gotoxy(27, 23);
    printf("Press any key to continue...");

    /* Wait until user press some key. */
    getchar();

    render_menu();
}

void render_menu()
{
    unsigned char choice =0;
    char user_count_label[STR_MAX_LENGTH];

    system("clear");

    /* Show menu */
    gotoxy(25, 5);
    printf("Select Any option from below: \n");
    gotoxy(25, 7);
    printf("1. Add New User \n");
    gotoxy(25, 8);
    printf("2. View Users \n");
    gotoxy(25, 9);
    printf("3. Add New Connection Request \n");
    gotoxy(25, 10);
    printf("4. Edit existing request \n");
    gotoxy(25, 11);
    printf("5. View Requests \n");
    gotoxy(25, 12);
    printf("6. Exit \n");

    sprintf(user_count_label, "Total Users : %lu and Total Requests : %lu", number_of_users, number_of_requests);
    gotoxy(0, 24);
    printf("%s", user_count_label);

    gotoxy(30, 15);
    printf("Enter your choice : ");

    /* Read user choice */
    gotoxy(50, 15);
    scanf("%c", &choice);
    flush_buffer();

    switch (choice)
    {
    case '1':
        add_user_page();
        break;
    case '2':
        view_user_page();
        break;
    case '3':
        add_request_page();
        break;
    case '4':
        edit_request_page();
        break;
   case '5':
        view_requests_page();
        break;
    case '6':
        close_application(EXIT_SUCCESS, "");
        break;
    default:
        close_application(EXIT_SUCCESS, "");
        break;
    }
}

void add_user_page()
{
    /* Requests ID which will be stored in file. */
    unsigned long user_id = last_user_id + 1;

    /* User name */
    char user_name[STR_MAX_LENGTH];

    /* User phone */    
    char user_phone[STR_MAX_LENGTH + 2];

    /* User Id String, which will be shown in success dialogue box. */
    char user_id_string[STR_MAX_LENGTH];

    /* This variable will store user's data. */
    User user;

    /* User information in string, so it can be stored into file easily. */
    char * user_info_string = NULL;

    /* All labels which will be displayed on the screen. */
    const char * enter_detail_label = "Enter details of user (All fields are required)  ";
    const char * user_name_label = "Enter User Name : ";
    const char * user_contact_label = "Enter User Contact : ";

    /* Clear screen */
    system("clear");

    gotoxy(0, 1);
    printf("%s", enter_detail_label);

    gotoxy(0, 3);
    printf("%s", user_name_label);

    gotoxy(0, 4);
    printf("%s", user_contact_label);

    /* Prepare input field for user name on row = 3, column = length(user_name_label). */
    gotoxy((int)strlen(user_name_label), 3);
    scanf("%[^\n]s", user_name);
    flush_buffer();

    /* Prepare input field for user contact on row = 4, column = length(user_contact_label). */
    gotoxy((int)strlen(user_contact_label), 4);
    scanf("%s", user_contact);
    flush_buffer();

    /* Prepare user id string */
    user.user_id = user_id;
    user.user_name = user_name; 
    user.user_contact = user_contact;

    /* Delimited string representation of 'user', which will be directly stored in file. */
    /* 'user_info_string' is pointing to heap memory, so release it after work is done. */

    user_info_string = get_user_string(&user);

    /* Write new user at the end of the file. */

    fseek(user_fp, 0, SEEK_END);
    fputs(user_info_string, user_fp);
    fputs("\n", user_fp);

    /* Free memory created by 'get_user_string' */
    free(user_info_string);

    /* Free memory created by array of users and requests */
    release_requests();
    release_users();

    /* Refresh all users */
    users = read_all_users_from_file(user_fp);

    /* Refresh all requests */
    requests = read_all_requests_from_file(request_fp);

    /* Prepare success dialogue */
    sprintf(user_id_string, "User ID : %lu", user_id);
    dialogue("User added successfully", user_id_string);
    render_menu();
}

void view_user_page()
{
    /* User Id which operator wants to search. */
    unsigned long user_id = 0;

    /* User Details*/
    User * user = NULL;

    /* All Requests made by above user */
    Request ** user_requests = NULL;

    /*Total count of all the requests made by the above user */
    int user_requests_count = 0;

    /* Line offset will be hepful to print information at desired lcation. */
    int line_offset = 0;

    system("clear");

    printf("Enter User ID : ");
    scanf("%lu", &user_id);
    flush_buffer();

    /* Get user details based on 'user_id' */
    user = get_user(user_id);

    /* If user is not found then show error message and return back to menu. */
    if (user == NULL)
    {
        system("clear");
        show_dialogue_box("No such user exits.", "");
        render_menu();
        return;
    }

    system("clear");

    /*Show user details and requests made by him */
    printf("User Details\n");
    printf("\nUser ID : %lu", user->user_id);
    printf("\nUser Name : %s", user->user_name);
    printf("\nUser Contact : %s", user->user_contact);

    /* 'user_requests' points to memory in heap, so release memory after work is done */
    user_requests = get_request_of_user(user_id, &user_requests_count);

    gotoxy(41, 1);

    if(user_requests == NULL)
    {
        printf("Request Details\n");
        gotoxy(41, 3);
        printf("No requests made by this user.");
        gotoxy(0, 24);
        printf("Press any key to return to main menu...");

        /* Wait for user to press any key. */
        getchar();
        render_menu();
        return;
    }

    /*Show request details on right side */
    printf("Request Details");

    for (int i = 0; i < user_requests_count; i++)
    {
        line_offset += 2;
        gotoxy(41, line_offset++);
        printf("Request ID : %lu", user_requests[i]->request_id);
        gotoxy(41, line_offset++);
        printf("Request Status : %s", get_request_status_string(user_requests[i]->status));
        gotoxy(41, line_offset++);
        printf("Comments : %s", user_requests[i]->comments);
        gotoxy(41, line_offset++);
        printf("Address : %s", user_requests[i]->address);
    }

    /* Releasing heap memory pointed to by 'user_requests' */
    free(user_requests);

    gotoxy(0, 24);
    printf("Press any key to return to main menu...");

    /* Wait for user to press any key. */
    getchar();
    render_menu();
}

void view_request_page()
{
    /* Request Id which operator wants to search. */
    unsigned long request_id = 0;

    /* Request Details */
    Request * request = NULL;

    system("clear");

    printf("Enter Request ID : ");
    scanf("%lu", &request_id);
    flush_buffer();

    /* Get request details based on 'request_id' */
    request = get_request(request_id);

    /* If request is not found then show error message and return back to menu. */
    if (request == NULL)
    {
        system("clear");
        show_dialogue_box("No such request exits.", "Please contact Administration. ");
        render_menu();
        return;
    }

    system("clear");

    /* Show request details */
    printf("Request Details\n");

    printf("\nRequest ID : %lu", request->request_id);
    printf("Requested By : %s (id : %lu)", request->requested_by->user_name, request->requested_by->user_id);
    printf("\nRequest Status : %s", get_request_status_string(request->status));
    printf("\nAddress : %s", request->address);
    printf("\nComments : %s", request->comments);

    gotoxy(0, 24);
    printf("Press any key to return to main menu...");

    /* Wait for user to press any key. */
    getchar();
    render_menu();
}

void add_request_page()
{
    /* Request ID which will be stored in file. */
    unsigned long request_id = last_request_id + 1;

    /* User id of user who amde request */
    unsigned long user_id = 0;

    /* Request Address */
    char address[STR_MAX_LENGTH];

    /* Request Comments */
    char comment[STR_MAX_LENGTH];

    /* Request Id String, which will be shown in success dialogue box. */
    char request_id_string[STR_MAX_LENGTH];

    /* User details*/
    User * user = NULL;

    /* This variable will store request's data. */
    Request request;

    /* Request information in string, so it can be stored into file easily. */
    char * request_info_string = NULL;

    /* All labels which will be displayed on the screen. */
    const char * enter_detail_label = "Enter details of Request made by user ";
    const char * user_id_label = "Enter User ID : ";
    const char * request_address_label = "Enter Address : ";
    const char * request_comments_label = "Enter any Comments (optional) : ";

    /* Clear screen */
    system("clear");

    gotoxy(0, 1);
    printf("%s", enter_detail_label);

    gotoxy(0, 3);
    printf("%s", user_id_label);

    gotoxy(0, 4);
    printf("%s", request_comments_label);

    gotoxy(0, 5);
    printf("%s", request_address_label);

    /* Prepare input field for requested by on row = 3, column = length(user_id_label). */
    gotoxy((int)strlen(user_id_label), 3);
    scanf("%lu", &user_id);
    flush_buffer();

    /* Prepare input field for user comment on row = 4, column = length(request_comment_label). */
    gotoxy((int)strlen(request_comments_label), 4);
    /*Using fgets because string can be empty*/
    fgets(comment, STR_MAX_LENGTH, stdin);

    /*If the user press just enter. (i.e, empty data). */
    if (strcmp(comment, "\n") == 0)
    {
        strcpy(comment, "");
    }
    else
    {
        /* If the user entered any string, it will contain "\n" as last character. */
        /* So replace that character with NULL*/
        comment[strlen(comment) - 1] = '\0';
    }

    /* Prepare input field for user address on row = 5, column = length(request_address_label). */
    gotoxy((int)strlen(request_address_label), 5);

    scanf("%[^\n]s", address);
    flush_buffer();

    user = get_user(user_id);

    /* If user is not found then show error message and return back to menu. */
    if (user == NULL)
    {
        system("clear");
        show_dialogue_box("No such user exits.", "Please contact Administration. ");
        render_menu();
    }

    /* Prepare request id string */
    request.request_id = request_id;
    request.requested_by = user;
    request.address = address;
    request.comment = comment;
    request.status = PENDING;

    /* Delimited string representation of 'request', which will be directly stored in file. */
    /* 'request_info_string' is pointing to heap memory, so release it after work is done. */

    request_info_string = get_request_string(&request);

    /* Write new request at the end of the file. */

    fseek(request_fp, 0, SEEK_END);
    fputs(request_info_string, request_fp);
    fputs("\n", request_fp);

    /* Free memory created by 'get_request_string' */
    free(request_info_string);

    /* Free memory created by array of users and requests */
    release_requests();
    release_users();

    /* Refresh all users */
    users = read_all_users_from_file(user_fp);

    /* Refresh all requests */
    requests = read_all_requests_from_file(request_fp);

    /* Prepare success dialogue */
    sprintf(request_id_string, "Request ID : %lu", request_id);
    show_dialogue_box("Request added successfully", request_id_string);
    render_menu();
}

void edit_request_page()
{
    /* Request ID for request which user want to edit */
    unsigned long request_id = 0;

    /* New Status for request. Details to 'PENDING'. */
    request_status new_status = PENDING;

    /* New Comments which user will enter. */
    char new_comment[STR_MAX_LENGTH];

    /* Request Details */
    Request * request = NULL;

    /* All labels which will be displayed on the screen. */
    char * enter_new_status_label = "Enter request status : ";
    char * enter_new_status_suggestion_label = "(1 -> In Progress, 2 -> Completed, 3 -> Rejected) ";
    char * enter_new_comment_label = "Enter any comments : ";

    /* Clear screen */
    system("clear");
    printf("Enter Request ID : ");
    scanf("%lu", &request_id);
    flush_buffer();

    /*Fetch Request from requests array. */
    request = get_request(request_id);

    /* If request is not found then show error message and return back to menu. */
    if (request == NULL)
    {
        system("clear");
        show_dialogue_box("No such request exits.", "");
        render_menu();
        return;
    }

    /*Display request parameters on screen */
    printf("\nRequest Details\n");
    printf("\nRequest ID : %lu", request->request_id);
    printf("\nRequested By : %s (id : %lu)", request->requested_by->user_name, request->requested_by->user_id);
    printf("\nRequest Status : %s", get_request_status_string(request->status));
    printf("\nAddress : %s", request->address);
    printf("\nComments : %s", request->comments);

    printf("\n\n***************************************************************************");

    printf("\n Enter new Details\n\n");

    printf("%s", enter_new_status_label);
    printf("%s", enter_new_status_suggestion_label);

    gotoxy((int)strlen(enter_new_status_label), 14);

    scanf("%d" &new_status);
    flush_buffer();

    printf("\n%s", enter_new_comment_label);
    fgets(new_comment, STR_MAX_LENGTH, stdin);

    /*If the user press just enter. (i.e, empty data). */
    if (strcmp(new_comment, "\n") == 0)
    {
        strcpy(new_comment, request->comment);
    }
    else
    {
        /* If the user entered any string, it will contain "\n" as last character. */
        /* So replace that character with NULL*/
        new_comment[strlen(new_comment) - 1] = '\0';
    }

    /*Store updated data in'request' */
    request->status = new_status;

    /* Do not copy 'new_comment' into 'request->comment', */
    /* that requires expansion in size of 'request->comment', */
    /* if 'new_comment' is bigger than 'request_comment' (otherwise memory will leak.) and create new one */

    free(request->comment);
    request->comment = strdup(new_comment);

    /* Repalce data in File */
    replace_request_in_file(request_fp, request);

    /* Free memory created by array of users and requests */
    release_requests();
    release_users();

    /* Refresh all users */
    users = read_all_users_from_file(user_fp);

    /* Refresh all requests */
    requests = read_all_requests_from_file(request_fp);

    show_dialogue_box("Request updated successfully", "");
    render_menu();
}

void close_application(int status, const char * message)
{
    /* Close file pointers */
    fclose(user_fp);
    fclose(request_fp);

    /* Free memory created by array of users and requests */
    release_requests();
    release_users();

    system("clear");

    /* Show message */
    if (strlen(message) > 0)
    {
        printf("%s", message);
    }

    /* Exit application */
    exit(status);
}

void show_dialogue_box(const char * message, char * id)
{
    int message_length = (int)strlen(message);

    const char * press_any_key = "Press any key to continue";
    int info_length = (int)strlen(press_any_key);

    int left_offset = 15;
    int length =50;
    int line_offset = 9;

    system("clear");

    /* Line 1 */
    gotoxy(left_offset, line_offset++);
    printf("********************************************************************");
    
    /*Line 2 */
    gotoxy(left_offset, line_offset);
    printf("*");
    gotoxy(left_offset + length - 1, line_offset++);
    printf("*");

    /*Line 3 */
    gotoxy(left_offset, line_offset);
    printf("*");
    gotoxy((80 - message_length) / 2, line_offset);
    printf("%s", message);
    gotoxy(left_offset + length - 1, line_offset++);
    printf("*");

    if(strcmp(id, "") != 0)
    {
        /*Line 4 */
        gotoxy(left_offset, line_offset);
        printf("*");
        gotoxy((int)((80 - strlen(id)) / 2), line_offset);
        printf("%s", id);
        gotoxy(left_offset + length - 1, line_offset++);
        printf("*");
    }

    /*Line 5 */
    gotoxy(left_offset, line_offset++);
    printf("*");
    gotoxy((int)((80 - info_length) / 2), line_offset);
    printf("%s", press_any_key);
    gotoxy(left_offset + length - 1, line_offset++);
    printf("*");

    /*Line 6 */
    gotoxy(left_offset, line_offset);
    printf("*");
    gotoxy(left_offset + length - 1, line_offset++);
    printf("*");

    /*Line 7 */
    gotoxy(left_offset, line_offset++);
    printf("********************************************************************");

    getchar();
}

void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}