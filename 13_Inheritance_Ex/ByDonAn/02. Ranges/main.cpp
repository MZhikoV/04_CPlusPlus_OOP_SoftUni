#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <functional>
#include <memory>

using namespace std;


class Range
    {
        int from, to;

    public:
        Range(istream &istr) { istr >> *this; }

        int getFrom() const
        {
            return from;
        };

        int getTo() const
        {
            return to;
        };

        friend istream &operator>>(istream &istr, Range &range);
    };

    // friend
    istream &operator>>(istream &istr, Range &range)
    {
        istr >> range.from >> range.to;
        return istr;
    };

    class Data
    {

    protected:
        map<int, shared_ptr<Range>> data;

    public:
        void addRange(shared_ptr<Range> r)
        {
            data[r->getFrom()] = r;
        };
    };

    class Processor : public Data
    {

    public:
        void go(function<void(istream &)> doer)
        {

            while (true)
            {
                string buffer;
                getline(cin,buffer);
                if (buffer == ".")
                {
                    break;
                };
                istringstream istr(buffer);
                doer(istr);
            }
        }
    };

class isInRangeProcessor: public Processor {

        public:
            bool isInRange(int i) {
                auto itStart = data.upper_bound(i);

                if (itStart==data.begin()) {
                    return false;
                }
                else {
                    itStart--;
                    return i<=itStart->second->getTo();
                }
            }
};

int main()
{
    isInRangeProcessor proc;

    proc.go( [&](istream & istr) {
        proc.addRange(make_shared<Range>(istr));
    }
    );

    proc.go( [&](istream & istr) {
        int i;
        istr>>i;

        cout<<(proc.isInRange(i) ? "in":"out")<<endl;        
    }
    );

 //   system("pause");
    return 0;
}