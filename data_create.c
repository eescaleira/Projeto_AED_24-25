#include "gestor.h"

t_item *create_item(char *title, int id, int type, char *publisher) {
	t_item *item;
	item = malloc(sizeof(t_item));
	if (!item) {
		perror("Failed to allocate memory for item");
		return NULL;
	}
	item->id = id;
	item->type = type;
	item->title = strdup(title);
	item->publisher = strdup(publisher);
	item->reserved = false;
	item->client = NULL;
	item->prev = NULL;
	item->next = NULL;
}

t_item *make_list(void){
	t_item *head = create_item("head", 0, 0, "head");
	t_item *prev = head;
	int i = 0;
	for(; i < 10; i++){
		t_item *new_item = create_item("item", i +1 , 1, "publisher");
		if (!new_item) {
			perror("Failed to create item");
			return NULL;
		}
		printf("Creating item %d\n", i + 1);
		new_item->prev = prev;
		prev->next = new_item;
		prev = new_item;
	}
	return(head);
}