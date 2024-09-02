#ifndef TREE
#define TREE

#include <map>
#include <string>
#include <vector>

struct Node 
{
    std::map<std::string, Node> children;
};

class Tree 
{
private:
    Node root;

public:
    bool Has(const std::vector<std::string>& node) const;

    void Insert(const std::vector<std::string>& node);

    void Delete(const std::vector<std::string>& node);
};

bool Tree::Has(const std::vector<std::string>& node) const
{
    const Node* curr_node = &root;
    for (const std::string &s: node)
    {
        if ((curr_node->children).find(s) != (curr_node->children).end())
        {
            curr_node = &((curr_node->children).at(s));
        }
        else
        {
            return false;
        }
    }
    return true;
}

void Tree::Insert(const std::vector<std::string>& node) 
{
    Node* curr_node = &root;
    for (const std::string &s: node)
    {
        if ((curr_node->children).find(s) != (curr_node->children).end())
        {
            curr_node = &((curr_node->children).at(s));
        }
        else
        {
            (curr_node->children)[s];
            curr_node = &((curr_node->children).at(s));
        }
    }
}

void Tree::Delete(const std::vector<std::string>& node)
{

    Node* curr_node = &root;
    int n = node.size();
    for (int i = 0; i < n; ++i)
    {

        const std::string& s = node[i];
        if ((curr_node->children).find(s) == (curr_node->children).end())
        {
            return;
        }
        else
        {

            if (i == n - 1)
            {
                (curr_node->children).erase(s);
                return;
            }
            else
            {
                curr_node = &((curr_node->children).at(s));
            }
        }
    }
}


#endif
