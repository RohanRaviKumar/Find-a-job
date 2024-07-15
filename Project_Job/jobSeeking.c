#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct seeker_data
{
  char name[30];
  char pwd[20];
  char pno[10];
  char email[30];
  char dob[10];
  float tenth;
  float twelfth;
  char UG[10];
  float CGPA;
  int Exp;
  char location1[20];
  char location2[20];
  int shift;
  long int expected_salary;
  float score;
  char allocated_company[50];
  char allocated_location[20];
  float percentage_match;
  char status[20];
};

struct company_data
{
  char cmp_name[20];
  char cmp_pwd[20];
  int cmp_type;
  float min_tenth;
  float min_twelfth;
  int work_exp;
  char location[20];
  int day_vac;
  int night_vac;
  float score_requirement;
  long int off_salary;
};

struct seeker_data s1[50];
struct seeker_data s[1];
struct company_data e1[50];
struct company_data e[1];
int seeker_count = 0, company_count = 0;

void reading(int user)
{
  if (user == 1)
  {
    FILE *fp;
    fp = fopen("seeker.csv", "r");
    if (fp == NULL)
    {
      printf("Error opening the file\n");
      exit(1);
    }
    char line[200];
    char str[100];

    while (fgets(line, sizeof(line), fp))
    {
      char *field = strtok(line, ",");
      int field_count = 0;

      while (field)
      {
        if (field_count == 0)
        {
          strncpy(s1[seeker_count].name, field,sizeof(s1[seeker_count].name) - 1);
          s1[seeker_count].name[sizeof(s1[seeker_count].name) - 1] = '\0';
        }
        if (field_count == 1)
        {
          strncpy(s1[seeker_count].pwd, field,sizeof(s1[seeker_count].pwd) - 1);
          s1[seeker_count].pwd[sizeof(s1[seeker_count].pwd) - 1] = '\0';
        }
        if (field_count == 2) 
        {
          strncpy(s1[seeker_count].pno, field,sizeof(s1[seeker_count].pno) - 1);
          s1[seeker_count].pno[sizeof(s1[seeker_count].pno) - 1] = '\0';
        }
        if (field_count == 3) 
        {
          strncpy(s1[seeker_count].email, field,sizeof(s1[seeker_count].email) - 1);
          s1[seeker_count].email[sizeof(s1[seeker_count].email) - 1] = '\0';
        }
        if (field_count == 4)
        {
          strncpy(s1[seeker_count].dob, field,sizeof(s1[seeker_count].dob) - 1);
          s1[seeker_count].dob[sizeof(s1[seeker_count].dob) - 1] = '\0';
        }
        if (field_count == 5)
        {
          s1[seeker_count].tenth = strtof(field, NULL);
        }
        if (field_count == 6)
        {
          s1[seeker_count].twelfth = atof(field);
        }
        if (field_count == 7)
        {
          strncpy(s1[seeker_count].UG, field, sizeof(s1[seeker_count].UG) - 1);
          s1[seeker_count].UG[sizeof(s1[seeker_count].UG) - 1] = '\0';
        }
        if (field_count == 8) 
        {
          s1[seeker_count].CGPA = atof(field);
        }
        if (field_count == 9) 
        {
          s1[seeker_count].Exp = atoi(field);
        }
        if (field_count == 10) 
        {
          strncpy(s1[seeker_count].location1, field,sizeof(s1[seeker_count].location1) - 1);
          s1[seeker_count].location1[sizeof(s1[seeker_count].location1) - 1] ='\0';
        }
        if (field_count == 11) 
        {
          strncpy(s1[seeker_count].location2, field,sizeof(s1[seeker_count].location2) - 1);
          s1[seeker_count].location2[sizeof(s1[seeker_count].location2) - 1] ='\0';
        }
        if (field_count == 12) 
        {
          s1[seeker_count].shift = atoi(field);
        }
        if (field_count == 13) 
        {
          s1[seeker_count].expected_salary = strtol(field, NULL, 10);
        }
        if (field_count == 14) 
        {
          s1[seeker_count].score = atof(field);
        }
        field = strtok(NULL, ",");
        field_count++;
      }
      seeker_count++;
    }
    fclose(fp);
  }

  else if (user == 2)
  {
    FILE *fp;
    fp = fopen("employer.csv", "r");
    if (fp == NULL)
    {
      printf("Error opening the file\n");
      exit(1);
    }
    char line[200];
    char str[100];

    while (fgets(line, sizeof(line), fp)) 
    {
      char *field = strtok(line, ",");
      int field_count = 0;
      while (field) 
      {
        if (field_count == 0) 
        {
          strncpy(e1[company_count].cmp_name, field,sizeof(e1[company_count].cmp_name) - 1);
          e1[company_count].cmp_name[sizeof(e1[company_count].cmp_name) - 1] ='\0';
        }
        if (field_count == 1) 
        {
          strncpy(e1[company_count].cmp_pwd, field,sizeof(e1[company_count].cmp_pwd) - 1);
          e1[company_count].cmp_pwd[sizeof(e1[company_count].cmp_pwd) - 1];
        }
        if (field_count == 2) 
        {
          e1[company_count].cmp_type = atoi(field);
        }
        if (field_count == 3) 
        {
          e1[company_count].work_exp = atoi(field);
        }
        if (field_count == 4) 
        {
          e1[company_count].off_salary = strtol(field, NULL, 0);
        }
        if (field_count == 5) 
        {
          strncpy(e1[company_count].location, field,sizeof(e1[company_count].location) - 1);
          e1[company_count].location[sizeof(e1[company_count].location) - 1] ='\0';
        }
        if (field_count == 6) 
        {
          e1[company_count].day_vac = atoi(field);
        }
        if (field_count == 7) 
        {
          e1[company_count].night_vac = atoi(field);
        }
        if (field_count == 8) 
        {
          e1[company_count].score_requirement = strtof(field, NULL);
        }
        if (field_count == 9) 
        {
          e1[company_count].min_tenth = strtof(field, NULL);
        }
        if (field_count == 10) 
        {
          e1[company_count].min_twelfth = strtof(field, NULL);
        }
        field = strtok(NULL, ",");
        field_count++;
      }
      company_count++;
    }
    fclose(fp);
  }
}

