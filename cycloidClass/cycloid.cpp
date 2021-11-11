#include <iostream>
#include <cmath>
#include "cycloid.h"

namespace cld
{
        Cycloid::Cycloid( double newRadius )
        {
            setRadius(abs(newRadius));
        }

        void Cycloid::setRadius( double newRadius )
        {
            radius = newRadius;
        }

        double Cycloid::getRadius() const
        {
            return radius;
        }

        // x = r*t - r*sin(t)
        // y = r - r*cos(t)
        double Cycloid::coordinateX( double const angle ) const
        {
            return radius*angle - radius*sin( angle );
        }

        double Cycloid::coordinateY( double const angle ) const
        {
            return radius - radius*cos( angle );
        }

        //Rc = 4r*sin(t/2)
        //Rc > 0
        double Cycloid::radiusOfCurvature( double const angle ) const
        {
            return 4 * radius * abs( sin( angle / 2 ) );
        }

        double Cycloid::arcLen( double angle ) const
        {
            double res = 0;
            int full_arcs_value;

            //arcLen is even function
            if( angle < 0 )
                angle *= -1;

            full_arcs_value = angle / ( 2 * M_PI );

            //len of the arc len
            res = 4*radius*( 1 - cos( angle / 2 ) ) + 8 * radius * full_arcs_value;

            return res;
        }

        double Cycloid::arcScuare( double angle ) const
        {
            double res = 0;
            int full_arcs_value;

            //arcScuare is even function
            if( angle < 0 )
                angle *= -1;

            full_arcs_value = angle / ( 2 * M_PI );

            // square of one full arc is 3*pi*R^2
            angle -= 2 * M_PI * full_arcs_value;
            res += 3 * M_PI * radius * radius * full_arcs_value;

            //len of the part of period
            res += radius * radius * ( 1.5*angle - 2*sin(angle) + 0.25*sin( 2*angle ) );

            return res;
        }

        double Cycloid::surfaceAreaRotation( double angle ) const
        {
            double res = 0;
            int full_arcs_value;

            //surface is even function
            if( angle < 0 )
                angle *= -1;

            full_arcs_value = angle / ( 2 * M_PI );

            // surface area of rotation of one full arc is 64*pi*R^2 / 3
            angle -= 2 * M_PI * full_arcs_value;
            res += (64 / 3) * M_PI * radius * radius * full_arcs_value;

            //surface of the part of period
            res += radius*radius * (4/3) * ( cos( 1.5*angle) - 9*cos( angle/2 ) + 8 );

            return res;
        }

        double Cycloid::volumeRotation( double angle ) const
        {
            double res = 0;
            int full_arcs_value;

            //volume is even function
            if( angle < 0 )
                angle *= -1;

            full_arcs_value = angle / ( 2 * M_PI );

            // volume of rotation of one full arc is 5 * pi^2 * R^3
            angle -= 2 * M_PI * full_arcs_value;
            res += 5 * M_PI*M_PI * radius*radius*radius* full_arcs_value;

            //volume of the part of period
            res += radius*radius*radius * (M_PI/12) * ( 9*sin( 2*angle) + 4*sin(angle)*sin(angle)*sin(angle) - 48*sin(angle) + 30*angle );

            return res;
        }

}
