#include "PowerGenerator.h"

PowerGenerator::PowerGenerator(unsigned long pPowerCapacity,
                               unsigned long pPowerConsumption,
                               unsigned long pMaximumConsumption) :
    mState(DEACTIVATED),
    mPowerCapacity(pPowerCapacity),
    mPowerConsumption(pPowerConsumption),
    mMaximumConsumption(pMaximumConsumption)
{}

//-----------------------------------------------------------------------------

PowerGenerator::~PowerGenerator(void)
{}

//-----------------------------------------------------------------------------

void PowerGenerator::update(void)
{

}

//-----------------------------------------------------------------------------

PowerGenerator::State PowerGenerator::getState(void)
{
    return mState;
}

//-----------------------------------------------------------------------------

void PowerGenerator::setState(PowerGenerator::State pState)
{
    mState = pState;
}

//-----------------------------------------------------------------------------

bool PowerGenerator::Activate(void)
{
    setState(ACTIVATED);
    return true;
}

//-----------------------------------------------------------------------------

bool PowerGenerator::Deactivate(void)
{
    setState(DEACTIVATED);
    return true;
}

//-----------------------------------------------------------------------------

unsigned long PowerGenerator::getPowerCapacity(void)
{
    return mPowerCapacity;
}

//-----------------------------------------------------------------------------

void PowerGenerator::setPowerCapacity(unsigned long pPowerCapacity)
{
    mPowerCapacity = pPowerCapacity;
}

//-----------------------------------------------------------------------------

unsigned long PowerGenerator::getPowerConsumption(void)
{
    return mPowerConsumption;
}

//-----------------------------------------------------------------------------

void PowerGenerator::setPowerConsumption(unsigned long pPowerConsumption)
{
    mPowerConsumption = pPowerConsumption;
}

//-----------------------------------------------------------------------------

unsigned long PowerGenerator::getMaximumConsumption(void)
{
    return mMaximumConsumption;
}

//-----------------------------------------------------------------------------

void PowerGenerator::setMaximumConsumption(unsigned long pMaximumConsumption)
{
    mMaximumConsumption = pMaximumConsumption;
}

//-----------------------------------------------------------------------------

void PowerGenerator::addFuel(Fuel *pFuel)
{
    // Generators can only hold 1 type of fuel so if this is different then
    // the current fuel remove all fuel.
    if (mCurrentFuelType != pFuel->mType)
    {
        removeFuel();
    }

    // Update the current fuel
    mCurrentFuelType = pFuel->mType;
    mTotalFuel.push(pFuel);
}

//-----------------------------------------------------------------------------

void PowerGenerator::consumeFuel(void)
{
    if (mTotalFuel.empty())
    {
        mCurrentFuelType = Fuel::NONE;
    }
    else
    {
        // todo need to delete?
        mTotalFuel.pop();
    }
}

//-----------------------------------------------------------------------------

void PowerGenerator::removeFuel(void)
{
    std::queue<Fuel*> empty;
    std::swap(mTotalFuel, empty);
    mCurrentFuelType = Fuel::NONE;
}

//-----------------------------------------------------------------------------

size_t PowerGenerator::getTotalFuel(void)
{
    return mTotalFuel.size();
}

//-----------------------------------------------------------------------------

Fuel::Type PowerGenerator::getCurrentFuelType(void)
{
    return mCurrentFuelType;
}

Fuel* PowerGenerator::getCurrentFuel(void)
{
    if (mTotalFuel.empty())
    {
        // todo memory leaks
        return new NoFuel();
    }
    else
    {
        return mTotalFuel.front();
    }

    return new NoFuel();
}
