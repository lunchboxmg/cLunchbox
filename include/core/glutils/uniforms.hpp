#include <vendor/glad/glad.h>
#include <vendor/GLFW/glfw3.h>
#include <vendor/glm/glm.hpp>

namespace Renderer
{
namespace Uniforms
{
    class UBase
    {
        protected:

            char* mName;
            int   mLocation;

        public:

            UBase(char* aName);

            void StoreLocation(int aProgramId);

            char* GetName() { return mName; }
            int   GetLocation() { return mLocation; }

    };

    class UFloat : public UBase
    {
        protected:
            
            float mValue;
            bool  mUsed;
        
        public:

            UFloat(char* aName);

            void Load(float aValue);

    };

    class UBool : public UFloat
    {
        public:

            UBool(char* aName);

            void Load(float aValue);
    };

    class UVec3f : public UBase
    {
        private:

            float mX, mY, mZ;
            bool  mUsed;

        public:

            UVec3f(char* aName);

            void Load(float aX, float aY, float aZ);
            void Load(glm::fvec3 aVector);

    };
}
}