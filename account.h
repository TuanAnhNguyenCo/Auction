typedef struct
{
    char username[100];
    char password[100];
    char status;
} AccountMessage;

typedef struct
{
    int message_type;
    int current_user_id;
} MessageForm;