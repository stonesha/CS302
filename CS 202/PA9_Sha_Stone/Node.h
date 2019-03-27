#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        Node();
        virtual ~Node();
        Node(const Node& other);
        Node& operator=(const Node& other);

    protected:

    private:
};

#endif // NODE_H
