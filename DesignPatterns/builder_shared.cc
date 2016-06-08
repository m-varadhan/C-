#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Popup
{
public:
    Popup(int value, string str){
        this->v = value;
        this->str = str;
    }
    virtual void print() = 0;
    int v;
    string str;
};
typedef shared_ptr<Popup> PopupPtr;

class PopupA : public Popup
{
public:
    PopupA(int v, string str) : Popup(v, str) { }
    virtual void print() {
        cout << "PopupA" << endl;
    }
};
typedef shared_ptr<PopupA> PopupAPtr;

class PopupB : public Popup
{
public:
    PopupB(int v, string str) : Popup(v, str) { }
    virtual void print() {
        cout << "PopupB" << endl;
    }
};
typedef shared_ptr<PopupB> PopupBPtr;


class Builder : public enable_shared_from_this<Builder>
{
public:
    PopupPtr popupPtr;
    Builder() { };
    shared_ptr<Builder> init(int value, string str) {
        shared_ptr<Builder> builder;
	popupPtr = nullptr ;

        switch (value)
        {
        case 1:
            popupPtr = PopupAPtr(new PopupA(value, str));
            break;
        case 2:
            popupPtr = PopupBPtr(new PopupB(value, str));
            break;
        default:
            cout << "default error" << endl;
            break;
        }

        if (popupPtr) {
            builder = shared_from_this();
        } 
        else {
            cout << "popup is null" << endl;
        }

        if (!builder) {
            cout << "builder is null" << endl;
        }
        return builder;
    }

    PopupPtr build()
    {
        if (!popupPtr) {
            cout << "popup is null" << endl;
        }
        return PopupPtr(popupPtr);
    }

};
typedef shared_ptr<Builder> BuilderPtr;

int main()
{
    BuilderPtr builderPtr = BuilderPtr(new Builder());

    PopupPtr popupPtr1 = builderPtr->init(1, "111111111111")->build();
    popupPtr1->print();

    PopupPtr popupPtr2 = builderPtr->init(2, "222222222222")->build();
    popupPtr2->print();
    return 0;
}
