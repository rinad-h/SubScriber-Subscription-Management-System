#include <stdio.h>
#include <string.h>
#include "subscriber.h"

// Function to check if a subscription name is unique
int is_unique_name(const char *name, Subscription subscriptions[], int subscription_count) {
    for (int i = 0; i < subscription_count; i++) {
        if (strcmp(subscriptions[i].name, name) == 0) {
            return 0; // Name already exists
        }
    }
    return 1; // Name is unique
}

// Function to add a subscription
void addSubscription(Subscription subscriptions[], int *subscription_count) {
    if (*subscription_count >= MAX_SUBSCRIPTIONS) {
        printf("Subscription limit reached. Cannot add more.\n");
        return;
    }

    char name[50];
    float cost;

    printf("Enter subscription name: ");
    scanf("%s", name);

    // Check if the name is unique
    if (!is_unique_name(name, subscriptions, *subscription_count)) {
        printf("Subscription name must be unique. This name already exists.\n");
        return;
    }

    // Input cost with validation for negative values
    do {
        printf("Enter subscription cost: ");
        scanf("%f", &cost);
        if (cost < 0) {
            printf("Cost cannot be negative. Please enter a valid cost.\n");
        }
    } while (cost < 0);

    // Store the subscription
    strcpy(subscriptions[*subscription_count].name, name);
    subscriptions[*subscription_count].cost = cost;
    (*subscription_count)++;

    printf("Subscription added successfully!\n");
}

// Function to display all subscriptions
void viewSubscriptions(Subscription subscriptions[], int subscription_count) {
    if (subscription_count == 0) {
        printf("No subscriptions available.\n");
        return;
    }

    printf("\nAll Subscriptions:\n");
    for (int i = 0; i < subscription_count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, subscriptions[i].name, subscriptions[i].cost);
    }
}

// Function to remove a subscription
void removeSubscription(Subscription subscriptions[], int *subscription_count) {
    int index;
    
    viewSubscriptions(subscriptions, *subscription_count);
    if (*subscription_count == 0) return;

    printf("Enter the subscription number to remove: ");
    scanf("%d", &index);

    if (index < 1 || index > *subscription_count) {
        printf("Invalid subscription number.\n");
        return;
    }

    // Remove the subscription by shifting elements
    for (int i = index - 1; i < *subscription_count - 1; i++) {
        subscriptions[i] = subscriptions[i + 1];
    }

    (*subscription_count)--;
    printf("Subscription removed successfully.\n");
}

// Function to update the cost of a subscription
void updateSubscription(Subscription subscriptions[], int subscription_count) {
    int index;
    float new_cost;

    viewSubscriptions(subscriptions, subscription_count);
    if (subscription_count == 0) return;

    printf("Enter the subscription number to update: ");
    scanf("%d", &index);

    if (index < 1 || index > subscription_count) {
        printf("Invalid subscription number.\n");
        return;
    }

    do {
        printf("Enter new cost: ");
        scanf("%f", &new_cost);
        if (new_cost < 0) {
            printf("Cost cannot be negative. Please enter a valid cost.\n");
        }
    } while (new_cost < 0);

    subscriptions[index - 1].cost = new_cost;
    printf("Subscription cost updated successfully!\n");
}
