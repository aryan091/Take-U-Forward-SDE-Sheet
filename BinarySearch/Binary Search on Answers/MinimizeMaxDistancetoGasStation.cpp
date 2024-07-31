#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool gasStationRequired(vector<int> &stations, int K, long double distance)
{
    int n = stations.size();
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        count += (int)((stations[i] - stations[i - 1]) / distance);
    }
    return count <= K;
}

double findSmallestMaxDistOptimal(vector<int> &stations, int K)
{
    double delta = 1e-6;
    double ans = -1.0;
    double low = 0, high = 1e8;
    while (high - low > delta)
    {
        double mid = (low + high) / 2;
        if (gasStationRequired(stations, K, mid))
        {
            ans = mid;
            high = mid;
        }
        else
            low = mid;
    }
    return ans + 0.000001;
}

double findSmallestMaxDistBF(vector<int> &stations, int K)
{
    int n = stations.size();

    vector<int> howManyGasStationPlaces(n - 1, 0);

    for (int gasStation = 1; gasStation <= K; gasStation++)
    {
        long double maxSection = -1;
        int maxInd = -1;

        for (int i = 0; i < n - 1; i++)
        {
            long double diff = stations[i + 1] - stations[i];
            long double sectionLength =
                diff / (long double)(howManyGasStationPlaces[i] + 1);

            if (sectionLength > maxSection)
            {
                maxSection = sectionLength;
                maxInd = i;
            }
        }
        howManyGasStationPlaces[maxInd]++;
    }

    long double maxAns = -1;
    for (int i = 0; i < n - 1; i++)
    {
        long double diff = stations[i + 1] - stations[i];
        long double sectionLength = diff / (long double)(howManyGasStationPlaces[i] + 1);
        maxAns = max(maxAns, sectionLength);
    }

    return maxAns;

    // TC - O(K * N) + O(N)
    // SC - O( N - 1 )
}

double findSmallestMaxDistBetter(vector<int> &stations, int K)
{
    // Code here

    int n = stations.size();

    vector<int> howManyGasStationPlaces(n - 1, 0);
    priority_queue<pair<long double, int>> pq;

    for (int i = 0; i < n - 1; i++)
    {
        pq.push({(long double)(stations[i + 1] - stations[i]), i});
    }

    for (int gasStation = 1; gasStation <= K; gasStation++)
    {
        auto tp = pq.top();
        pq.pop();
        int secInd = tp.second;
        howManyGasStationPlaces[secInd]++;

        long double iniDiff = stations[secInd + 1] - stations[secInd];
        long double newSectionlength = iniDiff / (long double)(howManyGasStationPlaces[secInd] + 1);

        pq.push({newSectionlength, secInd});
    }

    return pq.top().first;

    // TC - O(NlogN + KlogN)
    // Insert operation of priority queue takes logN time complexity.

    // SC - O(N-1)+O(N-1)
    // Vector & PQ
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ansBF = findSmallestMaxDistBF(arr, k);
    cout << ansBF << " ";

    long double ansBetter = findSmallestMaxDistBetter(arr, k);
    cout << ansBetter << " ";

    long double ansOptimal = findSmallestMaxDistOptimal(arr, k);
    cout << ansOptimal << " ";

    return 0;
}