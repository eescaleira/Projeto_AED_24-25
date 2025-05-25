#include "gestor.h"

void free_item(t_item *item) {
	if (item) {
		free(item->title);
		free(item->publisher);
		free(item->client);
		free(item);
	}
}

void free_client(t_client *client) {
	if (client) {
		free(client->name);
		free(client->surname);
		free(client);
	}
}

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

void free_list(t_item *head) {
	t_item *current = head;
	t_item *next;

	while (current) {
		next = current->next;
		if(current->client) {
			free_client(current->client);
		}
		free_item(current);
		current = next;
	}
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