#include "tasklist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TaskList initTasklist()
{
  TaskList list;
  list.head = NULL;
  return list;
}

void addTask(TaskList *list, char *name, int priority)
{
  Task *newTask = (Task *)malloc(sizeof(Task));
  newTask->name = strdup(name);
  newTask->priority = priority;
  newTask->status = NEW;
  newTask->next = NULL;

  if (list->head == NULL || list->head->priority > priority)
  {
    newTask->next = list->head;
    list->head = newTask;
  }
  else
  {
    Task *current = list->head;
    while (current->next != NULL && current->next->priority < priority)
    {
      current = current->next;
    }
    newTask->next = current->next;
    current->next = newTask;
  }
}

void changeTaskStatus(TaskList *list, int priority, TaskStatus status)
{
  Task *current = list->head;
  while (current != NULL)
  {
    if (current->priority == priority)
    {
      current->status = status;
      return;
    }
    current = current->next;
  }
}

void deleteTask(TaskList *list, int priority)
{
  if (list->head == NULL)
  {
    return;
  }

  Task *current = list->head;
  if (current->priority == priority)
  {
    list->head = current->next;
    free(current->name);
    free(current);
    return;
  }

  while (current->next != NULL && current->next->priority != priority)
  {
    current = current->next;
  }

  if (current->next != NULL)
  {
    Task *toDelete = current->next;
    current->next = toDelete->next;
    free(toDelete->name);
    free(toDelete);
  }
}

void displayTasks(const TaskList *list)
{
  Task *current = list->head;
  while (current != NULL)
  {
    printf("Priority: %d, Name: %s, Status: ", current->priority, current->name);
    switch (current->status)
    {
    case NEW:
      printf("NEW\n");
      break;
    case STARTED:
      printf("STARTED\n");
      break;
    case COMPLETED:
      printf("COMPLETED\n");
      break;
    }
    current = current->next;
  }
}

void freeTasklist(TaskList *list)
{
  Task *current = list->head;
  while (current != NULL)
  {
    Task *toDelete = current;
    current = current->next;
    free(toDelete->name);
    free(toDelete);
  }
  list->head = NULL;
}