#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int at[100], bt[100], tat[100], wt[100];
    int completed[100];
    int gantt[100];
    int time_mark[101];

    for(int i=0;i<n;i++)
        completed[i] = 0;

    cout << "Enter Arrival Time and Burst Time\n";

    for(int i=0;i<n;i++)
    {
        cout << "P" << i+1 << ": ";
        cin >> at[i] >> bt[i];
    }

    int current_time = 0;
    int completed_count = 0;
    int k = 0;

    time_mark[0] = 0;

    while(completed_count < n)
    {
        int idx = -1;
        int min_bt = 9999;

        for(int i=0;i<n;i++)
        {
            if(at[i] <= current_time && completed[i] == 0)
            {
                if(bt[i] < min_bt)
                {
                    min_bt = bt[i];
                    idx = i;
                }
            }
        }

        if(idx != -1)
        {
            current_time += bt[idx];

            tat[idx] = current_time - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            completed[idx] = 1;

            gantt[k] = idx;
            time_mark[k+1] = current_time;

            k++;
            completed_count++;
        }
        else
        {
            current_time++;
        }
    }

    float avgWT = 0, avgTAT = 0;

    cout << "\n";
    cout << left << setw(10) << "Process"
         << setw(10) << "AT"
         << setw(10) << "BT"
         << setw(10) << "WT"
         << setw(10) << "TAT" << endl;

    for(int i=0;i<n;i++)
    {
        cout << left << setw(10) << ("P"+to_string(i+1))
             << setw(10) << at[i]
             << setw(10) << bt[i]
             << setw(10) << wt[i]
             << setw(10) << tat[i] << endl;

        avgWT += wt[i];
        avgTAT += tat[i];
    }

    cout << "\nAverage WT = " << avgWT/n;
    cout << "\nAverage TAT = " << avgTAT/n;

    cout << "\n\nGantt Chart:\n";

    for(int i=0;i<k;i++)
        cout << "| P" << gantt[i]+1 << " ";

    cout << "|\n";

    for(int i=0;i<=k;i++)
        cout << time_mark[i] << " ";

    cout << endl;

    return 0;
}
