/*
*Functio :insertToLinkedList
*insert employee in the linked list
*
*id is the employee
*Fname is the first name of the employee
*Lname is thr last name of thr employee
*age is the employee age
*salary is the employee salary
*
*void function
*/
void insertToLinkedList(int id, char fname[20], char lname[20], int age, float salary)
{
  new = malloc(sizeof(struct employee));

  new->id = id;

  strncpy(new->fname, upperLower(fname), 20);

  strncpy(new->lname, upperLower(lname), 20);

  new->age = age;

  new->salary = salary;

  new->next = NULL;

  if (start == NULL)
  {
    start = new;
    start->prev = NULL;
    current = new;
    super_hero = start;
  }
  else
  {
    current->next = new;
    new->prev = current;
    current = new;
  }
}

/*
*Functio :insert_employee
*insert employee in the database file
*
*Fname is the first name of the employee
*Lname is thr last name of thr employee
*age is the employee age
*salary is the employee salary
*
*void function
*/
void insert_employee(char fname[20], char lname[20], int age, float salary)
{

  fpointer = fopen(DB, "a");

  int id = ++new_id;

  insertToLinkedList(id, fname, lname, age, salary);

  if (id > 1)
  {
    fprintf(fpointer, "\n");
  }

  fprintf(fpointer, "%d;%s;%s;%d;%.2f", new->id, new->fname, new->lname, new->age, new->salary);
  fclose(fpointer);
}

/*
*Functio :listLinkedlist
*list the linked list from the software
*
*temp_list is pointer = start
*
*void function
*/
void listLinkedlist(struct employee *temp_list)
{
  puts("ID\tFirst Name\t\tLast Name\t\tAge\tSalary\n");
  while (temp_list != NULL)
  {
    printf("%d\t%s\t\t%s\t\t%d\t%.2f\n", temp_list->id, temp_list->fname, temp_list->lname, temp_list->age, temp_list->salary);
    temp_list = temp_list->next;
  }
}

/*
*Function: swap
*used to swap all index in 2 nodes
*
*a and b are pointers tos the greater node index and the smaller node index
*
*void func
*/
void swap(struct employee *a, struct employee *b)
{
  int temp;
  temp = a->id;
  a->id = b->id;
  b->id = temp;

  char name[20];
  strcpy(name, a->fname);
  strcpy(a->fname, b->fname);
  strcpy(b->fname, name);

  strcpy(name, a->lname);
  strcpy(a->lname, b->lname);
  strcpy(b->lname, name);

  int temp1;
  temp1 = a->age;
  a->age = b->age;
  b->age = temp1;

  float temp2;
  temp2 = a->salary;
  a->salary = b->salary;
  b->salary = temp2;
}

int swapped, i;
struct employee *sort1;
/*
*Function: swapCondition
*used to check the right condtion
*
*int n is refer to the condition which we will sawp using it
*
*void func
 */
void swapCondition(int n)
{
  if (n == 1)
  {
    if (strcmp(sort1->fname, sort1->next->fname) > 0)

    {
      swap(sort1, sort1->next);
      swapped = 1;
    }
  }
  else if (n == 2)
  {
    if (sort1->age > sort1->next->age)
    {
      swap(sort1, sort1->next);
      swapped = 1;
    }
  }
  else if (n == 3)
  {
    if (sort1->salary > sort1->next->salary)
    {
      swap(sort1, sort1->next);
      swapped = 1;
    }
  }
  else if (n == 4)
  {
    if (sort1->id > sort1->next->id)
    {
      swap(sort1, sort1->next);
      swapped = 1;
    }
  }
}

/*
*Function sort_Employee
*used to sort the linked list
*
*int n is refer to the type of sorting
*
*soid func
*/
void sort_Employees(int n)
{

  do
  {
    swapped = 0;
    sort1 = start;

    while (sort1->next != NULL)
    {
      swapCondition(n);

      sort1 = sort1->next;
    }

  } while (swapped);
}

struct employee *search_temp;

