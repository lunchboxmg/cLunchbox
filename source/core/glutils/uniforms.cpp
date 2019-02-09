#include <core/glutils/uniforms.hpp>

#include <iostream>

namespace Renderer
{
namespace Uniforms
{
    UBase::UBase(char* aName):
        mName(aName),
        mLocation(-1)
    {

    }

    void UBase::StoreLocation(int aProgramId)
    {
        mLocation = glGetUniformLocation(aProgramId, mName);
        if (mLocation == UNIFORM_NOT_FOUND)
        {
            std::cout << "ERROR: Uniform \"" << mName << "\" not found!" << std::endl;
        }
    }

    UFloat::UFloat(char* aName):
        UBase(aName),
        mValue(0),
        mUsed(false)
    {

    }

    void UFloat::Load(float aValue)
    {
        if (!mUsed || mValue != aValue)
        {
            glUniform1f(mLocation, aValue);
            mUsed = true;
            mValue = aValue;
        }
    }

    UBool::UBool(char* aName):UFloat(aName) {}

    void UBool::Load(float aValue)
    {
        UFloat::Load( aValue <= 0 ? 0 : 1 );
    }
}
}