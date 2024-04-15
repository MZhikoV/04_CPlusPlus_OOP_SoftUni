#ifndef nodee_h
#define nodee_h

class Node {
    int from;
    int to;

    public:
    Node (const int& from, const int& to) : from(from), to(to) {};

    int getFrom() const {
        return  from;
    };

    int getTo() const {
        return to;
    };
};



#endif