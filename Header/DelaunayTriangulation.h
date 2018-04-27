#ifndef DELAUNAYTRIANGULATION_H
#define DELAUNAYTRIANGULATION_H

#include "Triangle.h"

using namespace std;

class DelaunayTriangulation
{
private:
    vector<Vector3D*>* _ProjectedDots;
    vector<Triangle*>* _Mesh;
    int _Statistics[2]; // 0: triangle search operations; 1: local optimizations;

    void BuildInitialHull(vector<Vector3D*>*);
    void InsertDot(Vector3D*);
    void RemoveExtraTriangles();
    void SplitTriangle(Vector3D*, Triangle*);
    void FixNeighborhood(Triangle*, Triangle*, Triangle*);
    void DoLocalOptimization(Triangle*, Triangle*);
    bool TrySwapDiagonal(Triangle*, Triangle*);
    bool IsMinimumValueInArray(double[], int, int);
    double GetDistance(Vector3D*, Vector3D*);
    double GetDeterminant(Vector3D*, Vector3D*, Vector3D*);
    double GetDeterminant(double[]);

public:
    DelaunayTriangulation();
    ~DelaunayTriangulation();

    vector<tuple<int, int, int>*> GetTriangulationResult(vector<Vector3D*>&);
    string GetStatistics();
};

#endif