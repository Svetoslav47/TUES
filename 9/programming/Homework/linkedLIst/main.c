#include <stdio.h>
#include "tasklist.h"

void printMenu()
{
  printf("1. Add a task\n");
  printf("2. Change task status\n");
  printf("3. Delete a task\n");
  printf("4. Display tasks\n");
  printf("5. Exit\n");
}

int main()
{
  TaskList list = initTasklist();
  int choice = 0;

  while (choice != 5)
  {
    printMenu();
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
    {
      char name[100];
      int priority;
      printf("Enter task name: ");
      scanf(" %[^\n]", name);
      printf("Enter task priority: ");
      scanf("%d", &priority);
      addTask(&list, name, priority);
      break;
    }
    case 2:
    {
      int priority;
      int status;
      printf("Enter task priority: ");
      scanf("%d", &priority);
      printf("Enter new status (0: NEW, 1: STARTED, 2: COMPLETED): ");
      scanf("%d", &status);
      changeTaskStatus(&list, priority, (TaskStatus)status);
      break;
    }
    case 3:
    {
      int priority;
      printf("Enter task priority: ");
      scanf("%d", &priority);
      deleteTask(&list, priority);
      break;
    }
    case 4:
      displayTasks(&list);
      break;
    case 5:
      printf("Exiting...\n");
      break;
    default:
      printf("Invalid choice, please try again.\n");
      break;
    }
  }

  freeTasklist(&list);
  return 0;
}
