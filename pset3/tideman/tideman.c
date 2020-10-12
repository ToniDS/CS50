#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i ++)
    {
        if (strcmp(name, candidates[i]) == 0){
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count -1; i ++)
    {
        if (preferences[ranks[i]][ranks[i+1]] == 0)
        {
            preferences[ranks[i]][ranks[i+1]] = 1;
        } else {
            preferences[ranks[i]][ranks[i+1]] ++;
        }
    }    
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    pair new_pair;
    for (int i = 0; i < candidate_count; i ++)
    {
        for (int j = 0; i < candidate_count; i++)
        {
                new_pair.winner = i;
                new_pair.loser = j;
                pairs[pair_count - 1] = new_pair;
                pair_count ++;
        }
    }
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // trying bubble sort
    int first_winner;
    int first_loser;
    int first_difference;
    int second_winner;
    int second_loser;
    int second_difference;
    int swapped = -1;  
    pair first_pair;
    pair second_pair;
    while (swapped != 0){
        swapped = 0;
        for (int i = 0; i < pair_count -1; i++) {
            first_winner = pairs[i].winner;
            first_loser = pairs[i].loser;
            first_difference = preferences[first_winner][first_loser];
            second_winner = pairs[i+1].winner;
            second_loser = pairs[i+1].loser;
            second_difference = preferences[second_winner][second_loser];
            
            if (first_difference < second_difference)
            {
                first_pair = pairs[i];
                second_pair = pairs[i+1];
                pairs[i] = second_pair;
                pairs[i+1] = first_pair;
                swapped ++;
            }

        }
        for (int i = 0; i < pair_count; i++){
            printf("%i - %i: %i\n", pairs[i].winner, pairs[i].loser,
            preferences[pairs[i].winner][pairs[i].loser]);
        }
    }  
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}

