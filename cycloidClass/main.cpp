#include <iostream>
#include <cmath>
#include "cycloid.h"

using namespace std;

const char* msgs[] =
{
    "[0] or any letter - close program",
    "[1] - get cycloid radius",
    "[2] - set cycloid radius",
    "[3] - get X coordinate depending on the angle of rotation",
    "[4] - get Y coordinate depending on the angle of rotation",
    "[5] - return the radius of curvature of the cycloid from the angle of rotation",
    "[6] - return the arc length of the cycloid from the angle of rotation",
    "[7] - return square under cycloid from the angle of rotation",
    "[8] - return surface area of rotation cycloid from the angle of rotation",
    "[9] - return volume of rotation cycloid from the angle of rotation",
};

int const msgsSize = sizeof(msgs) / sizeof(msgs[0]);

inline int dialog_getR(cld::Cycloid& cy)
{
    cout << "Cycloid radius: " << cy.getRadius() << endl;
    return 0;
}

inline int dialog_setR(cld::Cycloid& cy)
{
    double radius;
    cout << "Enter new radius value: ";
    cin >> radius;
    cy.setRadius( radius );
    cout << "Done!" << endl;

    return 0;
}

inline int dialog_getX(cld::Cycloid& cy)
{
    double angle;
    cout << "Enter angle of rotation: ";
    cin >> angle;
    cout << "X coordinate: " << cy.coordinateX( angle ) << endl;

    return 0;
}

inline int dialog_getY(cld::Cycloid& cy)
{
    double angle;
    cout << "Enter angle of rotation: ";
    cin >> angle;
    cout << "Y coordinate: " << cy.coordinateY( angle ) << endl;

    return 0;
}

inline int dialog_RofCurvature(cld::Cycloid& cy)
{
    double angle;
    cout << "Enter angle of rotation: ";
    cin >> angle;
    cout << "Radius of curvature: " << cy.radiusOfCurvature( angle ) << endl;

    return 0;
}

inline int dialog_arcLen(cld::Cycloid& cy)
{
    double angle;
    cout << "Enter angle of rotation: ";
    cin >> angle;
    cout << "Arc length: " << cy.arcLen( angle ) << endl;

    return 0;
}

inline int dialog_square(cld::Cycloid& cy)
{
    double angle;
    cout << "Enter angle of rotation: ";
    cin >> angle;
    cout << "Arc square: " << cy.arcScuare( angle ) << endl;

    return 0;
}

inline int dialog_surfaceAreaRotation(cld::Cycloid& cy)
{
    double angle;
    cout << "Enter angle of rotation: ";
    cin >> angle;
    cout << "Surface area of rotation: " << cy.surfaceAreaRotation( angle ) << endl;

    return 0;
}

inline int dialog_volumeRotation(cld::Cycloid& cy)
{
    double angle;
    cout << "Enter angle of rotation: ";
    cin >> angle;
    cout << "Volume of rotation: " << cy.volumeRotation( angle ) << endl;

    return 0;
}

int (*functions[])(cld::Cycloid&) = { nullptr, dialog_getR, dialog_setR,
                                 dialog_getX, dialog_getY, dialog_RofCurvature,
                                 dialog_arcLen, dialog_square, dialog_surfaceAreaRotation,
                                 dialog_volumeRotation
                                 };

void menu(cld::Cycloid& cy)
{
    int operation_code = 1;

    cout << "Hello! Here is a menu of cycloid's operations" << endl;

    for (int i = 0; i < msgsSize; i++ )
            puts(msgs[i]);

    while( operation_code != 0 )
    {
        cout << "Enter code: ";
        cin >> operation_code;
        if( operation_code < 0 || operation_code > msgsSize+ 1 )
        {
            cout << "Wrong code! Try again!" << endl;
            continue;
        }
        if( operation_code == 0 )
        {
            cout << "Goodbye!";
            break;
        }

        functions[operation_code](cy);
    }

}

int main()
{
    cld::Cycloid cy;
    menu(cy);
    return 0;
}
