void seeTasks(todo *s){
  system("clear");
   todo *temp;
   temp=s;
        if(s==NULL){
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

todo* createtasks(todo* s){
    char k;
    todo *t,*temp;
    fflush(stdin);
    scanf("%c",&k);
    if(s==NULL){ //Incase the list is empty, it adds one node to the list.
        t=(todo *)calloc(1,sizeof(todo)); //allocating node memory for adding it to the end of the list.
        s=t;
        printf("\nADD it..\n");
        fflush(stdin); //Clearing the stdin buffer.
        gets(t->data);
        t->count=1;
        s->link=NULL;
       }
    else{
       temp=(todo *)calloc(1,sizeof(todo));
       printf("\nADD it..\n");
       printf("\n");//Allocating node memory for adding it to the end of the list
       fflush(stdin);
       gets(temp->data);
       temp->link=NULL;
       t->link=temp;
       t=t->link;
     }fixcount(s);
  return s;
}
todo* deleteTasks(todo *s){
  int d;
  todo *temp1,*temp;
  printf("\nEnter the no of the task you want to remove\n");
  scanf("%d",&d);
  temp1=s;
  temp=s->link;
  while(1){
    if(temp1->count==d){//Using two nodes and freeing the middle one between them, after we call the fixcount in order the keep the order of the tasks.
      s=s->link;
      free(temp1);
      fixcount(s);
      break;
    }
    if(temp->count==d){
        temp1->link=temp->link;
        free(temp);
        fixcount(s);
        break;
    }
    else{
        temp1=temp;
        temp=temp->link;
    }
  }
  return s;
}

void fixcount(todo *s){ //Function I found on the internet to fix the order of the list, it counts the number of nodes and changes the order accordingly.
  todo *temp;
  int i=1;
  temp=s;
  while(temp!=NULL){
    temp->count=i;
    i++;
    temp=temp->link;
  }

}

todo* updateTasks(todo *s){
  int d,x;
  todo *temp1,*temp;
  printf("\nEnter the no of the task you want to update\n");
  scanf("%d",&d);
  temp = s;
  while(temp->count != d){ //as long as we didn't reach the count of the task, keep going.
    temp = temp->link;
  }
  printf("\nEnter the task you want to update\n");
  fflush(stdin);//Clearing  the buffer
  scanf("%s",&temp->data); //Getting the input from the user and changed the data of the requested node.
  printf("Updated, returning to the main lobby\n");
  sleep(2);
  return s;
  }