/*
*Function: searchCondition
*at first check the type of searching are by first name of by last name
*
*n is intege number = the type of searching by first name if (n== 1) or lalstname if(n == 2)
*search is string = the name which the user want to search for 
*
*void func
*/
void searchCondition(int n, char search[])
{
  if (n == 1)
  {
    if (strcmp(search_temp->fname, search) == 0)
    {
      printf("%d\t%s\t\t%s\t\t%d\t%.2f\n", search_temp->id, search_temp->fname, search_temp->lname, search_temp->age, search_temp->salary);
    }
  }
  else
  {
    if (strcmp(search_temp->lname, search) == 0)
    {
      printf("%d\t%s\t\t%s\t\t%d\t%.2f\n", search_temp->id, search_temp->fname, search_temp->lname, search_temp->age, search_temp->salary);
    }
  }
}

/*
*Function: searchEmployee
*used to search for spacfic employee by first name of last name

*n is intege number = id 
*status is string = the status of searching by first name of last name
*
*void func
*/
void searchEmployee(int n, char status[])
{

  char search[20];

  printf("Enter The %s\n", status);
  scanf("%s", &search);
  strncpy(search, upperLower(search), 20);
  puts("ID\tFirst Name\tLast Name\tAge\tSalary");

  search_temp = start;
  while (search_temp != NULL)
  {

    searchCondition(n, search);

    search_temp = search_temp->next;
  }
}

struct employee *updateEmployeTemp;

/*
*Function: Updateinfo
*used to update aspacfic employee info
*
*n is intege number refer to what kind of data will update if(n==1) user want to update first name
*                                                          if(n==2)                     last name
*                                                          if(n==3) user want to update age
*                                                          if(n==4) user want to update salary
*
*void func
 */
void Updateinfo(int n)
{
  if (n == 1)
  {
    scanf("%s", &updateEmployeTemp->fname);
    strcpy(updateEmployeTemp->fname, upperLower(updateEmployeTemp->fname));
  }
  else if (n == 2)
  {
    scanf("%s", &updateEmployeTemp->lname);
    strcpy(updateEmployeTemp->lname, upperLower(updateEmployeTemp->lname));
  }
  else if (n == 3)
  {
    scanf("%d", &updateEmployeTemp->age);
  }
  else
  {
    scanf("%f", &updateEmployeTemp->salary);
  }
}

/*
*Function: update_Employee
*used to loop is the linked list and chech if user id equal to the employee id in the linked list
*
*update is string equal to the status of the update type are it first name or last name or age or salary
*id is integer number equal to the id what user want to update info 
*
*void func
 */
void update_Employee(int n, char update[10], int id)
{

  printf("Enter The New %s\n", update);
  updateEmployeTemp = start;
  while (updateEmployeTemp != NULL)
  {

    if (updateEmployeTemp->id == id)
    {
      Updateinfo(n);
      updateEmployeTemp = updateEmployeTemp->next;
    }
    else
    {
      updateEmployeTemp = updateEmployeTemp->next;
    }
  }
}

/*
*Function: delete_employee
*used to delet spacfic employee from the linked list
*
*id is integer number equal to the employee's id  which user want to delete
*
*void func
*/
void delete_employee(int id)
{

  // Store head node
  struct employee *deleteTemp = start, *previous;

  // If head node itself holds the key to be deleted
  if (deleteTemp->id == id)
  {

    start = deleteTemp->next; // Changed head
    start->prev = NULL ;
    super_hero = start;
    free(deleteTemp); // free old head
    return;
  }

  // Search for the key to be deleted, keep track of the
  // previous node as we need to change 'prev->next'
  while (deleteTemp->id != id)
  {
    previous = deleteTemp;
    deleteTemp = deleteTemp->next;
    //deleteTemp->prev = previous
  }

  // Unlink the node from linked list
  previous->next = deleteTemp->next;
  //deleteTemp->next->prev = deleteTemp->prev ;

  free(deleteTemp); // Free memory

  current = start;
  while (current->next != NULL)
  {
    current = current->next;
  }

  return;
}
