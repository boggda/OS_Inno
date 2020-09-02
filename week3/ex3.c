#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
  int value;
  struct Node *next;
};

void insert_node(struct Node** head, int value, int new_value)
{
  struct Node *t = (struct Node*)malloc(sizeof(struct Node));
  t->value = new_value;

  if (!(*head))
  {
    t->next = (*head);
    (*head) = t;
    return;
  }

  struct Node *current = *head;
  while(current->value != value)
  {
    if (!current->next)
      break;
    else
      current = current->next;
  }

  t->next = current->next;
  current->next = t;
}

void delete_node(struct Node** head, int value)
{
  struct Node *current = *head, *prev;

  if (current != NULL && current->value == value)
  {
    *head = current->next;
    free(current);
    return;
  }

  while (current != NULL && current->value != value)
  {
    prev = current;
    current = current->next;
  }

  if (current == NULL)
    return;

  prev->next = current->next;
  free(current);
}

void print_list(struct Node *head){
    while (head)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    putchar('\n');
}

int main(void)
{
  struct Node *head = NULL;
  puts("[+] Add 5 to list:");
  insert_node(&head, NULL, 5);
  print_list(head);

  puts("[+] Add 10 after 5:");
  insert_node(&head, 5, 10);
  print_list(head);

  puts("[+] Add 4 in the end of list:");
  insert_node(&head, NULL, 4);
  print_list(head);

  puts("[+] Add 7 after 10:");
  insert_node(&head, 10, 7);
  print_list(head);

  puts("[+] Add 9 after 4:");
  insert_node(&head, 4, 9);
  print_list(head);

  puts("[+] Delete 7:");
  delete_node(&head, 7);
  print_list(head);

  puts("[+] Delete 9:");
  delete_node(&head, 9);
  print_list(head);

  puts("[++] FINAL LIST:");
  print_list(head);
  return 0;
}
