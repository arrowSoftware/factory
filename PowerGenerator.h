#ifndef POWERGENERATOR_H
#define POWERGENERATOR_H

#include "Fuel.h"

#include <queue>

class PowerGenerator
{
    public:
        PowerGenerator(unsigned long pPowerCapacity,
                       unsigned long pPowerConsumption,
                       unsigned long pMaximumConsumption);

        virtual ~PowerGenerator(void);

        virtual void update(void);

        enum State
        {
            ACTIVATED,
            DEACTIVATED,
            TRIPPED
        };

        State mState;
        virtual State getState(void);
        virtual void setState(State pState);

        virtual bool Activate(void);
        virtual bool Deactivate(void);

        // The sum of the maximum power output of all power generators on the grid.
        unsigned long mPowerCapacity;
        virtual unsigned long getPowerCapacity(void);
        virtual void setPowerCapacity(unsigned long pPowerCapacity);

        // The current power demand by all buildings on the grid. If consumption
        // exceeds production a power trip occurs.
        unsigned long mPowerConsumption;
        virtual unsigned long getPowerConsumption(void);
        virtual void setPowerConsumption(unsigned long pPowerConsumption);

        // The sum of the maximum power demand if all buildings on the grid were
        // to operate at the same time.
        unsigned long mMaximumConsumption;
        virtual unsigned long getMaximumConsumption(void);
        virtual void setMaximumConsumption(unsigned long pMaximumConsumption);

        void addFuel(Fuel *pFuel);
        void consumeFuel(void);
        void removeFuel(void);
        size_t getTotalFuel(void);
        Fuel* getCurrentFuel(void);
        Fuel::Type mCurrentFuelType;
        Fuel::Type getCurrentFuelType(void);

        std::queue<Fuel*> mTotalFuel;
};

#endif // POWERGENERATOR_H
