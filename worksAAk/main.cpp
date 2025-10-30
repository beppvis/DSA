#include <cstddef>
#include <iostream>

using namespace std;

enum RideType{
    Thrill,
    Chill
};

struct Visitor
{
    int visitorID;
    string visitorName;
    enum RideType rideType;
    struct Visitor* nextVisitor;
    struct Visitor* prevVisitor;
};

class CarnivalWheel
{
    struct Visitor* head;
    public:
        CarnivalWheel()
        {
            head = NULL;
        }

        void addVisitor(int visitorID, string visitorName, enum RideType rideType)
        {
            struct Visitor* visitorToAdd = (struct Visitor*)malloc(sizeof(struct Visitor));
            visitorToAdd->visitorID = visitorID;
            visitorToAdd->visitorName = visitorName;
            visitorToAdd->rideType = rideType;

            if(head == NULL)
            {
                head = visitorToAdd;
                head->nextVisitor = visitorToAdd;
                head->prevVisitor = visitorToAdd;
                return;
            }

            struct Visitor* tptr = head->prevVisitor;
            visitorToAdd->prevVisitor = tptr;
            head->prevVisitor = visitorToAdd;
            tptr->nextVisitor = visitorToAdd;
            visitorToAdd->nextVisitor = head;
        }

        void printWheel()
        {
            struct Visitor* ptr = head;

            if(head == NULL)
            {
                cout << "Wheel is empty" << endl;
                return;
            }

            do
            {
                cout << ptr->visitorID << " <==> ";
                ptr = ptr->nextVisitor;
            }while(ptr != head);

        }
};      


int main()
{
    CarnivalWheel carnivalWheel;
    carnivalWheel.addVisitor(101, "Raman", Thrill);
    carnivalWheel.addVisitor(102, "Raman", Thrill);
    carnivalWheel.addVisitor(103, "Raman", Thrill);
    carnivalWheel.printWheel();


    
}