void WritingToFile(int seeker)
{
  FILE *fp;
  fp = fopen("job.csv", "a");
  for (int count = 0; count < seeker_count; count++) 
  {
    if (count == seeker) 
    {
      fprintf(fp,"%s,%s,%s,%s,%s,%.2f,%.2f,%s,%.2f,%d,%s,%s,%d,%ld,%.2f,%s,%s,%s\n",
              s1[count].name, s1[count].pwd, s1[count].pno, s1[count].email,
              s1[count].dob, s1[count].tenth, s1[count].twelfth, s1[count].UG,
              s1[count].CGPA, s1[count].Exp, s1[count].location1,
              s1[count].location2, s1[count].shift, s1[count].expected_salary,
              s1[count].score, s1[count].allocated_company,
              s1[count].allocated_location, s1[count].status);
    }
  }
  fclose(fp);
}

int login(char name[20], char pwd[20], int user)
{
  if (user == 1) 
  {
    for (int s = 0; s < seeker_count; s++) 
    {
      if ((strcmp(name, s1[s].name) == 0 && (strcmp(pwd, s1[s].pwd) == 0))) 
      {
        return 1;
      }
    }
    return 0;
  }

  else if (user == 2) 
  {
    for (int s = 0; s < company_count; s++) 
    {
      if ((strcmp(name, e1[s].cmp_name) == 0 &&(strcmp(pwd, e1[s].cmp_pwd) == 0))) 
      {
        return 1;
      }
    }
    return 0;
  }
}

