#include "gestor.h"

void print_item(t_item *item) {
	printf("______________________________________________________________\n");
	if (item) {	
		printf("ID: %d, Type: %d, Title: %s, Publisher: %s, Reserved: %s\n",
		       item->id, item->type, item->title ? item->title : "N/A",
		       item->publisher ? item->publisher : "N/A",
		       item->reserved ? "Yes" : "No");
		if (item->client) {
			printf("\n\n");
			printf("Name: %s %s, Phone: %i\n",
			       item->client->name ? item->client->name : "N/A",
			       item->client->surname ? item->client->surname : "N/A",
			       item->client->phone ? item->client->phone : 0);
		}
	} else {
		printf("Item is NULL\n");
	}

}

void print_list(t_item *head) {
	if (!head) {
		printf("List is empty.\n");
		return;
	}

	t_item *current = head;
	while (current) {
		print_item(current);
		current = current->next;
	}
}