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

void add_item(t_item *head, t_item *new_item) {
	if (head == NULL) {
		head = new_item;
	} else {
		t_item *temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new_item;
		new_item->prev = temp;
	}
}




t_item *make_list(void){
	t_item *head = create_item("head", 0, 0, "head");
	head->prev = NULL;
	t_item *one = create_item("one", 26, 1, "publisher");
	head->next = one;
	one->prev = head;
	t_item *two = create_item("two", 8, 1, "publisher");
	one->next = two;
	two->prev = one;
	t_item *three = create_item("three", 101, 1, "publisher");
	two->next = three;
	three->prev = two;
	t_item *four = create_item("four", 6, 1, "publisher");
	three->next = four;
	four->prev = three;
	t_item *five = create_item("five", 5, 1, "publisher");
	four->next = five;
	five->prev = four;
	t_item *six = create_item("six", 6, 1, "publisher");
	five->next = six;
	six->prev = five;
	t_item *seven = create_item("seven", -1, 1, "publisher");	
	six->next = seven;
	seven->prev = six;
	t_item *eight = create_item("eight", 20, 1, "publisher");
	seven->next = eight;
	eight->prev = seven;
	t_item *nine = create_item("nine", 9, 1, "publisher");
	nine->prev = eight;
	eight->next = nine;
	t_item *ten = create_item("ten", 10, 1, "publisher");
	nine->next = ten;
	ten->prev = nine;
	ten->next = NULL;
	return(head);
}