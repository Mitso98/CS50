/*
    this program takes maximum 9 names
    then asks you abut the numbers of voters
    then ask u nth times to write the name u wanna vote to
    and decides who is the winner if tie shows the most voted names
*/
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {   if (strncmp(candidates[i].name, name, 20) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // could have made just a varibale but it's 
    //possible to have moore than one winner
    typedef struct
    {
        string name;
        int votes;
    }
    winner;
    winner winners[candidate_count];
    int j = 0;
    int length = 0;
    // linear search for the winner/winners
    for (int i = 0; i < candidate_count; i++)
    {
        if (i == 0)
        {
            winners[i].name = candidates[i].name;
            winners[i].votes = candidates[i].votes;
        }
        else if (candidates[i].votes > winners[j].votes)
        {
            j = 0;
            length = 0;
            winners[j].name = candidates[i].name;
            winners[j].votes = candidates[i].votes;
        } 
        else if (candidates[i].votes == winners[j].votes)
        {
            length++;
            j++;
            winners[j].name = candidates[i].name;
            winners[j].votes = candidates[i].votes;
        }
    }
    // if multiple winners
    if (length > 0)
    {
        for (int i = 0; i <= length; i++)
        {
            printf("%s\n", winners[i].name);
        }
    }
    // if only one winner
    else
    {
        printf("%s\n", winners[0].name);
    }    
}
