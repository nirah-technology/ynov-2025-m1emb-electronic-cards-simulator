#include <iostream>
#include <string>
#include <vector>

class Tree {
    private:
        int height_hitbox = 0;
        int width_hitbox = 0;
        std::string texture;
    public: 
        Tree(int height, int width, std::string texture) : height_hitbox(height), width_hitbox(width), texture(texture) { }
        void grow() {
            std::cout << "Je grandi !" << std::endl;
        }

        int height() {
            return this->height_hitbox;
        }

        int width() {
            return this->width_hitbox;
        }

        std::string getTexture() {
            return this->texture;
        }
};

class TreeLocation {
    private:
        Tree* tree;
        int x = 0;
        int y = 0;

    public:
        TreeLocation(Tree* tree, int x, int y) : tree(tree), x(x), y(y) { };

        Tree* getTree() {
            return this->tree;
        }
        int getX() {
            return this->x;
        }
        int getY() {
            return this->y;
        }
};

class Forest {
    private:
        std::vector<TreeLocation*> trees;
    public:
        Forest() : trees() { };
        void addTree(Tree* tree, int x, int y) {
            this->trees.push_back(new TreeLocation(tree, x, y));
        }

        void render() {
            for (TreeLocation* treeLocation : this->trees) {
                std::cout << treeLocation->getTree() << " at (" << treeLocation->getX() << "," << treeLocation->getY() << ")"  << std::endl;
            }
        }
};