#ifndef TASKLIST_H
#define TASKLIST_H

typedef enum
{
  NEW,
  STARTED,
  COMPLETED
} TaskStatus;

typedef struct Task
{
  char *name;
  int priority;
  TaskStatus status;
  struct Task *next;
} Task;

typedef struct TaskList
{
  Task *head;
} TaskList;

TaskList initTasklist();
void addTask(TaskList *list, char *name, int priority);
void changeTaskStatus(TaskList *list, int priority, TaskStatus status);
void deleteTask(TaskList *list, int priority);
void displayTasks(const TaskList *list);
void freeTasklist(TaskList *list);

#endif // TASKLIST_H