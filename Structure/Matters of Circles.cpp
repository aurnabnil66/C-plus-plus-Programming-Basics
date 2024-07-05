#include<iostream>
#include<math.h>
using namespace std;
struct Volume
{
    double radius,radius1,radius2,volume,distance;
    int x1,x2,y1,y2;
    int distSq,radSumSq;
};
void calculateCircle1(struct Volume c1)
{    
    cout << "Enter radius : ";
    cin >> c1.radius;
    c1.volume = (4*3.1416*(c1.radius*c1.radius*c1.radius))/3;
    
    cout << "Volume : " << c1.volume;
}
void calculateCircle2(struct Volume c2)
{       
    cout << "Enter co-ordinates of center for 1st circle : " << endl;
    cout << "x1 : ";
    cin >> c2.x1;
    cout << "x2 : ";
    cin >> c2.x2;
    cout << "Enter co-ordinates of center for 2nd circle : " << endl;
    cout << "y1 : ";
    cin >> c2.y1;
    cout << "X2 : ";
    cin >> c2.y2;

    c2.distance = sqrt((c2.x1 - c2.x2)*(c2.x1 - c2.x2) + (c2.y1 - c2.y2)*(c2.y1 - c2.y2));

    cout << "Distance between the centers : " << c2.distance;
}
int intersectOrNot(struct Volume c3)
{
        cout << "Enter radius for the 1st circle : ";
        cin >> c3.radius1;
        cout << "Enter radius for the 2nd circle : ";
        cin >> c3.radius2; 
        
        cout << "Enter co-ordinates of center for 1st circle : " << endl;
        cout << "x1 : ";
        cin >> c3.x1;
        cout << "x2 : ";
        cin >> c3.x2;
        cout << "Enter co-ordinates of center for 2nd circle : " << endl;
        cout << "y1 : ";
        cin >> c3.y1;
        cout << "X2 : ";
        cin >> c3.y2;

        c3.distSq = (c3.x1 - c3.x2) * (c3.x1 - c3.x2) + (c3.y1 - c3.y2) * (c3.y1 - c3.y2);
        c3.radSumSq = (c3.radius1 + c3.radius2) * (c3.radius1 + c3.radius2);

        if (c3.distSq == c3.radSumSq)
        {
            return 1;
        }
        else if (c3.distSq > c3.radSumSq)
        {
            return -1;
        }
        else
        {
            return 0;
        }
}

int main()
{
    struct Volume s1,s2,s3;
    char ch;
    cout << "Enter choice : ";
    cin >> ch;
    if (ch == 'a')
    {
        calculateCircle1(s1);
    }
    else if (ch == 'b')
    {
        calculateCircle2(s2);
    }
    else if (ch == 'c')
    {
        int t = intersectOrNot(s3);
        
        if (t == 1)
        {
            cout << "Circles touch to each other and do not intersect";
        }
        else if (t < 0)
        {
            cout << "Circles do not touch to each other and do not intersect";
        }
        else 
        {
            cout << "Circles intersect to each other";
        }

    }
    
}


