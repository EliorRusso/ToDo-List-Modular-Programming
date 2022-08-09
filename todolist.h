typedef struct ToDo todo;
struct ToDo{
 char data[100];
 todo *link;
 int count;
};
void seeTasks(todo *start);
//******************
//general: Called when the user want to see tasks. Simply going node after node and printing it's data.
//
//params: start - base pointer to the start of the task list.
//
//return: Doesn't return anything.
//******************
todo* createtasks(todo* start);
//******************
//general: Called when the user want to create new tasks.
//
//params: start - base pointer to the start of the task list.
//temp - used as an extra parameter for the list.
//
//return: The modified list.
//******************
todo* deleteTasks(todo *start);
//******************
//general: Called when the user want to delete tasks. 
//
//params: start - base pointer to the start of the task list.
//temp - used as an extra parameter for the list.
//temp1 - used as an extra parameter for the list.
//
//return: The modified list.
//******************
void fixcount(todo *start);
//******************
//general: Called when a change to the list occurs. The function fixes the lines numbers accirding to the tasks count.
//
//params: start - base pointer to the start of the task list.
//
//return: The modified list.
//******************
todo* updateTasks(todo *start);
//general: Called when a user want to update a list.
//
//params: start - base pointer to the start of the task list.
//temp - used to an extra pointer to modify the list.
//return: The modified list.
//******************