// Features of Online Voting System in C
// The online voting system offers the following functions:

//- Taking a Vote from the User
//- Storing Different Votes
//- Calculating Votes
//- Declaring Results

#include <stdio.h>
#include <string.h>

// Define the structure
struct OVS
{
    char Cand_fName[30];
    char Cand_LName[30];
    char party_Name[5];
    int votes;
};

// Function to add candidates
void add_candidate(int n, struct OVS *p)
{
    printf("Filing Nomination \n\n");
    for (int i = 0; i < n; i++)
    {
        printf("Write Your First Name: ");
        scanf("%s", (p + i)->Cand_fName);
        printf("Write Your Last Name: ");
        scanf("%s", (p + i)->Cand_LName);
        printf("Write Party Name: ");
        scanf("%s", (p + i)->party_Name);
        (p + i)->votes = 0;
        printf("\n");
    }
    printf("----------------------------------------------\n");
}

// Function to allocate numbers to candidates
void allocate_Numbers(int n, struct OVS *p)
{
    printf("Allocated Party Number : \n\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s = %d\n", (p + i)->party_Name, i + 1);
    }
    printf("\n");
    printf("----------------------------------------------\n");
}

// Function for voting
void voting(int n, struct OVS *p)
{
    printf("Voting Started...\n");
    printf("Give Your Vote By Pressing Numbers 1 - %d\n\n", n);

    while (1)
    {
        int partyNumber;
        allocate_Numbers(n, p);
        printf("Enter Party Number (1 to %d): ", n);
        scanf("%d", &partyNumber);

        if (partyNumber == 0)
        {
            printf("\nEnd Voting.\n\n");
            break;
        }
        else if (partyNumber >= 1 && partyNumber <= n)
        {
            (p + partyNumber - 1)->votes++;
            printf("Vote for %s %s registered.\n\n", (p + partyNumber - 1)->Cand_fName, (p + partyNumber - 1)->Cand_LName);
        }
        else
        {
            printf("Invalid Entry! Please Enter a Number between 1 - %d\n", n);
        }
    }
}

void result(int n, struct OVS *p)
{
    printf("Voting Results:\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s %s from %s received %d votes.\n\n", (p + i)->Cand_fName, (p + i)->Cand_LName, (p + i)->party_Name, (p + i)->votes);
    }
}

int main()
{
    int n;
    printf("How Many Candidates Will File Nomination: ");
    scanf("%d", &n);
    printf("Enter '0' for ending the Vote \n");

    if (n > 100)
    {
        printf("Number of candidates exceeds the limit of 100.\n");
        return 1;
    }

    printf("\n");

    // Declare an array of OVS structures with a size limit
    struct OVS Candidates[100];

    add_candidate(n, Candidates);
    allocate_Numbers(n, Candidates);
    voting(n, Candidates);
    result(n, Candidates);

    return 0;
}