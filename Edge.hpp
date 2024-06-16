#ifndef EDGE_H
#define EDGE_H

#include <vector>
#include "Vertex.hpp" // Assuming Vertex class is defined

class Edge {
private:
    std::vector<Vertex*> connectedVertices;
    // Other attributes as needed

public:
    Edge(); // Constructor if needed

    const std::vector<Vertex*>& getConnectedVertices() const;
    // Other getter/setter methods as needed

    // Method to calculate the longest road starting from this edge
    int calculateLongestRoad() const;
};

#endif // EDGE_H
