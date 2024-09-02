#include <iostream>
#include "Tree.h"

void Test(Tree t, const std::vector<std::string>& node, bool result, int number)
{
    if (t.Has(node) == result)
    {
        std::cout << "test " << number << " passed!" << std::endl;
    }
    else
    {
        std::cout << "test " << number << " failed!" << std::endl;
    }
}

int main()
{
    const std::vector<std::string>& node = {"q", "qw", "qwe", "qwer", "qwert", "qwerty", "qwerty1", "qwerty12"};
    Tree t;
    t.Insert(node);
    const std::vector<std::string>& node1 = {"q"};
    Test(t, node1, true, 1);
    const std::vector<std::string>& node2 = {"q", "qw"};
    Test(t, node2, true, 2);
    const std::vector<std::string>& node3 = {"q", "qw", "qwe"};
    Test(t, node3, true, 3);
    const std::vector<std::string>& node4 = {"q", "qw", "qwe", "qwee"};
    Test(t, node4, false, 4);
    const std::vector<std::string>& node5 = {"q", "qw", "qwe"};
    t.Delete(node5);
    Test(t, node1, true, 5);
    Test(t, node2, true, 6);
    Test(t, node3, false, 7);
}
