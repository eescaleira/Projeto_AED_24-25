#include "gestor.h"

int list_length(t_item* head) {
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}

t_item* get_node_at(t_item* head, int index) {
    int i = 0;
    while (head && i < index) {
        head = head->next;
        i++;
    }	
    return head;
}


void remove_item(t_item *head, t_item *item_to_remove) {
	if (!item_to_remove)
		return;

	if (head == item_to_remove) {
		head = head->next;
		head->prev = NULL;
	} else {
		item_to_remove->prev->next = item_to_remove->next;
		if (item_to_remove->next) {
			item_to_remove->next->prev = item_to_remove->prev;
		}
	}
	free_item(item_to_remove);
}

void client_info(t_item *item) {
	int phone;
	char *name = malloc(50 * sizeof(char));
	char *surname = malloc(50 * sizeof(char));
	t_client *client = malloc(sizeof(t_client));
	printf("Enter Client name: ");
	scanf(" %[^\n]", name);
	printf("Enter Client surname: ");
	scanf(" %[^\n]", surname);
	printf("Enter Client phone: ");
	scanf(" %d", &phone);	

	client->name = name;
	client->surname = surname;
	client->phone = phone;
	item->client = client;
	printf("Client information added successfully.\n");
}