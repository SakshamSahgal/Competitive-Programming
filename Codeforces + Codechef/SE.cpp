#include<bits/stdc++.h>
#include <unordered_set>

using namespace std;

const int MAX_VOTERS = 100;
const int MAX_CANDIDATES = 10;

class Voter
{
private:
    string fingerprint;
public:

    string generateHash(int fingerprintInput)
    {
        string hashedFingerprint = "ce1892a895688066dd4be58" + to_string((fingerprintInput*5)%3) + "f1340bb5e";
        return hashedFingerprint;
    }

    void setFingerprint(int fp)
    {
        fingerprint = generateHash(fp);
    }

    string getFingerprint()
    {
        return fingerprint;
    }

};

class Admin
{
public:
    bool isValidCandidate(int candidate, int num_candidates)
    {
        return candidate >= 1 && candidate <= num_candidates;
    }
    bool isValidNumVoters(int numVoters)
    {
        return (numVoters >= 1 && numVoters <= MAX_VOTERS);
    }
    bool isValidNumCandidates(int numCandidates)
    {
        return (numCandidates >= 1 && numCandidates <= MAX_CANDIDATES);
    }
};

class ElectionCommission
{
public:
    void recordVote(int candidate, int* candidates, Voter* voter)
    {
        candidates[candidate-1]++;
        voter->setFingerprint(-1); // Mark fingerprint as used
        cout << "Vote recorded." << endl;
    }
};



void validateInput(int &input,int Max,string msg,Admin admin) //function to validate the input recorded
{
    while(1)
    {
        cout <<msg;
        cin >> input;
        if(admin.isValidNumVoters(input))
            break;
        else
            cout<<"Enter the no between 1-"<<Max<<"\n";
    }
    return;
}


int main()
{
    int num_voters, num_candidates;
    int votes[MAX_VOTERS];
    int candidates[MAX_CANDIDATES] = {0};
    Admin admin;

    validateInput(num_voters,MAX_VOTERS,"Enter no of voters : ",admin);
    validateInput(num_candidates,MAX_CANDIDATES,"Enter no of Candidates : ",admin);


    ElectionCommission ec;

    unordered_set<int> fingerprints; // Store unique fingerprints

    for (int i = 0; i < num_voters; i++)
    {
        cout << "Enter the fingerprint of voter " << i+1 << ": ";
        int fingerprint;
        cin >> fingerprint;

        // Check if fingerprint has already voted
        if (fingerprints.count(fingerprint))
        {
            cout << "This fingerprint has already voted!" << endl;
            i--;
            continue;
        }
        else
        {
            Voter voter;
            voter.setFingerprint(fingerprint);

            cout << "Choose a candidate (1-" << num_candidates << ") to vote for: ";
            int candidate;
            cin >> candidate;

            // Check if candidate number is valid
            if (!admin.isValidCandidate(candidate, num_candidates))
            {
                cout << "Invalid candidate number!" << endl;
                i--;
                continue;
            }
            else
            {
                fingerprints.insert(fingerprint);
                ec.recordVote(candidate, candidates, &voter);
            }
        }
    }

// Print the results
    cout << "Results:" << endl;
    for (int i = 0; i < num_candidates; i++)
        cout << "Candidate " << i+1 << ": " << candidates[i] << " votes" << endl;



    return 0;
}
