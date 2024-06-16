#include "Edge.hpp"
#include "Player.hpp"

Edge::Edge() {
    // Initialize attributes if needed
}

const std::vector<Vertex*>& Edge::getConnectedVertices() const {
    return connectedVertices;
}

int Edge::calculateLongestRoad() const {
    // Logic to calculate the longest road starting from this edge
    // Implement your algorithm here

    // Example:
    // Perform DFS or BFS to find the longest path starting from this edge
    // Traverse through connected vertices and recursively calculate road lengths

    // This is a placeholder to demonstrate the concept
    int maxLength = 0;
    // Example DFS traversal
    for (Vertex* vertex : connectedVertices) {
        // Implement DFS logic or any traversal method to find the longest path
        // Example: Simple traversal
        maxLength = std::max(maxLength, 1 + vertex->calculateLongestRoad());
    }
    return maxLength;
}
