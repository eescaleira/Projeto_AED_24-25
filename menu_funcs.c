#include "gestor.h"

void print_menu(t_item *item_list) {
	int option;
	printf("Menu:\n");
	printf("1. Add Item\n");
	printf("2. Remove Item\n");
	printf("3. Make Reservation\n");
	printf("4. Cancel Reservation\n");
	printf("5. List Items\n");
	printf("6. Search Item\n");
	printf("7. Exit\n");
	scanf("%i", &option);

	switch (option)
	{
	case 1:
		int id, type;
		char title[100], publisher[100];
		printf("Enter Item ID: ");
		scanf("%d", &id);
		printf("Enter Item Type (0: BOOK, 1: MAGAZINE, 2: NEWSPAPER, 3: CD, 4: DVD, 5: VIDEO, 6: OTHER): ");
		scanf("%d", &type);
		printf("Enter Item Title: ");
		scanf(" %[^\n]", title);
		printf("Enter Item Publisher: ");
		scanf(" %[^\n]", publisher);
		t_item *new_item = create_item(title, id, type, publisher);
		add_item(item_list, new_item);
		sleep(1);
		print_menu(item_list);
		break;
	case 2:
		printf("Enter Item ID to remove: ");
		scanf("%d", &id);
		item_list = orderByIdItem(item_list);
		t_item *item_to_remove = binary_search_by_id(item_list, id);
		print_item(item_to_remove);
		remove_item(item_list, item_to_remove);
		printf("Item removed successfully.\n");
		sleep(1);
		print_menu(item_list);
	case 3:
		printf("Enter Item ID to reserve: ");
		scanf("%d", &id);
		item_list = orderByIdItem(item_list);
		t_item *item_to_reserve = binary_search_by_id(item_list, id);
		if (item_to_reserve && !item_to_reserve->reserved) {
			client_info(item_to_reserve);
			item_to_reserve->reserved = true;
			printf("Item reserved successfully.\n");
		} else {
			printf("Item not found or already reserved.\n");
		}
		sleep(1);
		print_menu(item_list);
	case 4:
		printf("Enter Item ID to cancel reservation: ");
		scanf("%d", &id);
		item_list = orderByIdItem(item_list);
		t_item *item_to_cancel = binary_search_by_id(item_list, id);
		if (item_to_cancel && item_to_cancel->reserved) {
			item_to_cancel->reserved = false;
			free_client(item_to_cancel->client);
			item_to_cancel->client = NULL;
			printf("Reservation cancelled successfully.\n");
		} else {
			printf("Item not found or not reserved.\n");
		}
		break;
	case 5:
		printf("1. Alphabetical Order\n");
		printf("2. By ID\n");
		int choice;
		scanf("%d", &choice);
		if (choice == 1) {
			item_list = orderbyname(item_list);
		} else if (choice == 2) {
			item_list = orderByIdItem(item_list);
		} else {
			printf("Invalid choice.\n");
		}
		print_list(item_list);
		sleep(5);
		print_menu(item_list);
		break;
	case 6:
		printf("Enter Item ID to search: ");
		scanf("%d", &id);
		item_list = orderByIdItem(item_list);
		t_item *item_found = binary_search_by_id(item_list, id);
		if (item_found) {
			print_item(item_found);
		} else {
			printf("Item not found.\n");
		}
		sleep(5);
		print_menu(item_list);
		break;
	case 7:
		printf("Exiting...\n");
		free_list(item_list);
		exit(0);
		break;
	default:
		break;
	}
}