typedef struct ToDo todo;
struct ToDo{
 char data[100];
 todo *link;
 int count;
};
void seeTasks(todo *s);//Called when the user want to see tasks. Simply going node after node and printing it's data.
todo* createtasks(todo* s);//Called when the user want to create tasks. 
todo* deleteTasks(todo *s);
void fixcount(todo *s);
todo* updateTasks(todo *s);