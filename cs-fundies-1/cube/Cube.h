#pragma once

namespace fund {
    class Cube {
    public:  // Public members:
        double getVolume();
        double getSurfaceArea();
        void setLength(double length);

    private: // Private members:
        double length_;
    };
}
