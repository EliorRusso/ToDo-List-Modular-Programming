#include <stdio.h>
#include <stdlib.h>
#include "todolist.h"
#include "functions.c"

int main()
{
  todo *start=NULL;
  todo *lis = NULL;
    int choice;
    while(1){
        printf("\n1.See Tasks");
        printf("\n2.Create Tasks");
        printf("\n3.Delete Tasks");
        printf("\n4.Update Tasks");
        printf("\n5.Exit");
        printf("\n\nEnter choice");
        scanf("%d",&choice);
        switch(choice){
      case 1:
          seeTasks(lis);
        break;
      case 2:
          lis = createtasks(lis);
        break;
      case 3:
          lis = deleteTasks(lis);
        break;
      case 4:
         lis = updateTasks(lis);
         break;
      case 5:
        exit(0);
        }
    }
}