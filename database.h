/*
*Function: updateFile
*used to update file
*upDate is pointer
* 
*void func
*/
void updateFile(struct employee *upDate)
{

  fpointer = fopen(DB, "w");
  while (upDate != NULL)
  {
    if (upDate->id != start->id)
    {
      fprintf(fpointer, "\n");
    }

    fprintf(fpointer, "%d;%s;%s;%d;%.2f", upDate->id, upDate->fname, upDate->lname, upDate->age, upDate->salary);
    upDate = upDate->next;
  }

  fclose(fpointer);
}



/*
*Function: insertLinkedListFromFile
*used to update the new_id
*
*id is int number = id
*fname is string = the first name
*lname is string = the last name
*age is int num = age
*salary is float num =  salary
* 
*void func
*/
void insertLinkedListFromFile(int id, char fname[], char lname[], int age, float salary)
{
  new_id = id;
  insertToLinkedList(id, fname, lname, age, salary);
}

/*
*Function: DBconverter
*used to read data from file
* 
*void func
*/
void DBconverter()
{

  char singleline[100];

  FILE *fpointer;

  char idstring[20] = "stilVersion!", fnamestring[20], lnamestring[20], agestring[20], salarystring[20];

  fpointer = fopen(DB, "r");

  while (!feof(fpointer))
  {

    //ID  %[^;]  regular expresion
    fscanf(fpointer, "%[^;]", idstring);

    // Check the idstring has overwritten from file or not
    if (strcmp(idstring, "stilVersion!") == 0)
    {
      // if idstring has not overwritten, then the file contains only a new line.
      return;
    }

    fseek(fpointer, 1, SEEK_CUR);

    //FNAME

    fscanf(fpointer, "%[^;]", fnamestring);
    strcpy(fnamestring, upperLower(fnamestring));


    fseek(fpointer, 1, SEEK_CUR);

    //LNAME

    fscanf(fpointer, "%[^;]", lnamestring);
    strcpy(lnamestring, upperLower(lnamestring));


    fseek(fpointer, 1, SEEK_CUR);

    //AGE

    fscanf(fpointer, "%[^;]", agestring);

    fseek(fpointer, 1, SEEK_CUR);

    //SALARY

    fscanf(fpointer, "%[^\n]", salarystring);

    insertLinkedListFromFile(stringToint(idstring), fnamestring, lnamestring, stringToint(agestring), stringTofloat(salarystring));
  }

  fclose(fpointer);
}
