#ifndef TREE_H // Header guard to avoid multiple inclusions
#define TREE_H

#include <GL/glut.h>

class Tree {
private:
    float posX, posY, posZ;   // Position of the tree

public:
    // Constructor
    Tree(float x, float y, float z);

    // Method to draw the fan
    void draw();

private:

    };

#endif // TREE_H
