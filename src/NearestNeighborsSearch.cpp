#include "include/NearestNeighborsSearch.hpp"

NearestNeighborsSearch::NearestNeighborsSearch(vector<pair<double, double>> points)
{
    this->points = points;
}

NearestNeighborsSearch::~NearestNeighborsSearch()
{
}

double NearestNeighborsSearch::getEuclideanDistance(const pair<double, double> xiYi, const pair<double, double> xjYj)
{
    double xd = xiYi.first - xjYj.first;
    double yd = xiYi.second - xjYj.second;
    return floor(sqrt(xd * xd + yd * yd));
}

double NearestNeighborsSearch::getPseudoEuclideanDistance(const pair<double, double> xiYi, const pair<double, double> xjYj)
{
    double xd = xiYi.first - xjYj.first;
    double yd = xiYi.second - xjYj.second;
    double rij = sqrt((xd * xd + yd * yd) / 10.0);
    double tij = floor(rij);

    if (tij < rij)
    {
        return tij + 1.0;
    }
    return tij;
}

double NearestNeighborsSearch::tsp(const string weightType)
{
    int n = this->points.size();

    bitset<64> visitedCities, allOnes;

    allOnes.set();

    for (int i = n; i < 64; i++)
        visitedCities[i] = 1;

    int s = rand() % n;

    visitedCities[s] = 1;

    int u = s;

    double ansNNTSP = 0;

    while ((visitedCities & allOnes) != allOnes)
    {
        int nxtV = -1, nxtDist = INF;

        for (int v = 0; v < n; v++)
        {
            if (!visitedCities[v])
            {
                double currDist = weightType == "EUC_2D" ? getEuclideanDistance(this->points[u], this->points[v]) : getPseudoEuclideanDistance(this->points[u], this->points[v]);

                if (currDist < nxtDist)
                {
                    nxtV = v;
                    nxtDist = currDist;
                }
            }
        }

        visitedCities[nxtV] = 1;
        ansNNTSP += nxtDist;
        u = nxtV;
    }

    return (ansNNTSP + (weightType == "EUC_2D" ? getEuclideanDistance(this->points[s], this->points[u]) : getPseudoEuclideanDistance(this->points[s], this->points[u]))) / 1000.0;
}