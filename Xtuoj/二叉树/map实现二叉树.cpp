#include <iostream>
#include <map>

int main()
{
    std::map<int, std::string> tree;
    tree[4] = "four";
    tree[2] = "two";
    tree[5] = "five";
    tree[1] = "one";
    tree[3] = "three";

    std::cout << "Inorder traversal of the binary tree:\n";
    for (auto it = tree.begin(); it != tree.end(); ++it)
    {
        std::cout << it->first << ": " << it->second << '\n';
    }

    return 0;
}