void registration(int user) 
{
  if (user == 1) 
  {
    FILE *fp;
    int count = 0, f = 0;
    fp = fopen("seeker.csv", "a+");
    if (fp == NULL) 
    {
      printf("\nError opening the file\n");
    } 
    else 
    {
      printf("\n\n----------------Enter Seeker details-------------------\n\n");
      printf("\nEnter your name : ");
      fflush(stdin);
      scanf(" %29[^\n]", s1[seeker_count].name);

      printf("Enter a valid password : ");
      fflush(stdin);
      scanf(" %19[^\n]", s1[seeker_count].pwd);

      printf("Enter phone number : ");
      fflush(stdin);
      scanf(" %9[^\n]", s1[seeker_count].pno);

      printf("Enter email ID : ");
      fflush(stdin);
      scanf(" %29[^\n]", s1[seeker_count].email);

      printf("Enter date of birth in dd/mm/yyyy format : ");
      fflush(stdin);
      scanf(" %9[^\n]", s1[seeker_count].dob);

      printf("Enter 10th mark : ");
      fflush(stdin);
      scanf("%f", &s1[seeker_count].tenth);

      printf("Enter 12th mark : ");
      fflush(stdin);
      scanf("%f", &s1[seeker_count].twelfth);

      printf("Enter UG course name : ");
      fflush(stdin);
      scanf(" %9[^\n]", s1[seeker_count].UG);

      printf("Enter CGPA : ");
      fflush(stdin);
      scanf("%f", &s1[seeker_count].CGPA);

      printf("Enter number of years of work experience : ");
      fflush(stdin);
      scanf("%d", &s1[seeker_count].Exp);

      printf("Enter preferred location 1 : ");
      fflush(stdin);
      scanf(" %19[^\n]", s1[seeker_count].location1);

      printf("Enter preferred location 2 : ");
      fflush(stdin);
      scanf(" %19[^\n]", s1[seeker_count].location2);

      printf("Enter preferred shift:\n1. Day\n2. Night\n");
      fflush(stdin);
      scanf("%d", &s1[seeker_count].shift);

      printf("Enter expected salary : ");
      fflush(stdin);
      scanf("%ld", &s1[seeker_count].expected_salary);

      float score = (s1[seeker_count].tenth * 1 / 10) + (s1[seeker_count].twelfth * 1 / 10) + (s1[seeker_count].CGPA * 1);
      char course_arr[4][10] = {"EEE", "ECE", "IT", "CSE"};
      for (int j = 0; j < 4; j++) 
      {
        if (strcmp(s1[seeker_count].UG, course_arr[j]) == 0) 
        {
          score += (float)(j + 7);
          f = 1;
          break;
        }
      }
      if (f == 0) 
      {
        score += (float)(6);
      }
      s1[seeker_count].score = score / 4;
      fprintf(fp, "%s,%s,%s,%s,%s,%.2f,%.2f,%s,%.2f,%d,%s,%s,%d,%ld,%.2f\n",
              s1[seeker_count].name, s1[seeker_count].pwd, s1[seeker_count].pno,
              s1[seeker_count].email, s1[seeker_count].dob,
              s1[seeker_count].tenth, s1[seeker_count].twelfth,
              s1[seeker_count].UG, s1[seeker_count].CGPA, s1[seeker_count].Exp,
              s1[seeker_count].location1, s1[seeker_count].location2,
              s1[seeker_count].shift, s1[seeker_count].expected_salary,
              s1[seeker_count].score);
    }
    fclose(fp);
  }

  else if (user == 2) 
  {
    FILE *fp;
    int num = 0;
    fp = fopen("employer.csv", "a+");
    if (fp == NULL) 
    {
      printf("Error opening the file : ");
    } 
    else 
    {
      printf("\n\n-------------------Enter employer details---------------------\n\n");
      printf("Enter company name : ");
      fflush(stdin);
      scanf(" %19[^\n]", e[0].cmp_name);

      printf("Enter company password : ");
      fflush(stdin);
      scanf("%19[^\n]", e[0].cmp_pwd);

      printf("Enter type of company :\n1) Start up\n2) Private Company\n3) MNC\n");
      fflush(stdin);
      scanf("%d", &e[0].cmp_type);

      printf("Enter minimum tenth mark required : ");
      fflush(stdin);
      scanf("%f", &e[0].min_tenth);

      printf("Enter minimum twelfth mark required : ");
      fflush(stdin);
      scanf("%f", &e[0].min_twelfth);

      printf("Enter work experience requirement : ");
      fflush(stdin);
      scanf("%d", &e[0].work_exp);

      printf("\nEnter the academic overall score requirement for the job (out of 10) : ");
      fflush(stdin);
      scanf("%f", &e[0].score_requirement);

      printf("Enter the minimum salary offered : ");
      fflush(stdin);
      scanf("%ld", &e[0].off_salary);

      printf("Enter number of locations with vacancies : ");
      fflush(stdin);
      scanf("%d", &num);

      for (int i = 0; i < num; i++) 
      {
        printf("\nEnter location %d : ", i + 1);
        fflush(stdin);
        scanf(" %19[^\n]", e[0].location);

        printf("Enter number of day shift vacancies in the location : ");
        fflush(stdin);
        scanf("%d", &e[0].day_vac);

        printf("Enter number of night shift vacancies in the location : ");
        fflush(stdin);
        scanf("%d", &e[0].night_vac);

        fprintf(fp, "%s,%s,%d,%d,%ld,%s,%d,%d,%f,%f,%f\n", 
                e[0].cmp_name,e[0].cmp_pwd, e[0].cmp_type, e[0].work_exp, e[0].off_salary,
                e[0].location, e[0].day_vac, e[0].night_vac,
                e[0].score_requirement, e[0].min_tenth, e[0].min_twelfth);
      }
    }
    fclose(fp);
  }
}

void print_seeker_details(char user[20]) 
{
  for (int j = 0; j < seeker_count; j++) 
  {
    if (strcmp(user, s1[j].name) == 0) 
    {
      printf("\n\n======================================================\n                      %s                       \n======================================================\n\n",s1[j].name);
      printf("Phone Number             : %s\n", s1[j].pno);
      printf("Email                    : %s\n", s1[j].email);
      printf("Date of Birth            : %s\n", s1[j].dob);
      printf("Tenth                    : %f\n", s1[j].tenth);
      printf("Twelfth                  : %f\n", s1[j].twelfth);
      printf("UG                       : %s\n", s1[j].UG);
      printf("CGPA                     : %f\n", s1[j].CGPA);
      printf("Experience               : %d\n", s1[j].Exp);
      printf("Location Preference 1    : %s\n", s1[j].location1);
      printf("Location Preference 2    : %s\n", s1[j].location2);
      printf("Shift                    : %d\n", s1[j].shift);
      printf("Expected Salary          : %ld\n", s1[j].expected_salary);
      printf("Score                    : %f\n", s1[j].score);
    }
  }
}

void print_employer_details(char user[20]) 
{
  for (int j = 0; j < company_count; j++) 
  {
    if (strcmp(user, e1[j].cmp_name) == 0) 
    {
      printf("\n\n======================================================\n                 %s                      \n======================================================\n\n",e1[j].cmp_name);
      printf("Company Type                               : ");
      if (e1[j].cmp_type == 1) 
      {
        printf("Start Up Company\n");
      } 
      else if (e1[j].cmp_type == 2) 
      {
        printf("Private Company\n");
      } 
      else if (e1[j].cmp_type == 3) 
      {
        printf("Multi National Company\n");
      }
      printf("Minimum Tenth Score                        : %f\n",e1[j].min_tenth);
      printf("Minimum Twelfth Score                      : %f\n",e1[j].min_twelfth);
      printf("Work Experience                            : %d\n",e1[j].work_exp);
      printf("Location                                   : %s\n",e1[j].location);
      printf("Day Vacancies                              : %d\n",e1[j].day_vac);
      printf("Night Vacancies                            : %d\n",e1[j].night_vac);
      printf("Score Requirement                          : %f\n",e1[j].score_requirement);
      printf("Offered Salary                             : %ld\n",e1[j].off_salary);
    }
  }
}

