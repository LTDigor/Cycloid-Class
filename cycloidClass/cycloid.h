#ifndef CYCLOID_H
#define CYCLOID_H

namespace cld
{
    class Cycloid{
    private:
        double radius;// cycloid params


    public:
        Cycloid( double newRadius = 1 );

        void setRadius( double newRadius = 2*M_PI );
        double getRadius() const;
        double coordinateX( double const angle = 2*M_PI ) const;
        double coordinateY( double const angle = 2*M_PI ) const;
        double radiusOfCurvature( double const angle = 2*M_PI ) const;
        double arcLen( double angle = 2*M_PI ) const;
        double arcScuare( double angle = 2*M_PI ) const;
        double surfaceAreaRotation( double angle = 2*M_PI ) const;
        double volumeRotation( double angle = 2*M_PI ) const;
    };
}

#endif
