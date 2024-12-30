#include <stdio.h>
#include <stdlib.h>
#include "subscriber.h"

int main() {
    // Array to hold subscriptions
    Subscription subscriptions[MAX_SUBSCRIPTIONS];
    // Counter for the number of subscriptions
    int subscription_count = 0;
    int choice;

    // Main program loop
    while (1) {
        // Display the menu
        printf("\n--- SubScriber ---\n");
        printf("1. Add Subscription\n");
        printf("2. View Subscriptions\n");
        printf("3. Remove Subscription\n");
        printf("4. Update Subscription\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        // Read user choice
        scanf("%d", &choice);

        // Perform the action based on user choice
        switch (choice) {
            case 1:
                addSubscription(subscriptions, &subscription_count); // Add subscription
                break;
            case 2:
                viewSubscriptions(subscriptions, subscription_count); // View subscriptions
                break;
            case 3:
                removeSubscription(subscriptions, &subscription_count); // Remove subscription
                break;
            case 4:
                updateSubscription(subscriptions, subscription_count); // Update subscription
                break;
            case 5:
                printf("Exiting SubScriber. Goodbye!\n"); // Exit the program
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