void edit_details(char name[20], int user) 
{
  if (user == 1) 
  {
    int seeker = 0, edit = 0;
    for (int s = 0; s < seeker_count; s++) 
    {
      if (strcmp(s1[s].name, name) == 0) 
      {
        seeker = s;
        break;
      }
    }
    for (int i = 0; i < 5; i++) 
    {
      if (i == 0) 
      {
        printf("Do you want to edit your work experience (0/1) : ");
        scanf("%d", &edit);
        if (edit == 0) 
        {
          continue;
        } 
        else 
        {
          printf("Enter your new experience : ");
          scanf("%d", &s1[seeker].Exp);
        }
      } 
      else if (i == 1) 
      {
        printf("Do you want to edit your 1st location preference (0/1) : ");
        scanf("%d", &edit);
        if (edit == 0) 
        {
          continue;
        } 
        else 
        {
          printf("Enter your new 1st location preference : ");
          scanf("%s", s1[seeker].location1);
        }
      } 
      else if (i == 2) 
      {
        printf("Do you want to edit your 2nd location preference (0/1) : ");
        scanf("%d", &edit);
        if (edit == 0) 
        {
          continue;
        } 
        else {
          printf("Enter your new 2nd location preference : ");
          scanf("%s", s1[seeker].location2);
        }
      } 
      else if (i == 3) 
      {
        printf("Do you want to edit your preffered shift (0/1) : ");
        scanf("%d", &edit);
        if (edit == 0) 
        {
          continue;
        } 
        else 
        {
          printf("Enter your new preffered shift\n1) Day\n2) Night\nEnter choice : ");
          scanf("%d", &s1[seeker].shift);
        }
      } 
      else if (i == 4) 
      {
        printf("Do you want to edit your expected salary (0/1) : ");
        scanf("%d", &edit);
        if (edit == 0) 
        {
          continue;
        } 
        else 
        {
          printf("Enter your new expected salary : ");
          scanf("%ld", &s1[seeker].expected_salary);
        }
      }
    }
    print_seeker_details(name);
    FILE *fp;
    fp = fopen("seeker.csv", "w");
    if (fp == NULL) 
    {
      printf("\nError opening the file\n");
    } 
    else 
    {
      for (int i = 0; i < seeker_count; i++) 
      {
        fprintf(fp, "%s,%s,%s,%s,%s,%.2f,%.2f,%s,%.2f,%d,%s,%s,%d,%ld,%.2f\n",
                s1[i].name, s1[i].pwd, s1[i].pno, s1[i].email, s1[i].dob,
                s1[i].tenth, s1[i].twelfth, s1[i].UG, s1[i].CGPA, s1[i].Exp,
                s1[i].location1, s1[i].location2, s1[i].shift,
                s1[i].expected_salary, s1[i].score);
        fflush(stdout);
      }
      fclose(fp);
    }
  }
}

