#include <core/glutils/uniforms.hpp>

#include <iostream>

namespace Renderer
{
namespace Uniforms
{

    int UNIFORM_NOT_FOUND = -1;

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

    UVec3f::UVec3f(char* aName):
        UBase(aName),
        mX(0), mY(0), mZ(0),
        mUsed(false)
    {

    }

    void UVec3f::Load(float aX, float aY, float aZ)
    {
        if (!mUsed || mX != aX || mY != aX || mZ != aZ)
        {
            glUniform3f(mLocation, aX, aY, aZ);
            mX = aX;
            mY = aY;
            mZ = aZ;
            mUsed = true;
        }
    }

    void UVec3f::Load(glm::fvec3 aVector)
    {
        Load(aVector.x, aVector.y, aVector.z);
    }
}
}