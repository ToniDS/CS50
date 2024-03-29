#include <cs50.h>
//#include <cstddef>
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
    {
        candidate this_candidate = candidates[i];
        //printf("%s\n", this_candidate.name);
        if (strcmp(name,this_candidate.name)== 0) 
        {
            candidates[i].votes ++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int max = 0;
    bool had_winner=false;
    string winning_candidate[candidate_count]; 
    for (int i = 0; i < candidate_count; i++)
    {
        candidate this_candidate = candidates[i];
        //printf("%s has %i votes. ", this_candidate.name, this_candidate.votes);
        if (this_candidate.votes > max)
        {
            max = this_candidate.votes;
            winning_candidate[0] = this_candidate.name;
            for (int j = 1; j < candidate_count; j++) {
                if (winning_candidate[j] != NULL)
                {
                    winning_candidate[j] = NULL;
                }
            }
        }
        else if (this_candidate.votes == max)
        {
            for (int j = 0; j < candidate_count; j++)
            {
                if (winning_candidate[j] == NULL)
                {
                    winning_candidate[j] = this_candidate.name;
                    break;
                }
            }

        }
    }
    
    for (int i = 0; i < candidate_count; i++)
    {
        if (winning_candidate[i] != NULL)
        {
            if (had_winner){
                printf("\n");
            }
            printf("%s", winning_candidate[i]);
            had_winner = true;
        }
    
    }
}