void matching(char username[20], char password[20], int user) 
{
  if (user == 1) 
  {
    float percentage_match;
    float per[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int seeker_cmp_type = 0, seeker = 0, perf = 0, p1 = 0, p2 = 0, p3 = 0,p4 = 0;
    for (int m = 0; m < seeker_count; m++) 
    {
      if ((strcmp(username, s1[m].name) == 0) && (strcmp(password, s1[m].pwd) == 0)) 
      {
        seeker = m;
        break;
      }
    }
    printf("\n\nEnter the type of company you prefer :\n1) Start Up Company\n2) Private Company\n3) Multi National Company\nEnter choice : ");
    scanf("%d", &seeker_cmp_type);
    printf("\n\nConstraints\n1) Location\n2) Salary\n3) Shift\n4) Type\nEnter the priority order of constraints :\n\nPriority 1 : ");
    scanf("%d", &p1);
    printf("Priority 2 : ");
    scanf("%d", &p2);
    printf("Priority 3 : ");
    scanf("%d", &p3);
    printf("Priority 4 : ");
    scanf("%d", &p4);
    if (p1 == 1) 
    {
      for (int m = 0; m < company_count; m++) 
      {
        if (strcmp(s1[seeker].location1, e1[m].location) == 0) 
        {
          per[m] = per[m] + 15;
        } 
        else if (strcmp(s1[seeker].location2, e1[m].location) == 0) 
        {
          per[m] = per[m] + 12;
        } 
        else 
        {
          per[m] = per[m] + 10;
        }
      }
    } 
    else if (p1 == 2) 
    {
      for (int m = 0; m < company_count; m++) 
      {
        if (s1[seeker].expected_salary < e1[m].off_salary) 
        {
          per[m] = per[m] + 15;
        } 
        else if (s1[seeker].expected_salary == e1[m].off_salary) 
        {
          per[m] = per[m] + 12;
        } 
        else 
        {
          per[m] = per[m] + 10;
        }
      }
    } 
    else if (p1 == 3) 
    {
      if (s1[seeker].shift == 1) 
      {
        for (int m = 0; m < company_count; m++) 
        {
          if (e1[m].day_vac > 0) 
          {
            per[m] = per[m] + 15;
          } 
          else 
          {
            per[m] = per[m] + 10;
          }
        }
      } 
      else if (s1[seeker].shift == 2) 
      {
        for (int m = 0; m < company_count; m++) 
        {
          if (e1[m].night_vac > 0) 
          {
            per[m] = per[m] + 15;
          } 
          else 
          {
            per[m] = per[m] + 10;
          }
        }
      }
    } 
    else if (p1 == 4) 
    {
      for (int m = 0; m < company_count; m++) 
      {
        if (seeker_cmp_type == e1[m].cmp_type) 
        {
          per[m] = per[m] + 15;
        } 
        else 
        {
          per[m] = per[m] + 10;
        }
      }
    }

    if (p2 == 1) 
    {
      for (int m = 0; m < company_count; m++) 
      {
        if (strcmp(s1[seeker].location1, e1[m].location) == 0) 
        {
          per[m] = per[m] + 10;
        } 
        else if (strcmp(s1[seeker].location2, e1[m].location) == 0) 
        {
          per[m] = per[m] + 8;
        } 
        else 
        {
          per[m] = per[m] + 7;
        }
      }
    } 
    else if (p2 == 2) 
    {
      for (int m = 0; m < company_count; m++) 
      {
        if (s1[seeker].expected_salary < e1[m].off_salary) 
        {
          per[m] = per[m] + 10;
        } 
        else if (s1[seeker].expected_salary == e1[m].off_salary) 
        {
          per[m] = per[m] + 8;
        } 
        else 
        {
          per[m] = per[m] + 7;
        }
      }
    } 
    else if (p2 == 3) 
    {
      if (s1[seeker].shift == 1) 
      {
        for (int m = 0; m < company_count; m++) 
        {
          if (e1[m].day_vac > 0) 
          {
            per[m] = per[m] + 10;
          } 
          else 
          {
            per[m] = per[m] + 7;
          }
        }
      } 
      else if (s1[seeker].shift == 2) 
      {
        for (int m = 0; m < company_count; m++) 
        {
          if (e1[m].night_vac > 0) 
          {
            per[m] = per[m] + 10;
          } 
          else 
          {
            per[m] = per[m] + 7;
          }
        }
      }
    } 
    else if (p2 == 4) 
    {
      for (int m = 0; m < company_count; m++) 
      {
        if (seeker_cmp_type == e1[m].cmp_type) 
        {
          per[m] = per[m] + 10;
        } 
        else 
        {
          per[m] = per[m] + 7;
        }
      }
    }

    if (p3 == 1) 
    {
      for (int m = 0; m < company_count; m++) 
      {
        if (strcmp(s1[seeker].location1, e1[m].location) == 0) 
        {
          per[m] = per[m] + 7;
        } 
        else if (strcmp(s1[seeker].location2, e1[m].location) == 0) 
        {
          per[m] = per[m] + 6;
        } 
        else 
        {
          per[m] = per[m] + 5;
        }
      }
    } 
    else if (p3 == 2) 
    {
      for (int m = 0; m < company_count; m++) 
      {
        if (s1[seeker].expected_salary < e1[m].off_salary)
        {
          per[m] = per[m] + 7;
        } 
        else if (s1[seeker].expected_salary == e1[m].off_salary) 
        {
          per[m] = per[m] + 6;
        } 
        else 
        {
          per[m] = per[m] + 5;
        }
      }
    } 
    else if (p3 == 3) 
    {
      if (s1[seeker].shift == 1) 
      {
        for (int m = 0; m < company_count; m++) 
        {
          if (e1[m].day_vac > 0) 
          {
            per[m] = per[m] + 7;
          } 
          else 
          {
            per[m] = per[m] + 5;
          }
        }
      }
      else if (s1[seeker].shift == 2) 
      {
        for (int m = 0; m < company_count; m++) 
        {
          if (e1[m].night_vac > 0) 
          {
            per[m] = per[m] + 7;
          } 
          else 
          {
            per[m] = per[m] + 5;
          }
        }
      }
    } 
    else if (p3 == 4) 
    {
      for (int m = 0; m < company_count; m++) 
      {
        if (seeker_cmp_type == e1[m].cmp_type) 
        {
          per[m] = per[m] + 7;
        } 
        else 
        {
          per[m] = per[m] + 5;
        }
      }
    }

    if (p4 == 1) 
    {
      for (int m = 0; m < company_count; m++) 
      {
        if (strcmp(s1[seeker].location1, e1[m].location) == 0) 
        {
          per[m] = per[m] + 5;
        } 
        else if (strcmp(s1[seeker].location2, e1[m].location) == 0) 
        {
          per[m] = per[m] + 5;
        } 
        else 
        {
          per[m] = per[m] + 4;
        }
      }
    } 
    else if (p4 == 2) 
    {
      for (int m = 0; m < company_count; m++) 
      {
        if (s1[seeker].expected_salary < e1[m].off_salary) 
        {
          per[m] = per[m] + 5;
        } 
        else if (s1[seeker].expected_salary == e1[m].off_salary) 
        {
          per[m] = per[m] + 5;
        } 
        else 
        {
          per[m] = per[m] + 4;
        }
      }
    } 
    else if (p4 == 3) 
    {
      if (s1[seeker].shift == 1) 
      {
        for (int m = 0; m < company_count; m++) 
        {
          if (e1[m].day_vac > 0) 
          {
            per[m] = per[m] + 5;
          } 
          else 
          {
            per[m] = per[m] + 4;
          }
        }
      } 
      else if (s1[seeker].shift == 2) 
      {
        for (int m = 0; m < company_count; m++) 
        {
          if (e1[m].night_vac > 0) 
          {
            per[m] = per[m] + 5;
          } 
          else 
          {
            per[m] = per[m] + 4;
          }
        }
      }
    } 
    else if (p4 == 4) 
    {
      for (int m = 0; m < company_count; m++) 
      {
        if (seeker_cmp_type == e1[m].cmp_type) 
        {
          per[m] = per[m] + 5;
        } 
        else 
        {
          per[m] = per[m] + 4;
        }
      }
    }
    printf("\n");
    int count = 1, match[company_count], matchf = 0;
    for (int m = 0; m < company_count; m++) 
    {
      if (s1[seeker].score >= e1[m].score_requirement && s1[seeker].Exp >= e1[m].work_exp) 
      {
        printf("%d) Company name : %s\n  Location : %s\n  Offered Salary : %ld\n Percentage matched : %f\n\n",count, e1[m].cmp_name, e1[m].location, e1[m].off_salary,(per[m] / 37) * 100);
        match[matchf] = m;
        matchf++;
        count++;
      }
    }
    int job = 0;
    printf("Enter the choice among the following jobs : ");
    scanf("%d", &job);
    strcpy(s1[seeker].allocated_company, e1[match[job - 1]].cmp_name);
    strcpy(s1[seeker].allocated_location, e1[match[job - 1]].location);
    printf("Congratulations. Job has been allocated\n\nCompany name : %s\nLocation : %s\n",s1[seeker].allocated_company, s1[seeker].allocated_location);
    WritingToFile(seeker);
  }

  else if (user == 2) 
  {
    int employer = 0, count = 1;
    for (int e = 0; e < company_count; e++) 
    {
      if ((strcmp(e1[e].cmp_name, username) == 0) && (strcmp(e1[e].cmp_pwd, password) == 0)) 
      {
        employer = e;
        break;
      }
    }
    for (int s = 0; s < seeker_count; s++) 
    {
      if ((s1[s].score >= e1[employer].score_requirement) && (s1[s].tenth >= e1[employer].min_tenth) && (s1[s].twelfth >= e1[employer].min_twelfth) && (s1[s].Exp >= e1[employer].work_exp)) {
        printf("%d) Name : %s\n   Email ID : %s\n   Phone Number : %s\n   Score : %f\n   Preffered location : %s\n   Preffered shift : ",count, s1[s].name, s1[s].email, s1[s].pno, s1[s].score,s1[s].location1);
        if (s1[s].shift == 1) 
        {
          printf("Day\n\n");
        } 
        else if (s1[s].shift == 2) 
        {
          printf("Night\n\n");
        }
        count++;
      }
    }
    printf(" You can contact the Candidate using the above given Personal details ");
  }
}

struct seeker_data a[50];

void review(char username[20], char pwd[20]) 
{
  FILE *fp;
  fp = fopen("job.csv", "r");
  if (fp == NULL) 
  {
    printf("Error Opening the File");
    exit(1);
  } 
  else 
  {
    char line[200];
    while (fgets(line, sizeof(line), fp)) 
    {
      char *field = strtok(line, ",");
      int field_count = 0;
      while (field) 
      {
        if (field_count == 0) 
        {
          strncpy(a[seeker_count].name, field,sizeof(a[seeker_count].name) - 1);
          a[seeker_count].name[sizeof(a[seeker_count].name) - 1] = '\0';
        }
        if (field_count == 1) 
        {
          strncpy(a[seeker_count].pwd, field, sizeof(a[seeker_count].pwd) - 1);
          a[seeker_count].pwd[sizeof(a[seeker_count].pwd) - 1] = '\0';
        }
        if (field_count == 2) 
        {
          strncpy(a[seeker_count].pno, field, sizeof(a[seeker_count].pno) - 1);
          a[seeker_count].pno[sizeof(a[seeker_count].pno) - 1] = '\0';
        }
        if (field_count == 3) 
        {
          strncpy(a[seeker_count].email, field,sizeof(a[seeker_count].email) - 1);
          a[seeker_count].email[sizeof(a[seeker_count].email) - 1] = '\0';
        }
        if (field_count == 4) 
        {
          strncpy(a[seeker_count].dob, field, sizeof(a[seeker_count].dob) - 1);
          a[seeker_count].dob[sizeof(a[seeker_count].dob) - 1] = '\0';
        }
        if (field_count == 5) 
        {
          a[seeker_count].tenth = strtof(field, NULL);
        }
        if (field_count == 6) 
        {
          a[seeker_count].twelfth = atof(field);
        }
        if (field_count == 7) 
        {
          strncpy(a[seeker_count].UG, field, sizeof(a[seeker_count].UG) - 1);
          a[seeker_count].UG[sizeof(a[seeker_count].UG) - 1] = '\0';
        }
        if (field_count == 8) 
        {
          a[seeker_count].CGPA = atof(field);
        }
        if (field_count == 9) 
        {
          a[seeker_count].Exp = atoi(field);
        }
        if (field_count == 10) 
        {
          strncpy(a[seeker_count].location1, field,sizeof(a[seeker_count].location1) - 1);
          a[seeker_count].location1[sizeof(a[seeker_count].location1) - 1] ='\0';
        }
        if (field_count == 11) 
        {
          strncpy(a[seeker_count].location2, field,sizeof(a[seeker_count].location2) - 1);
          a[seeker_count].location2[sizeof(a[seeker_count].location2) - 1] ='\0';
        }
        if (field_count == 12) 
        {
          a[seeker_count].shift = atoi(field);
        }
        if (field_count == 13) 
        {
          a[seeker_count].expected_salary = strtol(field, NULL, 10);
        }
        if (field_count == 14) 
        {
          a[seeker_count].score = atof(field);
        }
        if (field_count == 15) 
        {
          strncpy(a[seeker_count].allocated_company, field,sizeof(a[seeker_count].allocated_company) - 1);
          a[seeker_count].allocated_company[sizeof(a[seeker_count].allocated_company) -1] = '\0';
        }
        if (field_count == 16) 
        {
          strncpy(a[seeker_count].allocated_location, field,sizeof(a[seeker_count].allocated_location) - 1);
          a[seeker_count].allocated_location[sizeof(a[seeker_count].allocated_location) - 1] = '\0';
        }
        if (field_count == 17) 
        {
          strncpy(a[seeker_count].status, field,sizeof(a[seeker_count].status) - 1);
          a[seeker_count].status[sizeof(a[seeker_count].status) - 1] = '\0';
        }
        field = strtok(NULL, ",");
        field_count++;
      }
      seeker_count++;
    }
    for (int i = 0; i < seeker_count; i++) 
    {
      if (strcmp(username, a[i].name) == 0 && strcmp(pwd, a[i].pwd) == 0) 
      {
        printf("Allocated Company               : %s\n", a[i].allocated_company);
        printf("Allocated Location              : %s\n",a[i].allocated_location);
        printf("Interview Status                : %s\n", a[i].status);
      }
    }
  }
}

void candidatedisplay(char username[20]) 
{
  FILE *fp;
  fp = fopen("job.csv", "r");
  if (fp == NULL) 
  {
    printf("Error Opening the File");
    exit(1);
  } 
  else 
  {
    char line[200];
    while (fgets(line, sizeof(line), fp)) 
    {
      char *field = strtok(line, ",");
      int field_count = 0;

      while (field) 
      {
        if (field_count == 0) 
        {
          strncpy(a[seeker_count].name, field,sizeof(a[seeker_count].name) - 1);
          a[seeker_count].name[sizeof(a[seeker_count].name) - 1] = '\0';
        }
        if (field_count == 1) 
        {
          strncpy(a[seeker_count].pwd, field, sizeof(a[seeker_count].pwd) - 1);
          a[seeker_count].pwd[sizeof(a[seeker_count].pwd) - 1] = '\0';
        }
        if (field_count == 2) 
        {
          strncpy(a[seeker_count].pno, field, sizeof(a[seeker_count].pno) - 1);
          a[seeker_count].pno[sizeof(a[seeker_count].pno) - 1] = '\0';
        }
        if (field_count == 3) 
        {
          strncpy(a[seeker_count].email, field,sizeof(a[seeker_count].email) - 1);
          a[seeker_count].email[sizeof(a[seeker_count].email) - 1] = '\0';
        }
        if (field_count == 4) 
        {
          strncpy(a[seeker_count].dob, field, sizeof(a[seeker_count].dob) - 1);
          a[seeker_count].dob[sizeof(a[seeker_count].dob) - 1] = '\0';
        }
        if (field_count == 5) 
        {
          a[seeker_count].tenth = strtof(field, NULL);
        }
        if (field_count == 6) 
        {
          a[seeker_count].twelfth = atof(field);
        }
        if (field_count == 7) 
        {
          strncpy(a[seeker_count].UG, field, sizeof(a[seeker_count].UG) - 1);
          a[seeker_count].UG[sizeof(a[seeker_count].UG) - 1] = '\0';
        }
        if (field_count == 8) 
        {
          a[seeker_count].CGPA = atof(field);
        }
        if (field_count == 9) 
        {
          a[seeker_count].Exp = atoi(field);
        }
        if (field_count == 10) 
        {
          strncpy(a[seeker_count].location1, field,sizeof(a[seeker_count].location1) - 1);
          a[seeker_count].location1[sizeof(a[seeker_count].location1) - 1] ='\0';
        }
        if (field_count == 11) 
        {
          strncpy(a[seeker_count].location2, field,sizeof(a[seeker_count].location2) - 1);
          a[seeker_count].location2[sizeof(a[seeker_count].location2) - 1] ='\0';
        }
        if (field_count == 12) 
        {
          a[seeker_count].shift = atoi(field);
        }
        if (field_count == 13) 
        {
          a[seeker_count].expected_salary = strtol(field, NULL, 10);
        }
        if (field_count == 14) 
        {
          a[seeker_count].score = atof(field);
        }
        if (field_count == 15) 
        {
          strncpy(a[seeker_count].allocated_company, field,sizeof(a[seeker_count].allocated_company) - 1);
          a[seeker_count].allocated_company[sizeof(a[seeker_count].allocated_company) -1] = '\0';
        }
        if (field_count == 16) {
          strncpy(a[seeker_count].allocated_location, field,sizeof(a[seeker_count].allocated_location) - 1);
          a[seeker_count].allocated_location[sizeof(a[seeker_count].allocated_location) -
                                  1] = '\0';
        }
        if (field_count == 17) 
        {
          strncpy(a[seeker_count].status, field,sizeof(a[seeker_count].status) - 1);
          a[seeker_count].status[sizeof(a[seeker_count].status) - 1] = '\0';
        }
        field = strtok(NULL, ",");
        field_count++;
      }
      seeker_count++;
    }
    for (int i = 0; i < seeker_count; i++) 
    {
      if (strcmp(username, a[i].allocated_company) == 0) 
      {
        printf("Name                            : %s\n", a[i].name);
        printf("Phone Number                    : %s\n", a[i].pno);
        printf("Email ID                        : %s\n", a[i].email);
        printf("Allocated Location              : %s\n", a[i].allocated_location);
        printf("Interview Status                : %s\n", a[i].status);
      }
    }
  }
}

int main() 
{
  int user, f = 0, i = 3, job = 0, c1 = 0,c2=0;
  char username[20], passwd[20];
  printf("\n\n---------------JOB SEEKING PLATFORM----------------\n\n");
  printf("Choose the relevant option\n1. Seeker\n2. Employer\n\nEnter choice : ");
  scanf("%d", &user);
  reading(1);
  reading(2);
  if (user == 1) 
  {
  login_seeker:
    i = 3;
    f = 0;
    while (f == 0 && i > 0) 
    {
      printf("\n\n------------------LOGIN PAGE------------------\n\nEnter your full name : ");
      scanf(" %19[^\n]", username);
      printf("Enter your password : ");
      scanf(" %19[^\n]", passwd);
      f = login(username, passwd, user);
      if (f == 0) 
      {
        printf("\nIncorrect username and password.\n%d attempts remaining\n",i - 1);
        i--;
      } 
      else 
      {
        printf("\n\nSuccessfully logged in\n\n");
        int choice = 0, y = 0;
        printf("Do you want to\n1) View your details\n2) Look for job\n3) Job Allocation Status\nEnter choice (1/2/3) : ");
        scanf("%d", &choice);
        if (choice == 1) 
        {
          print_seeker_details(username);
          printf("\n\n");
          printf("\n\nDo you want to edit your details (0/1) : ");
          scanf("%d", &y);
          if (y == 0) 
          {
            printf("\n\nDo you want to look for job (0/1) : ");
            scanf("%d",&c2);
            if (c2==0)
            {
              exit(1);
            }
            else if (c2==1)
            {
              goto look_for_job;
            }
          } 
          else if (y == 1) 
          {
            edit_details(username, user);
            printf("\n\nDo you want to look for job (0/1) : ");
            scanf("%d", &c1);
            if (c1 == 0)
            {
              exit(1);
            } 
            else 
            {
              goto look_for_job;
            }
          }
        } 
        else if (choice == 2) 
        {
        look_for_job:
          printf("\n\nLooking for a job\n\n");
          matching(username, passwd, user);
        } 
        else if (choice == 3) 
        {
          printf("\n\nJob Allocation Status\n\n");
          review(username, passwd);
        }
      }
    }

    if (f == 0) 
    {
      printf("\n\nNumber of attempts exceeded.\nRegister to continue\n");
      registration(user);
      seeker_count++;
      printf("\n\nLogin again\n\n");
      goto login_seeker;
    } 
    else if (f == 1) 
    {
      ;
    }
  } 
  else if (user == 2) 
  {
    int c2 = 0;
    login_cmp:
    i = 3;
    f = 0;
    while (f == 0 && i > 0) 
    {
      printf("\n\n------------------LOGIN PAGE------------------\n\nEnter company name : ");
      scanf(" %19[^\n]", username);
      printf("Enter your password : ");
      scanf(" %19[^\n]", passwd);
      f = login(username, passwd, user);
      if (f == 0) 
      {
        printf("\nIncorrect username and password.\n%d attempts remaining\n",i - 1);
        i--;
      } 
      else 
      {
        printf("\n\nSuccessfully logged in\n\n");
        int choice = 0, y = 0;
        printf("Do you want to\n1) View your company details\n2) Look for seekers\n3) View Allocated Candidates\nEnter choice (1/2/3) : ");
        scanf("%d", &choice);
        if (choice == 1) 
        {
          print_employer_details(username);
          printf("\n\n");
          printf("\n\nDo you want to look for applicants (0/1) :  ");
          scanf("%d", &y);
          if (y == 1) 
          {
            goto look_for_applicants;
          } 
          else if (y == 0) 
          {
            ;
          }
        } 
        else if (choice == 2) 
        {
          look_for_applicants:
          printf("\n\nLooking for applicants\n\n");
          matching(username, passwd, user);
        } 
        else if (choice == 3) 
        {
          printf("\n\nDisplaying Allocated Candidates\n\n");
          candidatedisplay(username);
        }
      }
    }

    if (f == 0) 
    {
      printf("\n\nNumber of attempts exceeded.\nRegister to continue\n");
      registration(user);
      company_count++;
      printf("\n\nLogin again\n\n");
      goto login_cmp;
    } 
    else if (f == 1) 
    {
      int choice = 0;
    }
  }
  return 0;
}