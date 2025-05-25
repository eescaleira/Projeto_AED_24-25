#include "gestor.h"

//insertion sort
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

//selection sort by id
t_item* orderByIdItem(t_item* head) {
    if (!head || !head->next) 
        return head;
    t_item* sorted = NULL;
    while (head) {
        t_item* min = head;
        t_item* current = head->next;
        while (current) {
            if (current->id < min->id) {
                min = current;	
            }
            current = current->next;
        }
        if (min->prev)
            min->prev->next = min->next;
        if (min->next)
            min->next->prev = min->prev;
        if (min == head)
            head = head->next;
        min->prev = NULL;
        min->next = NULL;
        if (!sorted) {
            sorted = min;
        } else {
            t_item* tail = sorted;
            while (tail->next)
                tail = tail->next;
            tail->next = min;
            min->prev = tail;
        }
    }
    return sorted;
}


//binary search by id
t_item* binary_search_by_id(t_item* head, int id) {
    int left = 0;
    int right = list_length(head) - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        t_item* mid_node = get_node_at(head, mid);

        if (!mid_node) 
            break;
        if (mid_node->id == id) {
            return mid_node;
        } else if (mid_node->id < id) {
            left = mid + 1;
            right = list_length(head) - 1; 
        } else {
            right = mid - 1;
        }
        if(left == right && mid_node->id != id) {
            return NULL; 
        }
    }

    return NULL;
}