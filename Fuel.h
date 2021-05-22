#ifndef FUEL_H
#define FUEL_H

#include <string>

class Fuel
{
    public:
        enum Type
        {
            NONE,
            LEAVES,
            FABRIC,
            WOOD,
            FLOWERPETALS,
            BIOMASS,
            COAL,
            SOLIDBIOMASS
        };

        //-----------------------------------------------------------------------------

        static std::string typeToStr(Type pType)
        {
            switch(pType)
            {
                case NONE:
                    return "None";
                case LEAVES:
                    return "Leaves";
            }
        }

        //-----------------------------------------------------------------------------

        Fuel(int id,Type pType,
             unsigned long pFuelValue) :
            mId(id),
            mType(pType),
            mFuelValue(pFuelValue)
        {}

        //-----------------------------------------------------------------------------

        virtual ~Fuel(void)
        {}

        //-----------------------------------------------------------------------------

        std::string getName(void)
        {
            return typeToStr(mType);
        }

        //-----------------------------------------------------------------------------

        void breakDown(void)
        {
            mFuelValue -= 1;
            info();
        }

        void info(void)
        {
            printf("Fuel ID: %d\n", mId);
            printf("Fuel type: %s\n", Fuel::typeToStr(mType).c_str());
            printf("Fuel value: %lu\n", mFuelValue);
        }

        int mId;
        Type mType;

        // units are in MJ
        // 1 MJ provides 1 MW of power for 1 second
        unsigned long mFuelValue;
};

class NoFuel : public Fuel
{
    public:
        NoFuel(void) :
            Fuel(0, Fuel::NONE, 0)
        {}
};

class Leaves : public Fuel
{
    public:
        Leaves(int id) :
            Fuel(id, Fuel::LEAVES, 15)
        {}
};
/*
class Fabric : public Fuel
{};

class Wood : public Fuel
{};

class FLowerPetals : public Fuel
{};

class Biomass : public Fuel
{};

class Coal : public Fuel
{};

class SolidBiofuel : public Fuel
{};
*/

#endif // FUEL_H
