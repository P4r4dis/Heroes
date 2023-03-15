#ifndef         __IPOTION__
# define        __IPOTION__

class           IPotion
{
    public:
        virtual ~IPotion(void);

        int     getHealthPotion(void) const;
        void    setHealthPotion(int healthPotion);

        int     getPowerPotion(void) const;
        void    setPowerPotion(int PowerPotion);

        int     getPoisonPotion(void) const;
        void    setPoisonPotion(int poisonPotion);

    protected:
    private:
        int     m_healthPotion;
        int     m_powerPotion;
        int     m_poisonPotion;

};
#endif //       !__IPOTION__