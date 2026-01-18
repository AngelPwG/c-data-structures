#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct queue {
  char name[15];
  int size;
  struct queue *next;
};

typedef struct queue node;
typedef node *NODEPTR;

int main() {
  int opc = 0;
  char name[15];
  NODEPTR new = NULL;
  NODEPTR start = NULL;
  NODEPTR current = NULL;
  NODEPTR prev = NULL;
  do {

    printf("1)Add File (Enqueue)\n2)Print File (Dequeue)\n3)Cancel File\n4)Give Priority (Move to 2nd pos)\n5)Show Queue\n6)Exit\nChoose an option: ");
    scanf("%i", &opc);

    switch (opc) {
    case 1:
      new = (node *)malloc(sizeof(node));
      printf("\nFile name: ");
      scanf("%s", new->name);
      printf("\nFile size: ");
      scanf("%i", &new->size);
      new->next = NULL;
      if (start == NULL)
        start = new;
      else {
        for (current = start; current->next != NULL; current = current->next);
        current->next = new;
      }
      printf("%s added", new->name);
      getchar();
      break;
    case 2:
      current = start;
      start = start->next;
      printf("\nThe file %s was printed", current->name);
      free(current);
      getchar();
      break;
    case 3:
      printf("\nEnter the name of the file to cancel: ");
      scanf("%s", name);
      for (current = start; current != NULL; prev = current, current = current->next)
        if (strcmp(current->name, name) == 0)
          break;
      if (current == NULL)
        printf("The file was not found");
      else {
        printf("File name: %s\nFile size: %i\n", current->name, current->size);
        printf("Do you want to cancel it? (0. Yes) (1. No)");
        int opc2 = 0;
        scanf("%i", &opc2);
        if (opc2 == 0) {
          if (current == start)
            start = start->next;
          else
            prev->next = current->next;
          printf("%s canceled", current->name);
          free(current);
          getchar();
        }
      }
      break;
    case 4:
      printf("\nEnter the name of the file to priorize el nombre del archivo a darle prioridad: ");
      scanf("%s", name);
      for (current = start; current != NULL; prev = current, current = current->next)
        if (strcmp(current->name, name) == 0)
          break;
      if (current == NULL)
        printf("The file was not found");
      else {
        if (current == start || prev == start)
          printf("Cannot give priority to the first or second file on the queue\n");
        else {
          printf("File name: %s\nFile size: %i\n", current->name, current->size);
          printf("Do you want to give it priority? (0. Yes) (1. No)");
          int opc2;
          scanf("%i", &opc2);
          if (opc2 == 0) {
            prev->next = current->next;
            current->next = start->next;
            start->next = current;
          }
        }
        getchar();
      }
      break;
    case 5:
      printf("File name\tSize");
      for (current = start; current != NULL; current = current->next)
        printf("\n%s\t\t%i", current->name, current->size);
      getchar();
      break;
    case 6:
      break;
    default:
      printf("Choose a valid option\n");
      getchar();
      break;
    }
  } while (opc != 6);
  for (current = start; current != NULL; start = current) {
    current = start->next;
    free(start);
  }

  return 0;
}
