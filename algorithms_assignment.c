/*
A pharmaceutical company manufactures 3 lines of products from its factory in Dublin.  The production line is sophisticated and audited to the highest quality standards.  Each production line is staffed by a production team each consisting of a number of employees.  Each employee is certified to work on 1 or more lines and there are 4 production teams in total.

Working in the company's IT department, you have been given access to 4 separate lists detailing team membership and a separate list of certifications earned by each employee.
You have been asked to provide the following information :-

a)	combine the team lists  to produce a report of all employees in surname order
b)	a list of the employees certified to work on all 3 lines
c)	a routine to search for a specific worker by surname.

Your IT Department is determined to be as efficient as possible and has decided on the following standards for the project:-

1.	You should use the merge sort for sorting 
2.	Improve the efficiency of the merge sort by using another elementary sort to decrease the number of leaves in its execution tree.
3.	Explore any method to improve the execution of the elementary sort by using a searching algorithm you're familiar with.
4.	You should report on the time complexity of each algorithm you use in meeting requirements (a)-(c).
*/
#include <stdio.h>
#include <string.h>
#define NAME 30//Aray for both names and surnames
#define SIZE 6//Array for teams
#define ARRSIZE 24//Array for all people in the program 6*4

typedef struct teams
{
    char firstname[NAME];
    char surname[NAME];
    int first;//line 1
    int second;//line 2
    int third;//line 3

} teams;

void InsertionSort(char list[][100], int l, int t)
{
    int n = ARRSIZE;
    for (int i = l; i < n / 2; i++)
    {
        t = i;

        while (t > 0 && strcmp(list[t - 1], list[t]) > 0)
        {
            char tmp[n];
            strncpy(tmp, list[t - 1], sizeof(tmp) - 1);
            tmp[sizeof(tmp) - 1] = '\0';

            strncpy(list[t - 1], list[t], sizeof(list[t - 1]) - 1);
            list[t - 1][sizeof(list[t - 1]) - 1] = '\0';

            strncpy(list[t], tmp, sizeof(list[t]));
            list[t][sizeof(list[t]) - 1] = '\0';

            --t;
        }
    }
}
void mergesort(char a[][100], int low, int high)
{
    int n = ARRSIZE;
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        InsertionSort(a, low, mid);
        mergesort(a, mid + 1, high);
        InsertionSort(a, mid + 1, high);
        int i = low, j = mid + 1, k = low;
        char temp[n][100];
        while (i <= mid && j <= high)
        {
            if (strcmp(a[i], a[j]) < 0)
            {
                strcpy(temp[k], a[i]);
                k++;
                i++;
            }
            else
            {
                strcpy(temp[k], a[j]);
                k++;
                j++;
            }
        }
        while (i <= mid)
        {
            strcpy(temp[k], a[i]);
            k++;
            i++;
        }
        while (j <= high)
        {
            strcpy(temp[k], a[j]);
            k++;
            j++;
        }
        for (i = low; i <= high; i++)
            strcpy(a[i], temp[i]);
    }
}

