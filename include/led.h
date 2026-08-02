class Led {
    public:
        enum class State {
            OFF = 0,
            ON = 1
        };
        
        void init();
        void setState(State state);
        State getState();
};