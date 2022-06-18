#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26] = {NULL};
    bool flag=0; //to mark end of a word
    bool Contains_key(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    void Put(char ch,Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *Get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = 1;
    }
};

class Trie
{
public :
    Node *root = NULL;
    Trie()
    {
        root = new Node;
    }

    void Insert(string word)
    {
        Node *node = root;
        for(int i=0;i<word.length();i++)
        {
            if( !node->Contains_key(word[i]) )
                node->Put(word[i],new Node);
            node = node->Get(word[i]);
        }

        node->setEnd();
    }

    bool Search(string word)
    {
        Node *node = root;

        for(int i=0;i<word.length();i++)
        {
            if(!node->Contains_key(word[i]))
                return 0;
            node = node->Get(word[i]);
        }
        return node->flag;
    }

    bool starts_with(string word)
    {
        Node *node = root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->Contains_key(word[i]))
                return 0;
            node = node->Get(word[i]);
        }
        return 1;
    }
};
int main()
{
    //GO_FAST

    Trie t;

    t.Insert("saksham");
    t.Insert("saks");
    t.Insert("sakshams");
    cout<<t.Search("saksham")<<"\n";
    cout<<t.starts_with("s")<<"\n";
    cout<<t.starts_with("a")<<"\n";
    return 0;
}
