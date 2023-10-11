
class Sentinel{

    public:

    struct node{
        int data;
        struct node* next;
        struct node* prev;
    };

    virtual void menuz(std::string name) = 0;
    virtual void addHead(int num) = 0;
    virtual void addTail(int num) = 0;
    virtual void print() = 0;
    virtual int removeAt(int pos) = 0;
    virtual int removeNum(int num) = 0;
};