/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-rayann.folleas
** File description:
** StateManager
*/

#ifndef STATEMANAGER_HPP_
#define STATEMANAGER_HPP_

class StateManager {
    public:
        StateManager();
        ~StateManager();

        void setDestroyed(const bool &state);
        void setTrigger(const bool &state);

        bool isDestroyed() const;
        bool isTrigger() const;

    protected:
        bool _trigger;

        bool _destroy;
};

#endif /* !STATEMANAGER_HPP_ */
