FILE *fpointer;
char singleline[150];
int new_id = 0;
int employee_index = -1 ;

struct employee
{
  int id;
  char fname[20];
  char lname[20];
  int age;
  float salary;
  struct employee *next;
  struct employee *prev;
};

struct employee *start = NULL;
struct employee *new;
struct employee *current;
struct employee *super_hero = NULL;


/*
*Function: upperLower
*used to convert the first string char into upper case and the remaining char to lower case
*
*name is string refer to the string will type casting
*
*return pointer to array of string
*/
char *upperLower(char name[20])
{

  name[0] = toupper(name[0]);

  for (int too = 1; name[too] != NULL; ++too)
  {

    name[too] = tolower(name[too]);
  }

  return name;
}


/*
*Function: startNULLchecker
*used to check if there are linked list or not
*
*startNULLcheckerTemp is pointer = start
*
*return 1 if there are linked list or 
*return 0 if aren't linked list
*/
int startNULLchecker(struct employee *startNULLcheckerTemp)
{
  int checker = 1;
  if (startNULLcheckerTemp == NULL)
  {
    puts("No Employee Yet.");
    checker = 0;
  }

  return checker;
}


/*
*Function: ID_checker
*used to check a spacific id is it in the linked list or not
*
*checker is integer number = to the id we want to check
*
*return 1 if the id in the linked list
*return 0 if the id not in the linked list
*/
int ID_checker(int checker)
{
  struct employee *ID_checkertemp = start;
  while (ID_checkertemp != NULL)
  {
    if (ID_checkertemp->id == checker)
    {
      return 1;
    }
    ID_checkertemp = ID_checkertemp->next;
  }

  puts("\nEntered ID is not found!\n");
  return 0;
}



/*
*Function: stringTofloat
*used to convert string into float number
*
*string is string array equal to the string which we will convert it
*
*return floatnum
*/
float stringTofloat(char string[])
{

  float floatnum;

  sscanf(string, "%f", &floatnum);

  return floatnum;
}


/*
*Function: stringToint
*used to convert string into float number
*
*string is string array equal to the string which we will convert it
*
*return intnum
*/
int stringToint(char string[20])
{

  int intnum;
  sscanf(string, "%d", &intnum);

  return intnum;
}


/*
*Function: askForID
*used to ask user for the id
*
*return id
*/
int askForID()
{
  int id = 0;
  puts("Enter Employee ID");
  scanf("%d", &id);
  return id;
}
