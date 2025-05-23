#include "gestor.h"


t_item* orderbyname(t_item* head) {
    if (head == NULL || head->next == NULL)
        return head;
    t_item* sorted = NULL;
    while (head != NULL) {
        t_item* current = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        current->prev = current->next = NULL;
        if (sorted == NULL) {
            sorted = current;
        } else if (strcmp(current->title, sorted->title) < 0) {
            // Inserir no início
            current->next = sorted;
            sorted->prev = current;
            sorted = current;
        } else {
            t_item* temp = sorted;
            while (temp->next != NULL && strcmp(temp->next->title, current->title) < 0) {
                temp = temp->next;
            }
            current->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = current;

            temp->next = current;
            current->prev = temp;
        }
    }
    return sorted;
}

 
int main(){
	t_item *item_list = make_list();
	if (item_list == NULL) {
		fprintf(stderr, "Failed to create item list\n");
		return EXIT_FAILURE;
	}
	t_item *temp = item_list;
	while(temp != NULL){
		printf("Item ID: %s\n", temp->title);
		temp = temp->next;
	}
	item_list = orderbyname(item_list);
	printf("\n\n");
	while(item_list != NULL){
		printf("Item ID: %s\n", item_list->title);
		item_list = item_list->next;
	}
	return 0;
}