int main()
{
    int i = 0;
    int j = 0;
    teams team1[SIZE] = {
        "Monroe", "Grace", 0, 0, 1,
        "Windsor", "Eve", 0, 1, 1,
        "Draper", "Era", 1, 0, 0,
        "Jones", "Kate", 0, 1, 0,
        "Hutton", "Noa", 1, 1, 1,
        "Parker", "Bee", 0, 1, 0};

    teams team2[SIZE] = {
        "Campell", "Greer", 1, 0, 0,
        "Miller", "Mae", 0, 0, 1,
        "Delaney", "Moore", 0, 0, 1,
        "Bennet", "Kelly", 0, 1, 0,
        "Allison", "Olivia", 1, 1, 0,
        "Blair", "Emma", 1, 1, 1};

    teams team3[SIZE] = {
        "Brook", "Ava", 0, 1, 0,
        "Cassidy", "Charlotte", 0, 1, 0,
        "Chanel", "Sophia", 1, 0, 0,
        "Courtney", "Amelia", 0, 0, 1,
        "Eden", "Isabella", 1, 1, 0,
        "Ellery", "Mia", 1, 0, 1};
    
    teams team4[SIZE] = {
        "Ellis", "Evelyn", 1, 1, 1,
        "Emerson", "Harper", 1, 0, 0,
        "Fallon", "Camila", 0, 1, 0,
        "Joyce", "Gianna", 0, 1, 0,
        "Kennedy", "Luna", 1, 1, 1,
        "Madison", "Emily", 0, 0, 1};
    
    struct teams teamcombine[ARRSIZE] =
        {};

    for (int i = 0; i < SIZE; i++, j++)
    {
        strcpy(teamcombine[j].firstname, team1[i].firstname);
        strcpy(teamcombine[j].surname, team1[i].surname);
        teamcombine[j].first = team1[i].first;
        teamcombine[j].second = team1[i].second;
        teamcombine[j].third = team1[i].third;
    }
    for (int i = 0; i < SIZE; i++, j++)
    {
        strcpy(teamcombine[j].firstname, team2[i].firstname);
        strcpy(teamcombine[j].surname, team2[i].surname);
        teamcombine[j].first = team2[i].first;
        teamcombine[j].second = team2[i].second;
        teamcombine[j].third = team2[i].third;
    }
    for (int i = 0; i < SIZE; i++, j++)
    {
        strcpy(teamcombine[j].firstname, team3[i].firstname);
        strcpy(teamcombine[j].surname, team3[i].surname);
        teamcombine[j].first = team3[i].first;
        teamcombine[j].second = team3[i].second;
        teamcombine[j].third = team3[i].third;
    }
    for (int i = 0; i < SIZE; i++, j++)
    {
        strcpy(teamcombine[j].firstname, team4[i].firstname);
        strcpy(teamcombine[j].surname, team4[i].surname);
        teamcombine[j].first = team4[i].first;
        teamcombine[j].second = team4[i].second;
        teamcombine[j].third = team4[i].third;
    }

    int menu;
    char combine_surnames[ARRSIZE][100];
    int exit = 0;
    int result = 0;
    char query[NAME];
    while (exit != 1)
    {
        printf("\nwelcome to the program\n1:Sort by surname and display data\n2:Certified to work on all 3 lines\n3:Search for a worker by their surname\n4:Exit\n");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:

            // combining the surnames into one list
            for (int i = 0; i < ARRSIZE; i++)
            {

                strcpy(combine_surnames[i], teamcombine[i].surname);
            }

            // end of combining surnames into one list

            mergesort(combine_surnames, 0, ARRSIZE - 1);

            int value = 1;
            for (int i = 0; i < ARRSIZE; i++)
            {
                for (int j = 0; j < ARRSIZE; j++)
                {

                    value = (strcmp(combine_surnames[i], teamcombine[j].surname));
                    if (value == 0)
                    {
                        printf("surname=%s,", teamcombine[j].surname);
                        printf("firstname=%s,", teamcombine[j].firstname);
                        printf("line1=%d,", teamcombine[j].first);
                        printf("line2=%d,", teamcombine[j].second);
                        printf("line3=%d\n", teamcombine[j].third);
                    }
                }
            }
            break;

        case 2:
            for (int i = 0; i < SIZE; i++)
            {
                // Team1
                if ((team1[i].first) && (team1[i].second) && (team1[i].third) == 1)
                {
                    printf("\n%s %s is certified to work on all 3 lines. \n", team1[i].firstname, team1[i].surname);
                }
                // Team2
                if ((team2[i].first) && (team2[i].second) && (team2[i].third) == 1)
                {
                    printf("\n%s %s is certified to work on all 3 lines. \n", team2[i].firstname, team2[i].surname);
                }
                // Team3
                if ((team3[i].first) && (team3[i].second) && (team3[i].third) == 1)
                {
                    printf("\n%s %s is certified to work on all 3 lines. \n", team3[i].firstname, team3[i].surname);
                }
                // Team4
                if ((team4[i].first) && (team4[i].second) && (team4[i].third) == 1)
                {
                    printf("\n%s %s is certified to work on all 3 lines. \n", team4[i].firstname, team4[i].surname);
                }
            }
            break;

        case 3:

            printf("Please enter a surname for query: ");
            scanf("%s", query);

            for (i = 0; i < ARRSIZE; i++)
            {
                result = strcmp(query, teamcombine[i].surname);
                if (result == 0)
                {
                    break;
                }
            }

            if (result == 0)
            {
                printf("\n\nWorker %s %s found! Line certifications are: Line 1:%d , Line2:%d , Line3:%d ", teamcombine[i].firstname, teamcombine[i].surname, teamcombine[i].first, teamcombine[i].second, teamcombine[i].third);
            }
            else
            {
                printf("Employee couldnt find.");
            }

            break;

        case 4:
            exit = 1;
            break;

        default:
            printf("Enter the number 1-4");
            break;
        }
    }

    return 0;
}
