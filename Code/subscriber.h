#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#define MAX_SUBSCRIPTIONS 100

// Subscription structure
typedef struct {
    char name[50];
    float cost;
} Subscription;

// Function prototypes
void addSubscription(Subscription subscriptions[], int *subscription_count);
void viewSubscriptions(Subscription subscriptions[], int subscription_count);
void removeSubscription(Subscription subscriptions[], int *subscription_count);
void updateSubscription(Subscription subscriptions[], int subscription_count);

#endif
