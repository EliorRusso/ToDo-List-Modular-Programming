void seeTasks(todo *start){
  system("clear");
   todo *temp;
   temp=start;
        if(start==NULL){
           printf("\nEmpty TODO\n\n");
        }
       while(temp!=NULL){
          printf("%d)",temp->count); //As long as we havn't reached the end of the task list keep printing the data.
          puts(temp->data);
          fflush(stdin);
          temp=temp->link;
        }
        sleep(3);
       printf("\n\n\n");
   }

todo* createtasks(todo* start){
    char k;
    todo *t,*temp;
    fflush(stdin);
    fgets(&k, 12, stdin);
    //scanf("%c",&k);
    if(start==NULL){ //Incase the list is empty, it adds one node to the list.
        t=(todo *)calloc(1,sizeof(todo)); //allocating node memory for adding it to the end of the list.
        start=t;
        printf("\nADD it..\n");
        fflush(stdin); //Clearing the stdin buffer.
        fgets(&(t->data), 12, stdin);
        t->count=1;
        start->link=NULL;
       }
    else{
       temp=(todo *)calloc(1,sizeof(todo));
       printf("\nADD it..\n");
       printf("\n");//Allocating node memory for adding it to the end of the list
       fflush(stdin);
       fgets(&(temp->data), 12, stdin);
       temp->link=NULL;
       t->link=temp;
       t=t->link;
     }fixcount(start);
  return start;
}
todo* deleteTasks(todo *start){
  int inputnum;
  todo *temp1,*temp;
  printf("\nEnter the no of the task you want to remove\n");
  scanf("%d",&inputnum);
  temp1=start;
  temp=start->link;
  while(1){
    if(temp1->count==inputnum){//Using two nodes and freeing the middle one between them, after we call the fixcount in order the keep the order of the tasks.
      start=start->link;
      free(temp1);
      fixcount(start);
      break;
    }
    if(temp->count==inputnum){
        temp1->link=temp->link;
        free(temp);
        fixcount(start);
        break;
    }
    else{
        temp1=temp;
        temp=temp->link;
    }
  }
  return start;
}

void fixcount(todo *start){ //Function I found on the internet to fix the order of the list, it counts the number of nodes and changes the order accordingly.
  todo *temp;
  int i=1;
  temp=start;
  while(temp!=NULL){
    temp->count=i;
    i++;
    temp=temp->link;
  }

}

todo* updateTasks(todo *start){
  int d,x;
  todo *temp;
  printf("\nEnter the no of the task you want to update\n");
  scanf("%d",&d);
  temp = start;
  while(temp->count != d){ //as long as we didn't reach the count of the task, keep going.
    temp = temp->link;
  }
  printf("\nEnter the task you want to update\n");
  fflush(stdin);//Clearing  the buffer
  scanf("%s",&temp->data); //Getting the input from the user and changed the data of the requested node.
  printf("Updated, returning to the main lobby\n");
  sleep(2);
  return start;
  }