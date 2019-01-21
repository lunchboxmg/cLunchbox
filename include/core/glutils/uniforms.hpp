namespace Uniform
{
    class UBase
    {
        private:

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
        private:
            
            float mValue;
            bool  mUsed;
        
        public:

            void Load(float aValue);

    };
}